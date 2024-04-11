#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, m, d[N], fa[N], sz[N][2], id[N][2], ans;

char s[N];

int find_(int x) {
    if (x == fa[x]) {
        return x;
    }

    int y = fa[x];
    fa[x] = find_(fa[x]);
    d[x] ^= d[y];
    return fa[x];
}

int calc_(int u) {
    u = find_(u);

    if (find_(0) == u) {
        return sz[u][d[0]^1];
    }

    return min(sz[u][0], sz[u][1]);
}

void merge_(int u, int v, int w) {
    if (find_(u) == find_(v)) {
        return;
    }

    ans -= calc_(u);
    ans -= calc_(v);
    w ^= d[u]^d[v];
    u = find_(u), v = find_(v);
    fa[v] = u;
    d[v] = w;
    sz[u][w] += sz[v][0];
    sz[u][w^1] += sz[v][1];
    ans += calc_(u);
}

int main() {
    scanf("%d%d%s", &n, &m, s + 1);

    for (int k, i = 1; i <= m; i++) {
        scanf("%d", &k);

        for (int x, j = 1; j <= k; j++) {
            scanf("%d", &x);

            if (id[x][0]) {
                id[x][1] = i;
            } else {
                id[x][0] = i;
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        fa[i] = i;
        sz[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        merge_(id[i][0], id[i][1], s[i] == '0');
        printf("%d\n", ans);
    }
}