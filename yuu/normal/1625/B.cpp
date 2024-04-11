#include <bits/stdc++.h>
using namespace std;
int n;
map<int, vector<int>> pos;
void solve() {
    cin >> n;
    pos.clear();
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        pos[a].push_back(i);
    }
    int ans = -1;
    for (auto&& [v, p]: pos) {
        for (int i = 1; i < p.size(); i++) {
            ans = max(ans, p[i - 1] + n - p[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}