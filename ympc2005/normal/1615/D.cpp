#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

int n, m, T, fa[N], a[N], b[N], c[N], g[N], d[N];

bool ok;

vector <int> e[N];

int find_(int x) {
    return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

void dfs_(int u) {
    for (int v : e[u]) {
        if (!g[v]) {
            g[v] = 3 - g[u];
            dfs_(v);
        } else if (g[v] == g[u]) {
            ok = 1;
            return;
        }
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            g[i] = 0, fa[i] = i;
            e[i].clear();
        }

        for (int i = 1; i < n + m; i++) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);

            if (c[i] >= 0) {
                d[i] = 0;

                for (int j = 0; j < 30; j++) {
                    if (c[i]&(1<<j)) {
                        d[i] ^= 1;
                    }
                }
            }
        }

        for (int i = 1; i < n + m; i++) {
            if (c[i] >= 0 && !d[i]) {
                fa[find_(a[i])] = find_(b[i]);
            }
        }

        ok = 0;

        for (int i = 1; i < n + m; i++) {
            if (c[i] >= 0 && d[i]) {
                if (find_(a[i]) == find_(b[i])) {
                    ok = 1;
                } else {
                    e[find_(a[i])].push_back(find_(b[i]));
                    e[find_(b[i])].push_back(find_(a[i]));
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (fa[i] == i && !g[i]) {
                g[i] = 1;
                dfs_(i);
            }
        }

        if (ok) {
            puts("NO");
            continue;
        }

        puts("YES");

        for (int i = 1; i < n; i++) {
            if (c[i] == -1) {
                c[i] = g[find_(a[i])] != g[find_(b[i])];
            }

            printf("%d %d %d\n", a[i], b[i], c[i]);
        }
    }
}