#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10, mod = 1e9 + 7;

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod)
        if (b&1) res = 1ll*res*a%mod;
    
    return res;
}

int n, q, f[N][3], fac[N], inv[N], i3 = fpow_(3, mod - 2);

int C_(int n, int k) {
    return n < k ? 0 : 1ll*fac[n]*inv[k]%mod*inv[n - k]%mod;
}

int main() {
    scanf("%d%d", &n, &q);

    fac[0] = 1;

    for (int i = 1; i <= 3*n; i++)
        fac[i] = 1ll*fac[i - 1]*i%mod;
    
    inv[3*n] = fpow_(fac[3*n], mod - 2);

    for (int i = 3*n; i; i--)
        inv[i - 1] = 1ll*inv[i]*i%mod;

    f[0][0] = f[0][1] = f[0][2] = n;

    for (int i = 1; i <= 3*n; i++) {
        f[i][0] = (1ll*C_(3*n, i + 1) - 2ll*f[i - 1][0] - f[i - 1][1])%mod*i3%mod;
        f[i][1] = (f[i][0] + f[i - 1][0])%mod;
        f[i][2] = (f[i][1] + f[i - 1][1])%mod;       
    }

    for (int x, i = 1; i <= q; i++) {
        scanf("%d", &x);
        int ans = (C_(3*n, x) + f[x][0])%mod;
        printf("%d\n", (ans%mod + mod)%mod);
    }
}