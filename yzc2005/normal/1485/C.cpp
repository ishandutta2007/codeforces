#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x, y;
    std::cin >> x >> y;
    long long ans = 0;
    for (int k = 1; k * k <= x; ++k) {
      ans += std::max(0, std::min(y, x / k - 1) - k);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}