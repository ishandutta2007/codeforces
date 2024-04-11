#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ll infl = 1e18;

struct LL {
  ll value;

  LL() : value(infl) {}

  explicit LL(ll value) : value(value) {}

  LL(const LL& a, const LL& b) {
    value = min(a.value, b.value);
  }
};

struct Add {
  ll value;

  Add() : value(0) {}

  explicit Add(ll value) : value(value) {}

  Add(const Add& a, const Add& b) {
    value = a.value + b.value;
  }
};

void apply(LL& e, const Add& m, int l, int r) {
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

ST<LL, Add> st;
const int maxn = 500500;
vector<ll> dist;
vector<ll> W;
vector<int> g[maxn];
vector<int> qid[maxn];
int ql[maxn];
int qr[maxn];
ll ans[maxn];

int out[maxn];
int timer = 0;

void pre(int u) {
  assert(timer == u);
  ++timer;
  for (int v : g[u]) {
    pre(v);
  }
  out[u] = timer;
}

void dfs(int u, ll add = 0) {
  for (auto id : qid[u]) {
    ans[id] = st.get(ql[id], qr[id]).value + add;
  }
  for (int v : g[u]) {
    st.put(v, out[v], Add(-2 * W[v]));
    dfs(v, add + W[v]);
    st.put(v, out[v], Add(2 * W[v]));
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  dist.assign(n, 0);
  W.assign(n, 0);
  for (int i = 1; i < n; ++i) {
    int p, w;
    cin >> p >> w;
    --p;
    dist[i] = dist[p] + w;
    W[i] = w;
    g[p].push_back(i);
  }
  for (int i = 0; i < q; ++i) {
    int v, l, r;
    cin >> v >> l >> r;
    --v, --l;
    qid[v].push_back(i);
    ql[i] = l;
    qr[i] = r;
  }
  st = ST<LL, Add>(n);
  for (int i = 0; i < n; ++i) {
    if (g[i].empty()) {
      st.set(i, LL(dist[i]));
    }
  }
  st.build();

  pre(0);
  dfs(0);
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
}