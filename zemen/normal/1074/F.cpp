#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 200200;
const int LG = 18;
vector<int> g[maxn];
int in[maxn], out[maxn];
int p[maxn][LG];
int timer = 0;

const int inf = 1e9;

struct E {
  int value, cnt;

  E() : value(-inf), cnt(0) {}

  explicit E(int value) : value(value), cnt(1) {}

  E(const E& a, const E& b) {
    if (a.value > b.value) {
      *this = a;
    } else if (a.value < b.value) {
      *this = b;
    } else {
      *this = a;
      cnt += b.cnt;
    }
  }
};

struct Add {
  int value;

  Add() : value(0) {}

  explicit Add(int value) : value(value) {}

  Add(const Add& a, const Add& b) {
    value = a.value + b.value;
  }
};

void apply(E& e, const Add& m, int l, int r) {
  e.value += m.value;
  (void) l, (void) r;
}

template<typename E, typename M>
struct ST {
  static constexpr int inf = 1e9;
  int base;
  vector<E> t;
  vector<M> upd;

  static int calc_base(int n) {
    int x = 1;
    while (x < n) {
      x *= 2;
    }
    return x;
  }

  ST() : base(0) {}
  ST(int n) : base(calc_base(n)), t(base * 2), upd(base * 2) {}

  void push(int v, int cl, int cr) {
    int cc = (cl + cr) / 2;
    apply(t[v * 2 + 0], upd[v], cl, cc);
    apply(t[v * 2 + 1], upd[v], cc, cr);
    upd[v * 2 + 0] = M(upd[v * 2 + 0], upd[v]);
    upd[v * 2 + 1] = M(upd[v * 2 + 1], upd[v]);
    upd[v] = M();
  }

  E get(int l, int r, int v = 1, int cl = 0, int cr = inf) {
    cr = min(cr, base);
    if (l <= cl && cr <= r) {
      return t[v];
    }
    if (r <= cl || cr <= l) {
      return E();
    }
    push(v, cl, cr);
    int cc = (cl + cr) / 2;
    return E(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
  }

  void put(int l, int r, const M& x, int v = 1, int cl = 0, int cr = inf) {
    cr = min(cr, base);
    if (l <= cl && cr <= r) {
      apply(t[v], x, cl, cr);
      upd[v] = M(upd[v], x);
      return;
    }
    if (r <= cl || cr <= l) {
      return;
    }
    push(v, cl, cr);
    int cc = (cl + cr) / 2;
    put(l, r, x, v * 2 + 0, cl, cc);
    put(l, r, x, v * 2 + 1, cc, cr);
    t[v] = E(t[v * 2], t[v * 2 + 1]);
  }

  E& raw_data(int pos) {
    return t[base + pos];
  }

  void build() {
    for (int i = base - 1; i > 0; --i) {
      t[i] = E(t[i * 2], t[i * 2 + 1]);
    }
  }

  void set(int pos, const E& val, int v = 1, int cl = 0, int cr = inf) {
    cr = min(cr, base);
    if (cl + 1 == cr) {
      assert(v == pos + base);
      t[v] = val;
      return;
    }
    push(v, cl, cr);
    int cc = (cl + cr) / 2;
    if (pos < cc) {
      set(pos, val, v * 2, cl, cc);
    } else {
      set(pos, val, v * 2 + 1, cc, cr);
    }
    t[v] = E(t[v * 2], t[v * 2 + 1]);
  }
};

ST<E, Add> tree;

void dfs(int u, int prev = -1) {
  in[u] = timer++;
  p[u][0] = prev == -1 ? u : prev;
  for (int i = 0; i + 1 < LG; ++i) {
    p[u][i + 1] = p[p[u][i]][i];
  }
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    dfs(v, u);
  }
  out[u] = timer;
}

bool is_prev(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int go_up(int u, int v) {
  assert(is_prev(u, v));
  assert(!is_prev(v, u));
  for (int d = LG - 1; d >= 0; --d) {
    if (!is_prev(p[v][d], u)) {
      v = p[v][d];
    }
  }
  return v;
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  mt19937 rr(random_device{}());
  int ROOT = rr() % n;
  //cerr << "root: " << ROOT << '\n';

  dfs(ROOT);

  tree = ST<E, Add>(n);
  for (int i = 0; i < n; ++i) {
    tree.raw_data(i) = E(0);
  }
  tree.build();

  set<pair<int, int>> es;
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v) {
      swap(u, v);
    }
    int sgn = 1;
    if (es.count({u, v})) {
      sgn = -1;
      es.erase({u, v});
    } else {
      es.insert({u, v});
    }
    for (int it = 0; it < 2; ++it) {
      if (is_prev(u, v)) {
        int w = go_up(u, v);
        tree.put(0, n, Add(sgn));
        tree.put(in[w], out[w], Add(-sgn));
      } else {
        tree.put(in[u], out[u], Add(sgn));
      }
      swap(u, v);
    }
    auto e = tree.get(0, n);
    assert(e.value <= (int) es.size());
    int res = e.value == (int) es.size() ? e.cnt : 0;
    cout << res << '\n';
  }
}