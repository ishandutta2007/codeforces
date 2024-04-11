#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, a[N][6], b[N], id[N], rk[N], c[N*5], tot, sz[N*5], cnt, lim = 500, g[N], ans = 2e9 + 1;

vector <int> p[N*5];

bitset <N> f[1005], cur;

bool cmp_(int u, int v) {
    return b[u] < b[v];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            c[++tot] = a[i][j];
        }

        scanf("%d", &b[i]);
        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp_);
    sort(c + 1, c + tot + 1);
    tot = unique(c + 1, c + tot + 1) - c - 1;

    for (int i = 1; i <= n; i++) {
        rk[id[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = lower_bound(c + 1, c + tot + 1, a[i][j]) - c;
            p[a[i][j]].push_back(rk[i]);
        }
    }

    for (int i = 1; i <= tot; i++) {
        if (p[i].size() > lim) {
            g[i] = ++cnt;
            f[cnt].set();

            for (int j : p[i]) {
                f[cnt][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cur.set();
        cur[0] = 0;

        for (int j = 0, k; j < m; j++) {
            k = a[i][j];

            if (g[k]) {
                cur &= f[g[k]];
            } else {
                for (int x : p[k]) {
                    cur[x] = 0;
                }
            }
        }

        int j = cur._Find_first();

        if (j <= n) {
            ans = min(ans, b[i] + b[id[j]]);
        }
    }

    printf("%d\n", ans <= 2e9 ? ans : -1);
}