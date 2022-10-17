#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int N = 1502, K = 12;
int n, q, a[N][N], ans[N], v1[N];
P c[N][N][K], s1[N][K], s2[N][K];
bool vis[N * N];

inline void merge(P *a, P *b, P *r) {
  static P c[K]; int t = 0, j = 0;
  for (int i = 0; a[i].first && t <= q; ++i) {
    for (; b[j].first && b[j].first < a[i].first && t <= q; ++j) 
      if (!vis[b[j].second]) vis[b[j].second] = 1, c[t++] = b[j];
    if (!vis[a[i].second] && t <= q) vis[a[i].second] = 1, c[t++] = a[i];
  }
  for (; b[j].first && t <= q; ++j)
    if (!vis[b[j].second]) c[t++] = b[j];
  for (int i = 0; i < t; ++i) vis[c[i].second] = 0, r[i] = c[i];
  r[t].first = 0;
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%d", &a[i][j]);
  for (int j = 1; j <= n; ++j) 
    for (int i = n; i; --i) {
      c[i][j][0] = {i, a[i][j]};
      for (int k = 0, t = 1; c[i + 1][j][k].first && t <= q; ++k)
        if (c[i + 1][j][k].second != a[i][j]) c[i][j][t++] = c[i + 1][j][k];
    }
  for (int i = 1; i <= n; ++i) {
    int t1 = 0, t2 = 0;
    auto push = [&](int x) {
      v1[++t1] = x, memset(s1[t1], 0, sizeof s1[t1]);
      merge(s1[t1 - 1], c[i][x], s1[t1]);
    };
    auto pop = [&]() {
      if (!t2) {
        for (; t1; --t1) {
          ++t2, memset(s2[t2], 0, sizeof s2[t2]);
          merge(s2[t2 - 1], c[i][v1[t1]], s2[t2]);
        }
      }
      --t2;
    };
    auto query = [&]() {
      static P v[K]; memset(v, 0, sizeof v);
      if (!t1 && !t2) return 0;
      if (!t2) return s1[t1][q].first;
      return merge(s1[t1], s2[t2], v), v[q].first;
    };
    for (int l = 1, r = 0; l <= n; pop(), ++l) {
      while (r <= n) {
        int v = query(); // [l, r]
        if (v && v - i < r - l + 1) break;
        push(++r);
      }
      ++ans[min(r - l, n - i + 1)];
    }
  }
  for (int i = n; i; --i) ans[i] += ans[i + 1];
  for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
  return 0; 
}