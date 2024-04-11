#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n), s(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  std::reverse(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    s[i] = a[i];
    if (i) s[i] += s[i - 1];
  }
  std::vector<int> dp(n);
  dp[0] = a[0];
  for (int i = 1; i < n; ++i) {
    dp[i] = std::max(a[i] + s[i - 1] - dp[i - 1], dp[i - 1]);
  }
  printf("%d %d\n", s.back() - dp.back(), dp.back());
  return 0;
}