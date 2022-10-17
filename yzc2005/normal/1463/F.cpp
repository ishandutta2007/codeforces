#include <bits/stdc++.h>
const int N = 22;
int n, x, y, k, f[1 << N], g[1 << N];
inline void up(int &x, const int y) {x < y ? x = y : 0;}
int main() {
  std::cin >> n >> x >> y, k = x + y;
  if (x < y) std::swap(x, y);
  for (int i = 0; i < k; ++i) {
    int cur = (n - i + k - 1) / k;
    memset(g, 0, sizeof g);
    for (int j = 0; j < 1 << x; ++j) // not choosing
      up(g[(j & ((1 << x - 1) - 1)) << 1], f[j]); 
    for (int j = 0; j < 1 << x; ++j) { // choosing the current element
      if ((j >> (x - 1) & 1) || (j >> (y - 1) & 1)) continue;
      up(g[(j & ((1 << x - 1) - 1)) << 1 | 1], f[j] + cur);
    }
    std::swap(f, g);
  }
  printf("%d\n", *std::max_element(f, f + (1 << x)));
  return 0;
}