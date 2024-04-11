#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        int x = i;
        if (x <= k) ans = min(ans, n / x);
        x = n / i;
        if (x <= k) ans = min(ans, n / x);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}