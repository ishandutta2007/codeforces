#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, m, T, nex[N], f[N][2], a[N], pl, pr, gl[4], gr[4];

vector <int> e[N];

void solve_() {
    if (pl > n) {
        printf("%lld\n", 1ll*n*(n - 1)/2);
        return;
    }

    f[pl + 1][0] = 1;
    f[pl + 1][1] = 2;

    for (int i = pl + 2; i <= n + 1; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j : e[i]) {
                if (nex[j + 1] >= i - 1) {
                    f[i][k] |= f[j + 1][k^1];
                }
            }
        }
    }

    for (int i = pl + 1; i; i--) {
        for (int k = 0; k < 2; k++) {
            for (int j : e[i]) {
                if (nex[j + 1] >= i - 1) {
                    f[j + 1][k^1] |= f[i][k];
                }
            }
        }
    }

    if (!f[1][0] || !f[n + 1][0]) {
        puts("0");
        return;
    }

    memset(gl, 0, sizeof(gl));
    memset(gr, 0, sizeof(gr));

    for (int i = 1; i <= pl + 1; i++) {
        gl[f[i][0]]++;
    }

    for (int i = pr; i <= n + 1; i++) {
        gr[f[i][0]]++;
    }

    ll ans = 0;

    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if ((i&j)) {
                ans += 1ll*gl[i]*gr[j];
            }
        }
    }

    for (int i = pl; i <= pl + 1; i++) {
        for (int j = pr; j <= pr + 1; j++) {
            if (i + 1 >= j && (f[i][0]&f[j][0])) {
                ans--;
            }
        }
    }

    printf("%lld\n", ans);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i <= n + 1; i++) {
            f[i][0] = f[i][1] = a[i] = 0;
            e[i].clear();
        }

        for (int i = 1; i <= n + 1; i++) {
            if (i > 1) {
                e[i].push_back(0);
            }

            if (i <= n) {
                e[n + 1].push_back(i);
            }
        }

        a[0] = a[n] = 1;

        for (int u, v, i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);

            if (u + 1 == v) {
                a[u] = 1;
            } else {
                e[v].push_back(u);
            }
        }

        pl = 0;

        while (pl <= n && a[pl]) {
            pl++;
        }

        pr = n + 1;

        while (pr && a[pr - 1]) {
            pr--;
        }

        nex[n + 1] = n + 1;

        for (int i = n; i >= 0; i--) {
            nex[i] = a[i] ? nex[i + 1] : i;
        }

        solve_();
    } 
}