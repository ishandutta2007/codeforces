#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m, T, dfn[N], low[N], st[N], top, tim, q[N], cnt;

vector <int> e[N];

bool vis[N], tag, col[N];

vector <int> A, B;

void check_() {
    if (cnt == n || tag) {
        return;
    }

    for (int i = 1; i <= cnt; i++) {
        col[q[i]] = 1;
    }

    bool ok = 1;

    for (int i = 1; i <= cnt; i++) {
        for (int j : e[q[i]]) {
            ok = ok && col[j];
        }
    }

    if (ok) {
        tag = 1;
        A.clear();
        B.clear();

        for (int i = 1; i <= n; i++) {
            if (!col[i]) {
                B.push_back(i);
            } else {
                A.push_back(i);
            }
        }
    }

    for (int i = 1; i <= cnt; i++) {
        col[q[i]] = 0;
    }
}

void dfs_(int u) {
    vis[st[++top] = u] = 1;
    dfn[u] = low[u] = ++tim;

    for (int v : e[u]) {
        if (!dfn[v]) {
            dfs_(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        int x;
        cnt = 0;

        do {
            vis[x = st[top--]] = 0;
            q[++cnt] = x;
        } while (x != u);

        check_();
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            e[i].clear();
            dfn[i] = low[i] = vis[i] = 0;
        }

        top = tim = 0;

        for (int u, v, i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
        }

        tag = 0;

        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                dfs_(i);
            }
        }

        if (!tag) {
            puts("No");
        } else {
            puts("Yes");
            printf("%u %u\n", A.size(), B.size());

            for (int x : A) {
                printf("%d ", x);
            }

            putchar('\n');

            for (int x : B) {
                printf("%d ", x);
            }

            putchar('\n');
        }
    }
}