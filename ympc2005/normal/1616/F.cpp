#include <bits/stdc++.h>
using namespace std;

const int N = 305, mod = 3;

int n, m, T, tot, f[2050][N], a[N], b[N], c[N], e[N][N], cnt, id[N];

void upd_(int x, int y) {
    if (c[x] >= 0) {
        f[y][cnt + 1] = (f[y][cnt + 1] - c[x] + mod)%mod;
    } else {
        f[y][id[x]] = 1;
    }
}

void solve_() {
    tot = max(tot, cnt);

    for (int i = 1; i <= cnt; i++) {
        for (int j = i; j <= tot; j++) {
            if (f[j][i] > 0) {
                swap(f[i], f[j]);
                break;       
            }
        }

        if (!f[i][i]) {
            for (int j = 1; j < i; j++) {
                if (!f[j][j] && f[j][i]) {
                    swap(f[j], f[i]);
                    break;
                }
            }
        }

        if (!f[i][i]) {
            continue;
        }

        for (int j = 1; j <= tot; j++) {
            if (f[j][i] && j != i) {
                int d = (f[j][i] != f[i][i]) + 1;

                for (int k = i; k <= cnt + 1; k++) {
                    f[j][k] = (f[j][k] - d*f[i][k]%mod + mod)%mod;
                }
            }
        }
    }

    for (int i = cnt; i; i--) {
        if (f[i][cnt + 1] && !f[i][i]) {
            puts("-1");
            return;
        }

        if (!f[i][cnt + 1]) {
            continue;
        }

        if (f[i][i] == 2) {
            f[i][cnt + 1] = f[i][cnt + 1]*2%mod;
        }

        for (int j = i - 1; j; j--) {
            if (f[j][i]) {
                f[j][cnt + 1] = (f[j][cnt + 1] - f[i][cnt + 1]*f[j][i]%mod + mod)%mod;
            }
        }
    }

    for (int i = cnt + 1; i <= tot; i++) {
        for (int j = 1; j <= cnt; j++) {
            f[i][cnt + 1] = (f[i][cnt + 1] - f[i][j]*f[j][cnt + 1]%mod + mod)%mod;
        }

        if (f[i][cnt + 1]) {
            puts("-1");
            return;
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%d ", c[i] < 0 ? f[id[i]][cnt + 1] + 1 : c[i] + 1);
    }

    puts("");
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m), cnt = tot = 0;

        memset(e, 0, sizeof(e));
        memset(f, 0, sizeof(f));

        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            c[i]--;
            e[a[i]][b[i]] = e[b[i]][a[i]] = i;

            if (c[i] < 0) {
                id[i] = ++cnt;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (e[i][j] && e[j][k] && e[k][i]) {
                        ++tot;
                        upd_(e[i][j], tot);
                        upd_(e[j][k], tot);
                        upd_(e[k][i], tot);
                    }
                }
            }
        }

        solve_();
    }
}