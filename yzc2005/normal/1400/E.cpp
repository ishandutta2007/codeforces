#include <bits/stdc++.h>
const int N = 5005;
int n, a[N];
int solve(int l, int r) {
  int pos = std::min_element(a + l, a + r + 1) - a;
  int res = a[pos];
  for (int i = l; i <= r; ++i) {
    a[i] -= res;
  }
  if (pos ^ l) {
    res += solve(l, pos - 1);
  }
  if (pos ^ r) {
    res += solve(pos + 1, r);
  }
  return std::min(r - l + 1, res);
}
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::cout << solve(1, n);
  return 0;
}