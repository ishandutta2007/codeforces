#include <bits/stdc++.h>
const int N = 5e5 + 5;
int n, a[N], dp[N], l[N], r[N], c[N];
std::vector<int> mdf[N];
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i], ++c[a[i]], r[a[i]] = i;
  for (int i = n; i; --i) l[a[i]] = i;
  for (int i = 1; i <= n; ++i) if (l[i]) mdf[r[i]].emplace_back(i);
  for (int i = 1; i <= n; ++i) {
    for (auto x : mdf[i]) dp[i] = std::max(dp[i], dp[l[x] - 1] + c[x]);
    dp[i] = std::max(dp[i], dp[i - 1]);
  }
  int ans = dp[n]; memset(c, 0, sizeof(c));
  for (int i = n; i; --i) ans = std::max(ans, dp[i - 1] + ++c[a[i]]); 
  std::cout << n - ans << std::endl;
  return 0;
}