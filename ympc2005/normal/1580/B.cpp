#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int f[N][N][N], fac[N], C[N][N], mod;

int dfs_(int n, int m, int k) {
    if (n < k) return 0;

    if (!n && !k) return 1;

    if (m == 1) return k == 1 ? fac[n] : 0;

    if (~f[n][m][k]) return f[n][m][k];

    int res = 0;

    for (int i = 0; i < n; i++)
        for (int j = max(0, k + i + 1 - n); j <= i && j <= k; j++)
            res = (res + 1ll*dfs_(i, m - 1, j)*dfs_(n - i - 1, m - 1, k - j)%mod*C[n - 1][i])%mod;
    
    return f[n][m][k] = res;
}

int main() {
    int n, m, k;
    scanf("%d%d%d%d", &n, &m, &k, &mod);

    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;

        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%mod;
    }

    fac[0] = 1;

    for (int i = 1; i <= n; i++)
        fac[i] = 1ll*fac[i - 1]*i%mod;

    memset(f, -1, sizeof(f));

    printf("%d\n", (dfs_(n, m, k)%mod + mod)%mod);
}