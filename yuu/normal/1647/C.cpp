#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[101];
vector<tuple<int, int, int, int>> ans;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = 'x' + s[i];
    }
    if (s[1][1] == '1') {
        cout << "-1\n";
        return;
    }
    ans.clear();
    for (int i = n; i >= 2; i--) {
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '1') ans.emplace_back(i - 1, j, i, j);
    }
    for (int i = m; i >= 2; i--)
        if (s[1][i] == '1') ans.emplace_back(1, i - 1, 1, i);
    cout << ans.size() << '\n';
    for (auto&& [a, b, c, d] : ans) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}