#include <bits/stdc++.h>
using namespace std;

const int N = 50006;
int dp[N][2][2];
int a[N];

void U(int &x, int y, int z = 0) {
  if (y == -1) return;
  if (x == -1) x = y + z;
  else x = max(x, y + z);
}

void go() {
  memset(dp, -1, sizeof(dp));
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int x; cin >> x;
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    // not select i
    U(dp[i][0][0], dp[i - 1][0][0]);
    U(dp[i][0][0], dp[i - 1][0][1]);
    U(dp[i][0][1], dp[i - 1][1][0]);
    U(dp[i][0][1], dp[i - 1][1][1]);
    // select i
    U(dp[i][1][0], dp[i - 1][0][0], 1);
    U(dp[i][1][0], dp[i - 1][0][1], 1);

    if (a[i] + a[i - 1] >= 2 * x) {
      U(dp[i][1][1], dp[i - 1][1][0], 1);
    }
    if (i > 1 && a[i] + a[i - 1] + a[i - 2] >= 3 * x && a[i] + a[i - 1] >= 2 * x) {
      U(dp[i][1][1], dp[i - 1][1][1], 1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j : {0, 1}) {
      for (int k : {0, 1}) {
        ans = max(ans, dp[i][j][k]);
      }
    }
  }
  cout << ans << endl;
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}