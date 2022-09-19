# include <bits/stdc++.h>
using namespace std;
const int MN = 101;
int u[MN][MN];
int find(int n, int x) {
  if (u[n][x] == x)
    return x;
  else
    return u[n][x] = find(n, u[n][x]);
}
void onion(int n, int x, int y) {
  u[n][find(n, x)] = find(n, y);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    for (int k = 1; k <= n; ++k)
      u[i][k] = k;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    onion(c, a, b);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
     int a, b;
     scanf("%d%d", &a, &b);
     int ans = 0;
     for (int k = 1; k <= m; ++k)
        if (find(k, a) == find(k, b))
          ans++;
      printf("%d\n", ans);
  }
}