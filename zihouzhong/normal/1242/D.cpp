#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll F(ll n, ll k) {
    if (!n) return k * (k + 1) / 2;
    ll x = F(n / k, k), r = n % k;
    return k * (k + 1) / 2 - r + max<ll>(0, min(k, (r + 1) * k - x + 1));
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll x = (n - 1) / (k * k + 1), y = F(x, k) + (k * k + 1) * x;
    if (n == y) {
        cout << (x + 1) * (k + 1) << "\n";
    } else {
        n = (n - (n > y) - 1) % (k * k + 1);
        cout << x * k * (k + 1) + n / k * (k + 1) + n % k + 1 << "\n";
    }
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