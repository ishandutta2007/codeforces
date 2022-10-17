#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, a[N], f[N][N], g[N][N], h[N][N];

inline void up(int &x, int y) {
    x < y ? x = y : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(f, 0xcf, sizeof f);
    f[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        memset(g, 0xcf, sizeof g);
        memset(h, 0xcf, sizeof h);

        for (int x = 0; x <= n; ++x) {
            for (int y = 0; y < i; ++y) {
                if (i > 1) {
                    if (x == 0) {
                        up(g[i - 1][y + 1], f[x][y] + a[i - 1]);
                    } else {
                        up(g[x][y + 1], f[x][y] + a[x]);
                    }
                } // the same as the last one
                if (x == 0 || x < i) {
                    up(g[0][y], f[x][y] + a[i]);
                } // itself
                int pos = max(i + 1, x + 1);
                int cnt = y + pos - i;
                if (cnt <= i) {
                    up(h[pos][cnt], f[x][y]);
                }
                // for (int z = max(i + 1, x + 1); z <= n; ++z) {
                //     if (y + z - i <= i) {
                //         up(g[z][y + z - i], f[x][y] + a[z]);
                //     }
                // } // from the numbers after
            }
        }

        for (int x = i + 1; x <= n; ++x) {
            for (int y = 0; y <= i; ++y) {
                if (x > 0 && y > 0) {
                    up(h[x][y], h[x - 1][y - 1]);
                }
                up(g[x][y], h[x][y] + a[x]);
            }
        }
        
        memcpy(f, g, sizeof f);
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << "\n";

    return 0;
}