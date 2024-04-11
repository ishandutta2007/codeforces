#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int n;
void solve() {
    cin >> n;
    int64_t mod = 1;
    for (int i = 1; i + 1 < n; i++) {
        if (gcd(i, n) == 1) {
            ans.push_back(i);
            (mod *= i) %= n;
        }
    }
    assert((mod == 1) || (mod == n - 1));
    if (mod == n - 1) ans.push_back(n - 1);
    cout << ans.size() << '\n';
    for (auto&& x : ans) cout << x << ' ';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}