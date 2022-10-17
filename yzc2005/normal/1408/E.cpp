#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, a[N], b[N], c[N], fa[N];
long long ans;
struct node {
  int x, y, v;
};
int get(int x) {
  if (x == fa[x]) {
    return x;
  } else {
    return fa[x] = get(fa[x]);
  }
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  } 
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]); 
  }
  iota(fa, fa + n + 1, 0);
  vector<node> vec;
  for (int i = 1; i <= m; ++i) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int x;
      scanf("%d", &x);
      ans += a[i] + b[x];
      vec.push_back((node) {x, i, a[i] + b[x]});
    }
  }
  sort(vec.begin(), vec.end(), [&](node &x, node &y) {
    return x.v > y.v;
  });
  for (auto it : vec) {
    int x = it.x, y = it.y, v = it.v;
    if (!c[y]) {
      ans -= v;
      c[y] = get(x);
    } else {
      x = get(x);
      y = get(c[y]);
      if (x != y) {
        ans -= v;
        fa[x] = get(y);
      }
    }
  }
  printf("%lld\n", ans);
}