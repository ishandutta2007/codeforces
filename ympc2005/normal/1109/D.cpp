#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

int n, m, fac[N], inv[N], ans;

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod) {
        if (b&1) {
            res = 1ll*res*a%mod;
        }
    }

    return res;
}

int C_(int n, int k) {
    return n < k ? 0 : 1ll*fac[n]*inv[k]%mod*inv[n - k]%mod;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    fac[0] = 1;

    for (int i = 1; i <= max(n, m); i++) {
        fac[i] = 1ll*fac[i - 1]*i%mod;
    }

    inv[max(n, m)] = fpow_(fac[max(n, m)], mod - 2);

    for (int i = max(n, m); i; i--) {
        inv[i - 1] = 1ll*inv[i]*i%mod;
    }

    for (int i = 0; i <= n - 2; i++) {
        ans = (ans + 1ll*C_(n - 2, i)*C_(m - 1, i)%mod*(i + 2)%mod*fpow_(n, n - i - 3 + mod - 1)%mod*fpow_(m, n - 1 - i - 1)%mod*fac[i])%mod;
    }

    cout<<(ans%mod + mod)%mod<<'\n';
}