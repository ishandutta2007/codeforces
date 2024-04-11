#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<vector<int>> g;
vector<int> in, out, ord;
set<int> span;
int span_root = -1;
int timer;

const int maxd = 18;
vector<array<int, maxd>> up;

void pre(int u, int prev = -1) {
  ord.push_back(u);
  in[u] = timer++;
  up[u][0] = prev == -1 ? u : prev;
  for (int i = 0; i + 1 < maxd; ++i) {
    up[u][i + 1] = up[up[u][i]][i];
  }
  for (int v : g[u]) {
    if (v != prev) {
      pre(v, u);
    }
  }
  out[u] = timer;
}

bool is_prev(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
  for (int d = maxd - 1; d >= 0; --d) {
    if (!is_prev(up[u][d], v)) {
      u = up[u][d];
    }
  }
  if (!is_prev(u, v)) {
    u = up[u][0];
  }
  assert(is_prev(u, v));
  return u;
}

void expand(int u) {
  if (span_root == -1 || in[u] < in[span_root]) {
    span_root = u;
  }
  auto nx = span.lower_bound(in[u]);
  bool bad = false;
  if (nx != span.begin()) {
    auto pr = prev(nx);
    int v = ord[*pr];
    if (is_prev(v, u)) {
      span.erase(pr);
    } else if (is_prev(u, v)) {
      bad = true;
    }
  }
  if (nx != span.end()) {
    int v = ord[*nx];
    if (is_prev(v, u)) {
      span.erase(nx);
    } else if (is_prev(u, v)) {
      bad = true;
    }
  }
  if (!bad) {
    span.insert(in[u]);
  }
}

int span_size() {
  if (span.empty()) {
    return 0;
  }
  int res = (int) span.size();

  int vl = ord[*span.begin()];
  int vr = ord[*span.rbegin()];
  int l = lca(vl, vr);
  if (in[span_root] < in[l]) {
    ++res;
  }
  return res;
}

mt19937 rnd(1334);

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i].first;
    h[i].second = i;
  }
  g.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  const int root = rnd() % n;
  cerr << "root: " << root + 1 << '\n';
  in.resize(n);
  out.resize(n);
  up.resize(n);
  pre(root);

  sort(h.rbegin(), h.rend());
  ll res = 0;
  int sz = 0;
  for (auto [ch, u] : h) {
    //cerr << "expand " << u + 1 << '\n';
    expand(u);
    int new_sz = span_size();
    //cerr << "span: [" << span_root + 1 << "] ";
    //for (auto x : span) {
      //cerr << ord[x] + 1 << ' ';
    //}
    //cerr << "size: " << new_sz << '\n';
    if (sz == 0) {
      res += 2 * ch;
    } else if (sz > 1) {
      int delta = new_sz - sz;
      assert(delta == 0 || delta == 1);
      res += delta * ch;
    }
    sz = new_sz;
  }
  cout << res << '\n';
}