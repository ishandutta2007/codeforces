#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 2e5 + 10;

int n, m, d, id[15][15], tot, ans, c[55];

bool vis[N];

vector <pii> e[N];

bitset <55> f[55], g[15];

vector <int> p[N];

void dfs_(int u) {
    if (u > d) {
        ans++;
        return;
    }

    for (int i = 0; i < u; i++) {
        if (g[u - 1][id[u][i]] || vis[id[u][i]]) {
            continue;
        }

        c[u] = i + 1;
        g[u] = g[u - 1]|f[id[u][i]];
        dfs_(u + 1);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &d);

    for (int u, v, w, i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back(pii(w, v));
    }

    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < i; j++) {
            id[i][j] = ++tot;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!e[i].size()) {
            puts("0");
            exit(0);
        }

        sort(e[i].begin(), e[i].end());

        for (int j = 0; j < (int) e[i].size(); j++) {
            p[e[i][j].second].push_back(id[e[i].size()][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(c, 0, sizeof(c));

        for (int x : p[i]) {
            c[x]++;

            if (c[x] > 1) {
                vis[x] = 1;
            }
        }

        sort(p[i].begin(), p[i].end());
        p[i].erase(unique(p[i].begin(), p[i].end()), p[i].end());

        for (int j : p[i]) {
            for (int k : p[i]) {
                f[j][k] = 1;
            }
        }
    }

    dfs_(1);

    printf("%d\n", ans);
}