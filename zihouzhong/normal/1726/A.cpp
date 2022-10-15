#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    int ans = INT_MIN;
    for (int i = 1; i < n; i++) {
        ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, a[n - 1] - a[i]);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[(i + n - 1) % n] - a[i]);
    }
    cout << ans << "\n";
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