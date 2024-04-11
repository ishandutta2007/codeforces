#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll l, r;
    cin >> l >> r;
    auto get = [&](ll n) {
        ll t = max<ll>(0, sqrt(n) - 50);
        while ((t + 1) * (t + 1) <= n) t++;
        ll ans = t;
        t = max<ll>(0, sqrt(n) - 50);
        while ((t + 1) * (t + 2) <= n) t++;
        ans += t;
        t = max<ll>(0, sqrt(n) - 50);
        while ((t + 1) * (t + 3) <= n) t++;
        return ans + t;
    };
    cout << get(r) - get(l - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}