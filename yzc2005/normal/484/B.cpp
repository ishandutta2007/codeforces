#include <bits/stdc++.h>
const int N = 2e5 + 5;
int n, a[N], ans;
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::sort(a + 1, a + n + 1), n = std::unique(a + 1, a + n + 1) - a - 1;
  for (int i = n; i; --i) {
    if (ans > a[i]) continue;
    for (int x = 2 * a[i]; x - a[i] <= a[n]; x += a[i]) {
      int val = a[std::lower_bound(a + 1, a + n + 1, x) - a - 1];
      ans = std::max(ans, val % a[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}