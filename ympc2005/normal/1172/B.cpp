#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 998244353;

int n, fac[N], d[N], ans;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    fac[0] = 1;

    for (int u, v, i = 1; i < n; i++) {
        fac[i] = 1ll*fac[i - 1]*i%mod;
        cin>>u>>v;
        d[u]++;
        d[v]++;
    }

    ans = n;

    for (int i = 1; i <= n; i++) {
        ans = 1ll*ans*fac[d[i]]%mod;
    }

    cout<<(ans%mod + mod)%mod<<'\n';
}