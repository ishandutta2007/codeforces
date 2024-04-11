#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, q, cnt;
set<int> g[N];

inline void link(int u, int v) {
  bool prv = g[u].empty() || *--g[u].end() < u;
  g[u].insert(v);
  if (prv && v > u) ++cnt;
}

inline void del(int u, int v) {
  cnt -= *--g[u].end() > u;
  g[u].erase(v);
  cnt += (!g[u].empty() && *--g[u].end() > u);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    link(u, v), link(v, u);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int op, x, y;
    if (scanf("%d", &op), op != 3) scanf("%d%d", &x, &y);
    if (op == 1) link(x, y), link(y, x);
    else if (op == 2) del(x, y), del(y, x);
    else printf("%d\n", n - cnt);
  }
  return 0;
}