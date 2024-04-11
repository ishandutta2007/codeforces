#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m, f[N][N], len, g[N][N];

char s[N][N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }

    f[1][1] = s[1][1] != 'a';
    len = f[1][1] <= m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                continue;
            }

            f[i][j] = 1e9;

            if (i > 1) {
                f[i][j] = min(f[i][j], f[i - 1][j]);
            }

            if (j > 1) {
                f[i][j] = min(f[i][j], f[i][j - 1]);
            }

            f[i][j] += s[i][j] > 'a';
            
            if (f[i][j] <= m) {
                len = max(len, i + j - 1);
            }
        }
    }

    for (int i = 1; i <= len; i++) {
        putchar('a');
    }

    if (!len) {
        putchar(s[1][1]);
        len = 2, g[1][1] = 1;
    } else {
        len++;

        for (int i = 1; i <= n; i++) {
            if (i < len && len - i <= n && f[i][len - i] <= m) {
                g[i][len - i] = 1;
            }
        }
    }

    for (int i = len; i < n + n; i++) {
        int mn = 26;

        for (int j = 1; j <= n; j++) {
            if (j < i && i - j <= n && g[j][i - j]) {
                if (j < n) {
                    mn = min(mn, s[j + 1][i - j] - 'a');
                }

                if (i - j < n) {
                    mn = min(mn, s[j][i - j + 1] - 'a');
                }
            }
        }

        putchar('a' + mn);

        for (int j = 1; j <= n; j++) {
            if (j < i && i - j <= n && g[j][i - j]) {
                if (j < n && (int) s[j + 1][i - j] == 'a' + mn) {
                    g[j + 1][i - j] = 1;
                }

                if (i - j < n && (int) s[j][i - j + 1] == 'a' + mn) {
                    g[j][i - j + 1] = 1;
                }
            }
        }
    }

    putchar('\n');
}