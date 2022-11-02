#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 998244353;

int n, T, a[N], b[N], c[N], cnt, d, m, fac[N], inv[N], f[N], g[N];

int gcd_(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod) {
        if (b&1) {
            res = 1ll*res*a%mod;
        }
    }

    return res;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), cnt = m = 0;
        fac[0] = 1;

        for (int i = 1; i <= n; i++) {
            fac[i] = 1ll*fac[i - 1]*i%mod;
            a[i] = f[i] = g[i] = 0;

            if (n%i == 0) {
                c[++cnt] = i;
            }
        }

        inv[n] = fpow_(fac[n], mod - 2);

        for (int i = n; i; i--) {
            inv[i - 1] = 1ll*inv[i]*i%mod;
        }

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[x]++;
        }

        int d = 0;

        for (int i = 1; i <= n; i++) {
            if (a[i]) {
                ++m;
                b[m] = a[i];
                d = gcd_(d, a[i]);
            }
        }

        if (m == 1) {
            puts("1");
            continue;
        }

        for (int i = 1; i <= cnt; i++) {
            int x = n/c[i], val = 1, sum = 0;

            if (d%x) {
                continue;
            }

            for (int j = 1; j <= m; j++) {
                int y = b[j]/x;
                val = 1ll*val*inv[y]%mod;
                sum = (sum + 1ll*fac[y]*inv[y - 1])%mod;
            }

            f[i] = 1ll*val*fac[c[i]]%mod;

            for (int j = 1; j <= m; j++) {
                int y = b[j]/x, z = 1ll*fac[y]*inv[y - 1]%mod;
                g[i] = (g[i] + 1ll*val*z%mod*(sum - z))%mod;
            }

            g[i] = 1ll*g[i]*fac[c[i] - 2]%mod*n%mod;
        }

        int s1 = 0, s2 = 0;   

        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j < i; j++) {
                if (c[i]%c[j] == 0) {
                    f[i] = (f[i] - f[j])%mod;
                    g[i] = (g[i] - g[j])%mod;
                }
            }
            
            int k = 1ll*inv[c[i]]*fac[c[i] - 1]%mod;
            s1 = (s1 + 1ll*g[i]*k)%mod;
            s2 = (s2 + 1ll*f[i]*k)%mod;
        }

        int ans = 1ll*s1*fpow_(s2, mod - 2)%mod;
        printf("%d\n", (ans%mod + mod)%mod);
    }
}