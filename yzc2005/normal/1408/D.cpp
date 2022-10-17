#include <bits/stdc++.h>
const int N = 2005, K = 1e6 + 5;
int n, m, a[N], b[N], c[N], d[N], max[K];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &c[i], &d[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] <= c[j]) {
        max[c[j] - a[i]] = std::max(max[c[j] - a[i]], d[j] - b[i] + 1);
      }
    }
  }
  int ans = 1e9;
  for (int i = 1e6; ~i; --i) {
    max[i] = std::max(max[i], max[i + 1]);
    ans = std::min(ans, i + max[i]);
  }
  printf("%d\n", ans);
  return 0;
}