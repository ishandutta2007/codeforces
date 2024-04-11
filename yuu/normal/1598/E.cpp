#include <bits/stdc++.h>
using namespace std;
int n, m, q;
bool locked[1001][1001];
int64_t ans;
int64_t get(int x, int y) {
    y -= x - 1;
    x = 1;
    int dp[3][3];
    int new_dp[3][3];
    bool l[3];
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 3; k++) dp[j][k] = 0;
    int64_t res = 0;
    while ((x <= n) && (y <= m + 1)) {
        if (y > 1)
            l[0] = locked[x][y - 1];
        else
            l[0] = 1;
        if ((y >= 1) && (y <= m))
            l[1] = locked[x][y];
        else
            l[1] = 1;
        if ((y >= 0) && (y + 1 <= m))
            l[2] = locked[x][y + 1];
        else
            l[2] = 1;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) new_dp[j][k] = 0;
        for (int j = 0; j < 3; j++)
            if (!l[j]) {
                new_dp[j][0] = 1;
                if (j) new_dp[j][1] = new_dp[j - 1][0] + new_dp[j - 1][2];
                if (j < 2) new_dp[j][2] = dp[j + 1][0] + dp[j + 1][1];
            }
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                res += new_dp[j][k];
                dp[j][k] = new_dp[j][k];
            }
        x++;
        y++;
    }
    return res;
}
void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            auto get_diag_length = [&n, &m](int x, int y) { return min(n - x + 1, m - y + 1); };
            ans += get_diag_length(i + 1, j);
            ans += get_diag_length(i, j + 1);
            ans += get_diag_length(i + 1, j + 1) * 2;
            ans += 1;
        }
    }
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        ans -= get(x, y);
        locked[x][y] = !locked[x][y];
        ans += get(x, y);
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}