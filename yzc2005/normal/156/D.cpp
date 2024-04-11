#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k, fa[N], sz[N];
int get(int x) {
  return x == fa[x] ? x : fa[x] = get(fa[x]);
}
inline void merge(int x, int y) {
  x = get(x);
  y = get(y);
  if (x ^ y) {
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    fa[x] = y;
    sz[y] += sz[x];
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    sz[i] = 1;
  }
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    merge(u, v);
  }
  int ans = 1, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (fa[i] == i) {
      ++cnt;
      ans = 1ll * sz[i] * ans % k;
    }
  }
  if (cnt == 1) {
    cout << 1 % k << "\n";
  } else {
    for (int i = 1; i <= cnt - 2; ++i) {
      ans = 1ll * ans * n % k;
    }
    cout << ans << "\n";
  }
  return 0;
}