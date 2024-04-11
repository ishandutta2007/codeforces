#include <bits/stdc++.h>
const int N = 1e6 + 5;
int n, a[N];
long long dp[N][2]; // 0 : ascending; 1 : descending
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (i == 1) continue;
    int delta = abs(a[i] - a[i - 1]); 
    dp[i][0] = dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]);
    if (a[i] > a[i - 1]) dp[i][0] = std::max(dp[i][0], dp[i - 1][0] + delta);
    else dp[i][1] = std::max(dp[i][1], dp[i - 1][1] + delta);
  }
  printf("%lld\n", std::max(dp[n][0], dp[n][1]));
  return 0;
}