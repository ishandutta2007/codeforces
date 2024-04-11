#include <bits/stdc++.h>

const int N = 105;
int n, s, sb, f[N][N * N];

int main() {
  std::cin >> n;
  memset(f, 0xcf, sizeof(f)), **f = 0;
  for (int t = 1, a, b; t <= n; ++t) {
    std::cin >> a >> b, s += a, sb += b;
    for (int i = t; i; --i)
      for (int j = s; j >= a; --j)
        f[i][j] = std::max(f[i][j], f[i - 1][j - a] + b);
  }
  for (int k = 1; k <= n; ++k) {
    double ans = 0;
    for (int i = 1; i <= s; ++i)
      ans = std::max(ans, std::min(1.0 * i, (f[k][i] + sb) * 0.5));
    printf("%lf ", ans);
  }
  return 0;
}