#define __ __attribute__ ((optimize ("-O3"))) 
#define _ __ __inline __attribute__ ((__gnu_inline__, __always_inline__, __artificial__)) 
#include <bits/stdc++.h>
    
int N, M, K, MOD;
int dp[200][200][200];
int C[200][200];
int fac[200];
    
__ _ int calc(int n, int m, int k) {
    if (n == 0) {
        if (k == 0) return dp[n][m][k] = 1 % MOD;
        return dp[n][m][k] = 0;
    }
    if (n == 1) {
        if (m == 1 && k == 1) return dp[n][m][k] = 1 % MOD;
        if (m > 1 && k == 0) return dp[n][m][k] = 1 % MOD;
        return dp[n][m][k] = 0;
    }
    if (m == 1) {
        if (k == 1) {
            return dp[n][m][k] = fac[n];
        }
        return dp[n][m][k] = 0;
    }
    if (m > n) {
        if (k == 0) {
            return dp[n][m][k] = fac[n];
        }
        return dp[n][m][k] = 0;
    }
    int ans = 0;
    for (int ln = 0; ln + 1 <= n; ++ln) {
        if (m - 1 > ln) {
            int lk = 0;
            int rn = n - ln - 1, rk = k - lk;
            ans += 1ll * dp[ln][m - 1][lk] * dp[rn][m - 1][rk] % MOD * C[n - 1][ln] % MOD;
            if (ans >= MOD) ans -= MOD;
            continue;
        }
        if (m - 1 > n - ln - 1 && k <= ln) {
            int lk = k;
            int rn = n - ln - 1, rk = k - lk;
            ans += 1ll * dp[ln][m - 1][lk] * dp[rn][m - 1][rk] % MOD * C[n - 1][ln] % MOD;
            if (ans >= MOD) ans -= MOD;
            continue;
        }
        for (int lk = std::max(0, k - (n - ln - 1)); lk <= std::min(ln, k); ++lk) {
            int rn = n - ln - 1, rk = k - lk;
            ans += 1ll * dp[ln][m - 1][lk] * dp[rn][m - 1][rk] % MOD * C[n - 1][ln] % MOD;
            if (ans >= MOD) ans -= MOD;
        }
    }
    return dp[n][m][k] = ans;
}
    
__ int main() {
    scanf("%d%d%d%d", &N, &M, &K, &MOD);
    for (int i = 1; i <= N; ++i) {
        C[i][0] = C[i][i] = 1 % MOD;
        for (int j = 1; j <= i - 1; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
    for (int i = 0; i <= N; ++i) for (int j = 0; j <= std::min(N, M); ++j) for (int k = 0; k <= std::min(i, K); ++k) {
        calc(i, j, k);
    }
    printf ("%d\n", dp[N][M][K]);
}