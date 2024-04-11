#include <bits/stdc++.h>
using namespace std;

const int N = 106;

int a[N];
int dp[N][N][N][2];

void U(int &x, int v, int del) {
    if (v == -1) return;
    if (x == -1) x = v + del;
    else x = min(x, v + del);
}

int main () {
    memset(a, -1, sizeof(a));
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (x != 0) {
            a[i] = x % 2;
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            //j: number of odd
            int k = i - j;
            //k: number of even
            //cout << "a_i = " << a[i] << endl;
            if (a[i] != 0 && j > 0) {
                //select odd
                U(dp[i][j][k][1], dp[i - 1][j - 1][k][0], 1);
                U(dp[i][j][k][1], dp[i - 1][j - 1][k][1], 0);
            }
            if (a[i] != 1 && k > 0) {
                //select even
                U(dp[i][j][k][0], dp[i - 1][j][k - 1][0], 0);
                U(dp[i][j][k][0], dp[i - 1][j][k - 1][1], 1);
            }
        }
        //cout << dp[i][i][0][1] << endl;
    }
    int ans = -1;
    U(ans, dp[n][n - n / 2][n / 2][0], 0);
    U(ans, dp[n][n - n / 2][n / 2][1], 0);
    cout << ans << endl;
}