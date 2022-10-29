#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
  std::sort(a.rbegin(), a.rend());
  std::sort(b.rbegin(), b.rend());
  bool found = false;
  for (int i = 0; i < n && !found; ++i) {
    if (i >= m || a[i] > b[i]) found = true;
  }
  puts(found ? "YES" : "NO");
  return 0;
}