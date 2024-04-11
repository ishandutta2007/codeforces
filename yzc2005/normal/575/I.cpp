#include <bits/stdc++.h>
const int N = 5005, Q = 100005;
int n, q, ans[Q];
bool is_query[Q];
namespace F1 {
  int n, c[N * 2];
  void init(int _n) {
    n = _n;
    memset(c, 0, sizeof c);
  }
  void modify(int p) {
    for (; p <= n; p += p & -p)
      c[p] ++;
  }
  int query(int p) {
    int res = 0;
    for (; p; p -= p & -p)
      res += c[p];
    return res;
  }
}
namespace F2 {
  int n, m, c[N][N * 2];
  void init(int _n, int _m) {
    n = _n, m = _m;
    memset(c, 0, sizeof c);
  }
  void modify(int *c, int q) {
    for (; q <= m; q += q & -q)
      c[q] ++;
  } 
  void modify(int p, int q) {
    for (; p <= n; p += p & -p)
      modify(c[p], q);
  }
  int query(int *c, int q) {
    int res = 0;
    for (; q; q -= q & -q)
      res += c[q];
    return res;
  }
  int query(int p, int q) {
    int res = 0;
    for (; p; p -= p & -p)
      res += query(c[p], q);
    return res;
  }
}
struct node {
  int x, y, z;
  bool type;
  node(int _x = 0, int _y = 0, int _z = 0, bool _type = false) : x(_x), y(_y), z(_z), type(_type) {}
};         
struct Solver {
  std::vector<node> opr;
  void solve() {
    F1::init(n * 2);
    for (auto cur : opr) {
      if (cur.type) {
        int lim = std::min(n * 2, cur.x + cur.y + cur.z);
        F1::modify(n * 2 + 1 - lim);
      } else {
        ans[cur.z] += F1::query(n * 2 + 1 - cur.x - cur.y);
      }
    }
    F2::init(n, n * 2);
    for (auto cur : opr) {
      if (cur.type) {
        int x = cur.x - 1, y = cur.x + cur.y + cur.z;
        F2::modify(n + 1 - x, n * 2 + 1 - y);
      } else {
        ans[cur.z] -= F2::query(n + 1 - cur.x, n * 2 + 1 - cur.x - cur.y);
      }
    }
    F2::init(n, n * 2);
    for (auto cur : opr) {
      if (cur.type) {
        int x = cur.x + cur.y + cur.z, y = cur.y - 1;
        F2::modify(n + 1 - y, n * 2 + 1 - x);
      } else {
        ans[cur.z] -= F2::query(n + 1 - cur.y, n * 2 + 1 - cur.x - cur.y);
      }
    }
    F2::init(n, n);
    for (auto cur : opr) {
      if (cur.type) {
        int x = cur.x - 1, y = cur.y - 1;
        F2::modify(n + 1 - x, n + 1 - y);
      } else {
        ans[cur.z] += F2::query(n + 1 - cur.x, n + 1 - cur.y);
      }
    } 
  }
} o[4];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= q; ++i) {
    int op, dir, x, y, len;
    auto trans = [&](int x, bool type) {
      return type ? n + 1 - x : x;
    };
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d%d", &dir, &x, &y, &len);
      o[dir].opr.emplace_back(node(trans(x, dir > 2), trans(y, !(dir & 1)), len, true));
    } else {
      is_query[i] = true;
      scanf("%d%d", &x, &y);
      for (int dir = 1; dir <= 4; ++dir)
        o[dir].opr.emplace_back(node(trans(x, dir > 2), trans(y, !(dir & 1)), i, false));
    }
  }
  for (int i = 1; i <= 4; ++i) 
    o[i].solve();
  for (int i = 1; i <= q; ++i) 
    if (is_query[i]) printf("%d\n", ans[i]);
  return 0;
}