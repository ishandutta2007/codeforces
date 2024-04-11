#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int t, n, a[N], r[N], dp[N][N]; 
void down(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      r[i] = i + a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= n; ++i) {
      dp[1][i] = 0;
    } // dp[i][j] : current at i, last rightpoint <= j
    for (int i = 2; i <= n; ++i) {
      int cost = 0;
      for (int j = i - 1; j; --j) {
        if (r[j] >= i) {
          down(dp[i][r[j]], dp[j][i - 1] + cost);
        }
        cost += r[j] >= i;
      }
      for (int j = 1; j <= n; ++j) {
        down(dp[i][j], dp[i][j - 1]);
      }
    }
    printf("%d\n", dp[n][n]);
  }
  return 0;
}