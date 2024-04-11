#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

const int N = 15005, M = 305;
int n, a[N], f[N][M], g[N][M];

struct Fenwick {
  int n, c[N];
  void init(int _n) {
    n = _n;
    std::fill(c + 1, c + n + 1, inf);
  }
  void modify(int x, int y) {
    for (; x <= n; x += x & -x) 
      c[x] = min(c[x], y);
  }
  int query(int x) {
    int res = inf;
    for (; x; x -= x & -x) 
      res = min(res, c[x]);
    return res;
  }
} t1[M], t2[M], t3[M], t4[M];

int calc(int type) { // choosing / not choosing a_1
  int ans = 1;
  for (int i = 1; i < M; ++i) {
    t1[i].init(n), t2[i].init(n);
    t3[i].init(n), t4[i].init(n);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < M; ++j)
      f[i][j] = inf, g[i][j] = -inf;
  if (type == 0) {
    f[1][1] = a[1];
    t1[1].modify(n + 1 - a[1], a[1]);
    g[1][1] = a[1];
    t2[1].modify(a[1], n + 1 - a[1]);
  }
  for (int i = 2; i <= n; ++i) {
    if (type == 1) {
      f[i][2] = a[i];
      g[i][2] = a[i];
    }  
    int sup = min(M - 1, i);
    for (int j = 2 + type; j <= sup; ++j) {
      f[i][j] = t1[j - 1].query(n + 1 - a[i]);
      g[i][j] = n + 1 - t2[j - 1].query(a[i]);
      int pos = i - j + 1;
      t3[j - 1].modify(f[pos][j - 1], n + 1 - a[pos]);
      t4[j - 1].modify(n + 1 - g[pos][j - 1], a[pos]); 
      f[i][j] = min(f[i][j], t4[j - 1].query(n + 1 - a[i]));
      g[i][j] = max(g[i][j], n + 1 - t3[j - 1].query(a[i]));
      if (f[i][j] <= n || g[i][j] >= 1) ans = max(ans, j);
    }
    for (int j = 2; j <= sup; ++j) {
      t1[j].modify(n + 1 - a[i], f[i][j]);
      t2[j].modify(a[i], n + 1 - g[i][j]);
    }
  }
  return ans - type;
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  reverse(a + 1, a + n + 1);
  printf("%d\n", max(calc(0), calc(1)));
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}

// prepend a smaller number
// append a bigger number
// jump back and forth between endpoints
// f : currently at left, minimal rightmost element
// g : currently at right, maximal leftmost element