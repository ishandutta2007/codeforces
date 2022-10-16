#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
vector<tuple<int, int, int>> ans;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum ^= a[i];
        if (sum) {
            cout << "NO\n";
            return;
        }
        n--;
    }
    if (n % 2) {
        ans.emplace_back(1, 2, 3);
        for (int i = 3; i < n; i += 2) ans.emplace_back(i, i + 1, i + 2);
        for (int i = 1; i < n; i += 2) ans.emplace_back(i, i + 1, n);
    }
    assert(ans.size() <= n);
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto&& [x, y, z] : ans) cout << x << ' ' << y << ' ' << z << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}