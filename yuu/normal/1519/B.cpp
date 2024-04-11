#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int min_cost[101][101];
bitset<10001> dp[101][101];
void solve() {
    cin >> n >> m >> k;
    if (dp[n][m][k])
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    n = 100;
    m = 100;
    dp[1][1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j].count()) {
                if (i < n) dp[i + 1][j] |= (dp[i][j] << j);
                if (j < m) dp[i][j + 1] |= (dp[i][j] << i);
            }
        }
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}