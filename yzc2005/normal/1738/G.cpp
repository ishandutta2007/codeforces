#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n), ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        ans[i].assign(n, '0');
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0 && j > 0) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            if (s[i][j] == '0') {
                ++dp[i][j];
            }
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            if (dp[i][j] >= k) {
                cout << "NO\n";
                return;
            }
        }
    }
    vector<vector<pair<int, int>>> pos(k);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '0') {
                pos[dp[i][j]].emplace_back(i, j);
            }
        }
    }
    for (int i = k - 1, j = 0; i > 0; --i, ++j) {
        auto vec = pos[i];
        vec.emplace_back(0, n - 1 - j);
        vector<int> lim(n, n);
        for (auto [x, y] : vec) {
            lim[y] = min(lim[y], x);
        }
        int x = n - 1 - j, y = 0;
        ans[x][y] = '1';
        while (make_pair(x, y) != vec.back()) {
            if (x > lim[y]) {
                --x;
            } else {
                ++y;
            }
            ans[x][y] = '1';
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}