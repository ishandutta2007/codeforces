#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void go() {
    int n, k; cin >> n >> k;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        mp[(k - x % k) % k]++;
    }
    ll ans = 0;
    for (auto p: mp) {
        if (p.first != 0) ans = max(ans, p.first + (p.second - 1) * k + 1);
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        go();
    }
}