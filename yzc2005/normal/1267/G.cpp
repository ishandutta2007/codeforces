#include <bits/stdc++.h>
const int N = 105, M = 10005;
int n, x;
double dp[N][M];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> x;
  dp[0][0] = 1;
  for (int t = 1; t <= n; ++t) {
    int c;
    std::cin >> c;
    for (int i = t; i; --i) {
      for (int j = M - 1; j >= c; --j) {
        dp[i][j] += dp[i - 1][j - c] * i / (n - i + 1);
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < M; ++j) {
      ans += dp[i][j] * std::min(((double) n / i + 1) * x / 2, (double) j / i);
    }
  }
  std::cout << std::fixed << std::setprecision(10) << ans << "\n";
  return 0;
}