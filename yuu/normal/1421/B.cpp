#include <bits/stdc++.h>
using namespace std;
int n;
string s[201];
vector<pair<int, int>> ans;
bool try_make(char a, char b) {
    ans.clear();
    if (s[1][2] != a) ans.emplace_back(1, 2);
    if (s[2][1] != a) ans.emplace_back(2, 1);
    if (s[n - 1][n] != b) ans.emplace_back(n - 1, n);
    if (s[n][n - 1] != b) ans.emplace_back(n, n - 1);
    return ans.size() <= 2;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = '0' + s[i];
    }
    if (!try_make('0', '1')) try_make('1', '0');
    cout << ans.size() << '\n';
    for (auto&& [x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}