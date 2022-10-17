#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, dgr[N];
bitset<N> a[N], g[N];
int main() {
  scanf("%d", &n);
  bool flag = 1;
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    flag &= k == n;
    while (k--) {
      int x;
      scanf("%d", &x);
      a[i][x] = 1;
    } 
  }
  if (flag) {
    for (int i = 2; i <= n; ++i) {
      printf("1 %d\n", i);
    }
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      auto x = a[i] & a[j];
      if (x.count() == 2) {
        int u = x._Find_first(), v = x._Find_next(u);
        if (!g[u][v]) {
          g[u][v] = g[v][u] = 1;
          ++dgr[u], ++dgr[v]; 
        }
      }
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (int v = u + 1; v <= n; ++v) {
      if (g[u][v] && dgr[u] == 1 && dgr[v] == 1) {
        printf("%d %d\n", u, v);
        for (int i = 1; i <= n; ++i) {
          if ((int) a[i].count() < n) {
            for (int x = 1; x <= n; ++x) {
              if (x != u && x != v) {
                printf("%d %d\n", x, a[i][x] ? u : v);
              }
            }
            return 0;
          }
        }
      }
    }
  }
  for (int u = 1; u <= n; ++u) {
    if (g[u].none()) {
      bitset<N> x;
      x.set();
      for (int j = 1; j <= n; ++j) {
        if (a[j][u] && a[j].count() < x.count()) {
          x = a[j];
        }
      }
      for (int v = 1; v <= n; ++v) {
        if (x[v] && (g[v] & x).count() > 1) {
          g[u][v] = g[v][u] = 1;
          goto QAQ;
        }
      }
      for (int v = 1; v <= n; ++v) {
        if (x[v] && dgr[v] == 1 && (g[v] & x).any()) {
          g[u][v] = g[v][u] = 1;
          break;
        }
      }
      QAQ:;
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (int v = u + 1; v <= n; ++v) {
      if (g[u][v]) {
        printf("%d %d\n", u, v);
      }
    }
  }
  return 0;
}