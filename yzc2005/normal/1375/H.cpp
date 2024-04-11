#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 12 | 5, Q = 1 << 16 | 5;
int n, q, B, a[N], p[N], cnt, id[Q];
vector<pair<int, int>> opt;
struct node {
  int n;
  vector<int> pos;
  vector<vector<int>> id; 
  node(int _n = 0) {
    n = _n;
    pos.resize(n);
    id.resize(n);
    for (auto &v : id) {
      v.resize(n);
    }
  }
  inline int get(int l, int r) {
    l = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
    r = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;
    return l <= r ? id[l][r] : 0;
  }
} sqr[N];
inline int merge(int x, int y) {
  int res;
  if (x && y) {
    opt.push_back({x, y});
    res = ++cnt;
  } else {
    res = x | y;
  }
  return res;
}
node solve(int l, int r, int s) {
  if (l == r) {
    node res(1);
    res.pos = {p[s + l]};
    res.id = {{p[s + l]}};
    return res;
  }
  int mid = l + r >> 1;
  node x = solve(l, mid, s);
  node y = solve(mid + 1, r, s);
  node z(x.n + y.n);
  merge(x.pos.begin(), x.pos.end(), y.pos.begin(), y.pos.end(), z.pos.begin());
  for (int i = 0; i < z.n; ++i) {
    for (int j = i; j < z.n; ++j) {
      int l = z.pos[i], r = z.pos[j];
      z.id[i][j] = merge(x.get(l, r), y.get(l, r));
    }
  }
  return z;
}
int main() {
  scanf("%d%d", &n, &q);
  B = sqrt(q);
  cnt = n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    p[a[i]] = i;
  }
  for (int i = 1, j = 1; i <= n; i += B, ++j) {
    sqr[j] = solve(0, min(i + B - 1, n) - i, i);
  }
  for (int t = 1; t <= q; ++t) {
    int l, r;
    scanf("%d%d", &l, &r);
    for (int i = 1, j = 1; i <= n; i += B, ++j) {
      id[t] = merge(id[t], sqr[j].get(l, r));
    }
  }
  printf("%d\n", cnt);
  for (auto x : opt) {
    printf("%d %d\n", x.first, x.second);
  }
  for (int t = 1; t <= q; ++t) {
    printf("%d%c", id[t], " \n"[t == q]);
  }
  return 0;
}