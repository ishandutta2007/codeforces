#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i] + a[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
        int r = cnt[n] - cnt[i];
        ans = min(ans, cnt[i] + max(0, n - i - r - cnt[i]));
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