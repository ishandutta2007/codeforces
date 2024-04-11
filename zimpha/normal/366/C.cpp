#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1e5 + 10;

int f[N], g[N];
int a[N], b[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  int extra = 0, sum_pos = 0, sum_neg = 0;
  memset(f, -1, sizeof(f));
  memset(g, -1, sizeof(g));
  f[0] = g[0] = 0;
  for (int i = 0; i < n; ++i) {
    int c = a[i] - b[i] * k;
    if (c > 0) {
      sum_pos += c;
      for (int j = sum_pos; j >= c; --j) if (f[j - c] != -1) {
        f[j] = std::max(f[j], f[j - c] + a[i]);
      }
    } else if (c < 0) {
      sum_neg -= c;
      for (int j = sum_neg; j >= -c; --j) if (g[j + c] != -1) {
        g[j] = std::max(g[j], g[j + c] + a[i]);
      }
    } else {
      extra += a[i];
    }
  }
  int ret = extra ? extra : -1;
  for (int i = 1; i <= sum_pos && i <= sum_neg; ++i) {
    if (f[i] == -1 || g[i] == -1) continue;
    ret = std::max(ret, f[i] + g[i] + extra);
  }
  printf("%d\n", ret);
  return 0;
}