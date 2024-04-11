#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
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
const int N = 1e4 + 5, M = 20;
int n, k, m, f[1 << M], s[N], x[M], a[N], dis[M][N];
inline void bfs(int s, int *dis) {
  memset(dis, 0x3f, (n + 2) << 2);
  dis[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 1; i <= m; ++i) {
      auto extend = [&](int v) {
        if (v >= 1 && v <= n + 1 && dis[v] == inf) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }; 
      extend(u - a[i]);
      extend(u + a[i]);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1, p; i <= k; ++i) {
    scanf("%d", &p);
    s[p] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }
  k = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] ^ s[i - 1]) {
      x[k++] = i;
    }
  }
  for (int i = 0; i < k; ++i) {
    bfs(x[i], dis[i]);
  }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int s = 0; s < 1 << k; ++s) {
    for (int i = 0; i < k; ++i) {
      if (!(s >> i & 1)) {
        auto chk = [&](int &x, int y) {
          x = min(x, y);
        };
        chk(f[s | (1 << i)], f[s] + dis[i][n + 1]);
        for (int j = i + 1; j < k; ++j) {
          if (!(s >> j & 1)) {
            chk(f[s | ((1 << i) | (1 << j))], f[s] + dis[i][x[j]]);
          }
        }
        break;
      }
    }
  }
  if (f[(1 << k) - 1] == inf) {
    puts("-1");
  } else {
    printf("%d\n", f[(1 << k) - 1]);
  }
  return 0;
}