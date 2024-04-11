#include <bits/stdc++.h>
const int P = 1e9 + 7;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> b(n + 1); 
    for (int i = 1; i <= n; ++i) {
      std::cin >> b[i];
    }
    std::map<long long, int> cnt;
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    cnt[0] = 1;
    long long d = 0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1] * 2 % P - cnt[d];  
      if (dp[i] < 0) {
        dp[i] += P;
      }
      cnt[d] += (dp[i] - dp[i - 1] + P) % P;
      if (cnt[d] > P) {
        cnt[d] -= P;
      }
      d += b[i];
    }
    std::cout << dp[n] << std::endl;
  }
  return 0;
}