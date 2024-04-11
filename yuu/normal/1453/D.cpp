#include <bits/stdc++.h>
using namespace std;
int64_t k;
void solve() {
    cin >> k;
    if (k % 2) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    int64_t weight = k + 1;
    while (k) {
        if (weight > k) weight = 2;
        ans.push_back(weight == 2);
        k -= weight;
        weight *= 2;
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