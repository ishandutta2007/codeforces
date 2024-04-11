#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 250006;

ll f[N];

int main () {
    ll n, mod; cin >> n >> mod;
    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += f[i] * (n - i + 1) % mod * (n - i + 1) % mod * f[n - i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
}