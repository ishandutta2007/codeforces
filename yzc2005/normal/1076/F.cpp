#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, k, dp[N][2], x[N], y[N];
inline void down(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &y[i]);
  }
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i][1] = k + 1; // non-empty
    if (dp[i - 1][0] != k + 1) {
      int sx = dp[i - 1][0];
      int xx = x[i] - (k - sx), yy = y[i]; // x/x)yxy...y(x
      if (1ll * x[i] * k >= yy) { // in case y too much
        if (1ll * (yy - 1) * k >= xx) { // in case x too much
          dp[i][0] = 1;
        } else {
          down(dp[i][0], xx - 1ll * (yy - 1) * k);
        }
      }
      if (1ll * (yy - 1) * k >= xx) { // x/x)yxy...x(y
        if (1ll * x[i] * k >= yy) { 
          dp[i][1] = 1;
        } else {
          down(dp[i][1], yy - 1ll * x[i] * k);
        }
      }
    } 
    if (dp[i - 1][1] != k + 1) {
      int sy = dp[i - 1][1];
      int xx = x[i], yy = y[i] - (k - sy);
      if (1ll * y[i] * k >= xx) {
        if (1ll * (xx - 1) * k >= yy) {
          dp[i][1] = 1;
        } else {
          down(dp[i][1], yy - 1ll * (xx - 1) * k);
        }
      }
      if (1ll * (xx - 1) * k >= yy) {
        if (1ll * y[i] * k >= xx) {
          dp[i][0] = 1;
        } else {
          down(dp[i][0], xx - 1ll * y[i] * k);
        }
      }
    }
//    printf("%d %d\n", dp[i][0], dp[i][1]);
  }
  if (dp[n][0] > k && dp[n][1] > k) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}