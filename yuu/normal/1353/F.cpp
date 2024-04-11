#include <bits/stdc++.h>
using namespace std;
int n, m;
int64_t a[101][101];
int64_t dp[101][101];
int64_t start;

int64_t do_dp() {
    if (a[1][1] < (start + 1 + 1)) return 1e18;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) dp[i][j] = 1e18 + 1;

    dp[1][1] = a[1][1] - (start + 1 + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1 + (i == 1); j <= m; j++) {
            if (a[i][j] < start + i + j) continue;
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j] - (start + i + j);
        }
    return dp[n][m];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    int64_t ans = 1e18;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            start = a[i][j] - i - j;
            ans = min(ans, do_dp());
        }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}