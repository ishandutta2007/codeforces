#include <bits/stdc++.h>
using namespace std;

const int N = 2005, mod = 1e9 + 7;

int n, m;

int c1[N][N], c2[N][N], g1[N][N], g2[N][N];

int f1[N][N], f2[N][N], p1[N][N], p2[N][N];

char s[N][N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }

    memset(p1, 0x3f, sizeof(p1));
    memset(p2, 0x3f, sizeof(p2));

    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            c1[i][j] = c1[i][j + 1];
            c2[i][j] = c2[i + 1][j];

            if (s[i][j] == 'R') {
                c1[i][j]++;
                c2[i][j]++;
            }

            p1[i][m - c1[i][j + 1]] = j;
            p2[n - c2[i + 1][j]][j] = i;
        }
    }

    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            p1[i][j] = min(p1[i][j], p1[i][j + 1]);
            p2[i][j] = min(p2[i][j], p2[i + 1][j]);
        }
    }

    f1[1][1] = f2[1][1] = g1[1][1] = g2[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                continue;
            }

            f1[i][j] = (g2[i - 1][j] - g2[p2[i][j] - 1][j])%mod;
            f2[i][j] = (g1[i][j - 1] - g1[i][p1[i][j] - 1])%mod;
            g1[i][j] = (g1[i][j - 1] + f1[i][j])%mod;
            g2[i][j] = (g2[i - 1][j] + f2[i][j])%mod;
        }
    }

    if (n == 1 && m == 1) {
        puts("1");
    } else {
        int ans = (f1[n][m] + f2[n][m])%mod;
        printf("%d\n", (ans%mod + mod)%mod);
    }
}