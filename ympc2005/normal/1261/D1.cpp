#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 998244353;

int n, m, fac[N], inv[N], a[N], cnt;

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

    for (int i = 1; i <= n; i++) {
        cin>>a[i];

        if (a[i] == a[i - 1]) {
            i--, n--, cnt++;
        }
    }

    while (n > 1 && a[n] == a[1]) {
        n--;
        cnt++;
    }

    if (n == 1) {
        cout<<0<<'\n';
        exit(0);
    }

    fac[0] = 1;

    for (int i = 1; i <= n; i++) {
        fac[i] = 1ll*fac[i - 1]*i%mod;
    }

    inv[n] = fpow_(fac[n], mod - 2);

    for (int i = n; i; i--) {
        inv[i - 1] = 1ll*inv[i]*i%mod;
    }

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        int sum = fpow_(2, i);

        if (i%2 == 0) {
            sum = (sum - C_(i, i/2))%mod;
        }

        sum = 1ll*sum*fpow_(2, mod - 2)%mod;
        ans = (ans + 1ll*sum*fpow_(m - 2, n - i)%mod*C_(n, i))%mod;
    }

    ans = 1ll*ans*fpow_(m, cnt)%mod;
    cout<<(ans%mod + mod)%mod<<'\n';
}