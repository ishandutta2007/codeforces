#include <bits/stdc++.h>
using namespace std;
const int N = 2005, M = 100005;
int a, b, m, d[N], D, e[N][N], ans[M], mp[N][N]; 
inline void color(int u, int v) {
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= D; ++i) {
    bool v1 = e[u][i], v2 = e[v][i];
    if (!v1 && !v2) {
      e[u][i] = v, e[v][i] = u;
      return;
    } 
    else if (v1 && !v2) c1 = i;
    else if (!v1 && v2) c2 = i;
  }
  while (true) {
    e[u][c2] = v;
    int w = e[v][c2];
    e[v][c2] = u, e[v][c1] = 0;
    if (!w) break;
    e[v][c1] = w;
    int v1 = e[w][c1];
    e[w][c1] = v, e[w][c2] = 0;
    if (!v1) break;
    v = v1, u = w;
  }
}
int main() {
  scanf("%d%d%d", &a, &b, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    mp[u][a + v] = i, ++d[u], ++d[a + v];
  }
  D = *max_element(d + 1, d + a + b + 1);
  for (int i = 1; i <= a; ++i)
    for (int j = 1; j <= b; ++j)
      if (mp[i][a + j]) color(i, a + j);
  for (int u = 1; u <= a; ++u)
    for (int i = 1; i <= D; ++i)
      if (e[u][i]) ans[mp[u][e[u][i]]] = i;
  printf("%d\n", D);
  for (int i = 1; i <= m; ++i) 
    printf("%d ", ans[i]);
  return 0;
}