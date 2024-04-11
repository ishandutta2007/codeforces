#include <bits/stdc++.h>
using namespace std;

const int N = 1005, mod = 998244353;

int n, m, a[N], f[N][N], g[N], ans;

void solve_(int v) {
    memset(g, 0, sizeof(g));

    for (int i = 1, p = 1; i <= n; i++) {
        while (a[p] + v <= a[i]) {
            for (int j = 1; j <= m; j++) {
                g[j] = (g[j] + f[p][j])%mod;
            }

            p++;
        }

        for (int j = 1; j <= m; j++) {
            f[i][j] = g[j - 1];
        }

        f[i][1] = (f[i][1] + 1)%mod;
        ans = (ans + f[i][m])%mod;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; (m - 1)*i <= a[n]; i++) {
        solve_(i);
    }

    printf("%d\n", (ans%mod + mod)%mod);
}