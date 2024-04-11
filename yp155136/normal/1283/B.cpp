#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f_mx(ll kid, ll candy) {
    return kid * candy + (kid / 2);
}

ll f_mn(ll kid, ll candy) {
    return kid * candy;
}

int main () {
    int T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        ll ans = 0;
        for (ll i = n / k - 2; i <= n / k + 2; ++i) {
            if (i < 0) continue;
            if (f_mn(k, i) <= n) {
                ans = max(ans, min(n, f_mx(k, i)));
            }
        }
        cout << ans << endl;
    }
}