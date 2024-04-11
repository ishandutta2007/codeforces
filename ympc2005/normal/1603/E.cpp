#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n, mod, fac[N], inv[N], ans;

unordered_map <int, int> f[N];

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod) {
        if (b&1) {
            res = 1ll*res*a%mod;
        }
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &mod);

    fac[0] = 1;

    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll*fac[i - 1]*i%mod;
    }

    inv[n] = fpow_(fac[n], mod - 2);

    for (int i = n; i; i--) {
        inv[i - 1] = 1ll*inv[i]*i%mod;
    }

    for (int mn = n + 1; mn; mn--) {
        int res = 0;

        for (int i = 0; i <= n; i++) {
            f[i].clear();
        }

        f[0][n*(n + 1)] = 1;

        for (int i = n + 1; i > mn; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mx = mn*i;

                for (auto val : f[j]) {
                    int lim = min(val.first, mx);

                    for (int k = 1; j + k < n; k++) {
                        lim -= i;

                        if (lim < mn*(n - j - k)) {
                            continue;
                        }


                        f[j + k][lim] = (f[j + k][lim] + 1ll*val.second*inv[k])%mod;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto val : f[i]) {
                int lim = val.first;

                if (mn*(n - i) <= lim && (n - i) <= mn) {
                    res = (res + 1ll*val.second*inv[n - i])%mod;
                }
            }
        }

        ans = (ans + 1ll*res*fac[n]%mod)%mod;
    }

    printf("%d\n", (ans%mod + mod)%mod);
}