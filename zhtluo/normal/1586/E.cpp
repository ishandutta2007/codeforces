#include <bits/stdc++.h>

int N, M;
std::vector<int> edge[310000];
int f[310000], d[310000], dp[310000];
int anc[310000][20];
int x[310000], y[310000];
int res = 0;

void build(int u) {
    for (auto &e: edge[u]) {
        if (f[e] == 0) {
            f[e] = u;
            d[e] = d[u] + 1;
            build(e);
        }
    }
}

int prop(int u) {
    int sum = 0;
    for (auto &e: edge[u]) {
        if (f[e] == u) sum += prop(e);
    }
    sum += dp[u];
    dp[u] = sum;
    return dp[u];
}

int calc(int u) {
    int sum = 0;
    for (auto &e: edge[u]) {
        if (f[e] == u) sum += calc(e);
    }
    res -= sum / 2;
    if (u == 1) return 0;
    // printf("%d %d %d\n", u, f[u], dp[u]);
    if (dp[u] % 2 && sum % 2 == 0) {
        ++res; return 1;
    }
    return dp[u] % 2;
}

int lca(int u, int v) {
    if (d[u] < d[v]) std::swap(u, v);
    for (int k = 19; k >= 0; --k) {
        if (d[u] - d[v] >= 1 << k) {
            u = anc[u][k];
        }   
    }
    if (u == v) return u;
    for (int k = 19; k >= 0; --k) {
        if (anc[u][k] != anc[v][k]) {
            u = anc[u][k]; v = anc[v][k];
        }   
    }
    return f[u];
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    f[1] = 1; build(1);
    for (int i = 1; i <= N; ++i) anc[i][0] = f[i];
    for (int k = 1; k < 20; ++k)
        for (int i = 1; i <= N; ++i) {
            anc[i][k] = anc[anc[i][k - 1]][k - 1];
        }
    int Q; scanf("%d", &Q);
    for (int q = 0; q < Q; ++q) {
        int u, v;
        scanf("%d%d", &x[q], &y[q]);
        ++dp[x[q]]; ++dp[y[q]];
        dp[lca(x[q], y[q])] -= 2;
    }
    prop(1);
    int final = calc(1);
    if (res) {
        puts("NO");
        printf("%d\n", res);
    } else {
        puts("YES");
        for (int q = 0; q < Q; ++q) {
            int cf = lca(x[q], y[q]);
            int cur = x[q];
            static int sth1[310000];
            int size1 = 0;
            while (cur != cf) {
                sth1[size1++] = cur;
                cur = f[cur];
            }
            static int sth[310000];
            int size = 0;
            cur = y[q];
            while (cur != cf) {
                sth[size++] = cur;
                cur = f[cur];
            }
            printf("%d\n", size1 + 1 + size);
            for (int i = 0; i < size1; ++i) {
                printf("%d ", sth1[i]);
            }
            printf("%d", cf);
            for (int i = size - 1; i >= 0; --i) {
                printf(" %d", sth[i]);
            }
            puts("");
        }
    }
}