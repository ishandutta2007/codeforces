#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 50005;
const int M = 15000005;

int n, m, q, c, tim, tot, a[N], b[N], v[N], bel[N], dep[N], dfn[N], par[N], siz[N], tl[M], tr[M], tt[M];
LL sum[N], sqr[N], ts[M];
vector <int> adj[N];

inline void DFS(int x) {
  siz[x] = 1;
  for (auto y : adj[x]) {
    dep[y] = dep[x] + 1, DFS(y), siz[x] += siz[y];
  }
}

inline void DFS(int x, int c) {
  bel[x] = c, dfn[x] = ++tim;
  int k = 0;
  for (auto y : adj[x]) {
    if (siz[y] > siz[k]) {
      k = y;
    }
  }
  if (!k) {
    return ;
  }
  DFS(k, c);
  for (auto y : adj[x]) {
    if (y != k) {
      DFS(y, y);
    }
  }
}

inline void Modify(int &x, int l, int r, int ql, int qr, int v) {
  if (!x) {
    x = ++tot;
  }
  ts[x] += (qr - ql + 1) * v;
  if (l == ql && r == qr) {
    tt[x] += v;
    return ;
  }
  int mid = l + r >> 1;
  if (qr <= mid) {
    Modify(tl[x], l, mid, ql, qr, v);
  } else if (ql > mid) {
    Modify(tr[x], mid + 1, r, ql, qr, v);
  } else {
    Modify(tl[x], l, mid, ql, mid, v), Modify(tr[x], mid + 1, r, mid + 1, qr, v);
  }
}

inline LL Query(int x, int l, int r, int ql, int qr) {
  if (!x) {
    return 0;
  }
  if (l == ql && r == qr) {
    return ts[x];
  }
  int mid = l + r >> 1;
  LL ret = 1LL * tt[x] * (qr - ql + 1);
  if (qr <= mid) {
    return Query(tl[x], l, mid, ql, qr) + ret;
  } else if (ql > mid) {
    return Query(tr[x], mid + 1, r, ql, qr) + ret;
  } else {
    return Query(tl[x], l, mid, ql, mid) + Query(tr[x], mid + 1, r, mid + 1, qr) + ret;
  }
}

inline void Modify(int x, int y, int v) {
  for (; y; y = par[bel[y]]) {
    Modify(x, 1, n, dfn[bel[y]], dfn[y], v);
  }
}

inline LL Query(int x, int y) {
  LL r = 0;
  for (; y; y = par[bel[y]]) {
    r += Query(x, 1, n, dfn[bel[y]], dfn[y]);
  }
  return r;
}

inline void Insert(int x, int y) {
  sum[x] += dep[y];
  sqr[x] += (Query(x, y) << 1) + dep[y];
  Modify(x, y, 1);
}

inline void Delete(int x, int y) {
  Modify(x, y, -1);
  sqr[x] -= (Query(x, y) << 1) + dep[y];
  sum[x] -= dep[y];
}

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  Read(n), Read(m), Read(q), Read(c), tot = m;
  for (int i = 1; i <= n; ++i) {
    Read(a[i]);
  }
  for (int i = 2; i <= n; ++i) {
    Read(par[i]), adj[par[i]].pb(i);
  }
  for (int i = 1; i <= m; ++i) {
    Read(v[i]);
  }
  dep[1] = 1, DFS(1), DFS(1, 1);
  for (int i = 1; i <= n; ++i) {
    Insert(a[i], i);
  }
  for (int i = 1, opt, x, y; i <= q; ++i) {
    Read(opt), Read(x);
    if (opt == 1) {
      Read(y), Delete(a[x], x), a[x] = y, Insert(a[x], x);
    } else {
      printf("%lf\n", (1.0 * sqr[x] * v[x] * v[x] + 1.0 * c * c * n - 2.0 * sum[x] * v[x] * c) / n);
    }
  }
}