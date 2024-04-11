#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll ppow(ll a,ll n) {
    ll ret=1,now=a;
    while (n) {
        if (n&1) {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        n>>=1;
    }
    return ret;
}

const int N = 1000006;
ll f[N],revf[N];

ll C(int n,int m) {
    return (f[n] * revf[m]%mod * revf[n-m])%mod;
}

int main () {
    f[0] = revf[0] = 1;
    for (int i=1;i<N;++i) {
        f[i] = f[i-1] * i;
        f[i] %= mod;
        revf[i] = ppow(f[i],mod-2);
    }
    int n;
    cin >> n;
    ll ans = f[n];
    for (int i=2;i<n;++i) {
        ans += (f[i]-1 + mod) * f[(n-i)] % mod * C(n,i) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}