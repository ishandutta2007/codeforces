#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> ans;
void solve() {
    cin >> n >> k;
    ans.clear();
    for (int i = k + 1; i <= n; i++) ans.push_back(i);
    for (int j = k - 1; j >= 1; j--) {
        if (k - j > j) break;
        ans.push_back(j);
    }
    cout << ans.size() << '\n';
    for (auto&& x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}