#include <bits/stdc++.h>
using namespace std;

const int N = 206;
int dp[N][N][N];

void U(int &x, int v) {
    if (x == -1) {
        x = v;
    }
    else {
        x = max(x, v);
    }
}

int main () {
    memset(dp, -1, sizeof(dp));
    int n, kk; cin >> n >> kk;
    string s, t; cin >> s >> t;
    s = " " + s;
    // dp[i][j][k]: first i, j changes, before  i k t[0]s
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= kk; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (i == 1 && j == 0 && k == 0) {
                    // do something
                    dp[i][j][k] = 0;
                    // 1: not change
                    U(dp[i + 1][j][ k + (s[i] == t[0]) ], dp[i][j][k]);
                    // 2: change to t[0]
                    U(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
                    continue;
                }
                else if (i == 1) {
                    continue;
                }
                if (dp[i][j][k] == -1) continue;
                // 1: not change
                U(dp[i + 1][j][ k + (s[i] == t[0]) ], dp[i][j][k] + (s[i] == t[1]) * k);
                // 2: change to t[0]
                U(dp[i + 1][j + 1][k + 1], dp[i][j][k] + (t[0] == t[1]) * k);
                // 3 : change to t[1]
                U(dp[i + 1][j + 1][k + (t[0] == t[1])], dp[i][j][k] + k);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= kk; ++j) {
        for (int k = 0; k <= n; ++k) {
            ans = max(ans, dp[n + 1][j][k]);
        }
    }
    cout << ans << endl;
}