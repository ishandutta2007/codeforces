#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, c[N][N][N], f[N][N], cnt[N][N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int l, r;
      scanf("%d%d", &l, &r);
      ++cnt[l][r];
    }
  } 
  for (int i = 1; i <= m; ++i) {
    for (int l = 1, r = i; r <= m; ++l, ++r) {
      for (int k = l; k <= r; ++k) {
        c[l][r][k] = c[l + 1][r][k];
        for (int j = k; j <= r; ++j) {
          c[l][r][k] += cnt[l][j];
        }
        f[l][r] = max(f[l][r], f[l][k - 1] + f[k + 1][r] + c[l][r][k] * c[l][r][k]);
      }
    }
  }
  printf("%d\n", f[1][m]);
  return 0;
}