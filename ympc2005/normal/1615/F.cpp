#include <bits/stdc++.h>
using namespace std;

const int N = 2005, mod = 1e9 + 7;

int T, n, f[2][N<<1], g[2][N<<1];

char s[N], t[N];

void solve_() {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    
    int cur = 0, pre = 1;
    f[cur][n] = 1;

    for (int i = 1; i <= n; i++) {
        cur ^= 1, pre ^= 1;
        memset(f[cur], 0, sizeof(f[cur]));
        memset(g[cur], 0, sizeof(g[cur]));

        for (int j = -i; j <= i; j++) {
            for (int x = 0; x <= 1; x++) {
                if (s[i] != '?' && ((s[i] - '0')^(i&1)) != x) {
                    continue;
                }

                for (int y = 0; y <= 1; y++) {
                    if (t[i] != '?' && ((t[i] - '0')^(i&1)) != y) {
                        continue;
                    }

                    int k = j + n + x - y;
                    f[cur][k] = (f[cur][k] + f[pre][j + n])%mod;
                    g[cur][k] = (g[cur][k] + 1ll*f[pre][j + n]*abs(k - n) + g[pre][j + n])%mod;
                }
            }
        }
    }

    printf("%d\n", (g[cur][n]%mod + mod)%mod);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s%s", &n, s + 1, t + 1);
        solve_();
    }
}