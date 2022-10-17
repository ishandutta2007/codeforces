#include <bits/stdc++.h>
using namespace std;
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
const long long inf = 1e18;
const int N = 300005;
struct SegmentTree {
  long long val[N << 2], lzy[N << 2];
  inline void pushup(int p) {
    val[p] = min(val[p << 1], val[p << 1 | 1]);
  }
  inline void tag(int p, long long v) {
    val[p] += v;
    lzy[p] += v;
  }
  inline void pushdown(int p) {
    if (lzy[p]) {
      tag(p << 1, lzy[p]);
      tag(p << 1 | 1, lzy[p]);
      lzy[p] = 0;
    }
  }
  void modify(int p, int l, int r, int pos, long long v) {
    if (l == r) {
      val[p] = v;
      return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if (mid >= pos) {
      modify(p << 1, l, mid, pos, v);
    } else {
      modify(p << 1 | 1, mid + 1, r, pos, v);
    }
    pushup(p);
  }
  void add(int p, int l, int r, int L, int R, long long v) {
    if (L <= l && r <= R) {
      tag(p, v);
      return;
    }
    pushdown(p);
    int mid = l + r >> 1;
    if (mid >= L) {
      add(p << 1, l, mid, L, R, v);
    }
    if (mid < R) {
      add(p << 1 | 1, mid + 1, r, L, R, v);
    }
    pushup(p);
  }
  long long query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
      return val[p];
    }
    pushdown(p);
    int mid = l + r >> 1;
    if (mid >= L && mid < R) {
      return min(query(p << 1, l, mid, L, R), query(p << 1 | 1, mid + 1, r, L, R));
    } else if (mid >= L) {
      return query(p << 1, l, mid, L, R);
    } else {
      return query(p << 1 | 1, mid + 1, r, L, R);
    }
  }
} smt;
int n, m;
int tot, l[N], r[N], rev[N];
vector<int> g[N];
struct node {
  int w, id;
}; vector<node> s[N], t[N];
long long f[N]; 
void pre(int u, int fa) {
  l[u] = tot + 1;
  for (auto add : s[u]) {
    rev[add.id] = ++tot;
  }
  for (auto v : g[u]) {
    if (v ^ fa) {
      pre(v, u);
    }
  }
  r[u] = tot;
}
void dfs(int u, int fa) {
  long long sum = 0;
  for (auto v : g[u]) {
    if (v ^ fa) {
      dfs(v, u);
      sum += f[v];
    }
  }
  if (u == 1) {
    printf("%lld\n", sum);
    exit(0);
  }
  for (auto add : s[u]) {
    smt.modify(1, 1, m, rev[add.id], sum + add.w);
  }
  for (auto del : t[u]) {
    smt.modify(1, 1, m, rev[del.id], inf);
  }
  for (auto v : g[u]) {
    if (v ^ fa) {
      smt.add(1, 1, m, l[v], r[v], sum - f[v]);
    }
  }
  if (l[u] <= r[u]) {
    f[u] = smt.query(1, 1, m, l[u], r[u]);
  } else {
    f[u] = inf;
  }
  if (f[u] >= inf) {
    puts("-1");
    exit(0);
  }
}
int main() {
  read(n), read(m);
  for (int i = 1, u, v; i < n; ++i) {
    read(u), read(v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1, v, u, w; i <= m; ++i) {
    read(u), read(v), read(w);
    s[u].push_back((node) {w, i});
    t[v].push_back((node) {w, i});
  }
  pre(1, 0);
  dfs(1, 0);
  return 0;
}