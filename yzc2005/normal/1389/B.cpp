#include <bits/stdc++.h>
using namespace std;
const int N = 100005, inf = 0x3f3f3f3f;
int n, a[N], k, z, f[N][6][2];
inline void ckmax(int &a, int b) {
  if (a < b) a = b;
}
int main() {
  int T; scanf("%d", &T); while (T--) {
    scanf("%d%d%d", &n, &k, &z);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i <= k; ++i)
      for (int j = 0; j <= z; ++j)
        for (int l = 0; l < 2; ++l)
          f[i][j][l] = -inf;
    f[0][0][0] = a[1];
    for (int i = 0; i < k; ++i) 
      for (int j = 0; j <= z; ++j) 
        for (int l = 0; l < 2; ++l) {
          int pos = i - 2 * j + 1;
          ckmax(f[i + 1][j][0], f[i][j][l] + a[pos + 1]);
          if (pos > 1 && j < z && l == 0) ckmax(f[i + 1][j + 1][1], f[i][j][0] + a[pos - 1]);
        }
    int res = -inf;
    for (int i = 0; i <= z; ++i)
      for (int j = 0; j < 2; ++j)
        ckmax(res, f[k][i][j]);
    printf("%d\n", res);
  }
  return 0;
}