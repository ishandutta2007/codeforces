#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    int ans = -1000;

    if (n > 2) {
        ans = a[n - 1] - a[0];
    }

    for (int i = 1; i < n; ++i) {
        ans = max(ans, a[i] - a[0]);
        ans = max(ans, a[n - 1] - a[i]);
    }

    for (int i = 1; i < n; ++i) {
        ans = max(ans, a[(i + n - 1) % n] - a[i]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}