#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 100015, K = 12;
int n, m, q, a[N][K], id[N][K];
bitset<1 << K> c[N];
int main() {
//  freopen("matrix.in", "r", stdin);
//  freopen("matrix.out", "w", stdout);
  read(m), read(n), read(q);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      read(a[j][i]);
      id[j][i] = i;
    }
    for (int j = 0; j < 1 << n; ++j) {
      c[i][j] = (j >> i & 1);
    }
  }
  for (int i = 1; i <= m; ++i) {
    sort(id[i], id[i] + n, [&](int x, int y) {
      return a[i][x] > a[i][y];
    });
  }
  int cur = n - 1;
  for (int _ = 1, t, x, y; _ <= q; ++_) {
    read(t), read(x), read(y);
    if (t == 1) {
      c[++cur] = c[x - 1] | c[y - 1];
    } else if (t == 2) {
      c[++cur] = c[x - 1] & c[y - 1];
    } else {
      int mask = 0;
      for (int i = 0; i < n; ++i) {
        mask |= (1 << id[y][i]);
        if (c[x - 1][mask]) {
          printf("%d\n", a[y][id[y][i]]);
          break;
        }
      }
    }
  }
  return 0;
}