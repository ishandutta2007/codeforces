#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ans;
void solve() {
    cin >> n >> m;
    ans.clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            ans.push_back(max(i - 1, n - i) + max(j - 1, m - j));
        }
    sort(ans.begin(), ans.end());
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