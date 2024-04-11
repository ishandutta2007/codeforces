#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x) {
    if (x&1) return -x;
    else return x;
}

void solve() {
    ll l,r;
    cin >> l >> r;
    ll ans=0;
    if (r-l <= 10) {
        for (ll i=l;i<=r;++i) {
            ans += f(i);
        }
    }
    else {
        while (l%2 == 0) {
            ans += f(l);
            ++l;
        }
        while (r%2 == 1) {
            ans += f(r);
            --r;
        }
        ans += (r-l+1)/2;
    }
    cout << ans << endl;
}

int main () {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}