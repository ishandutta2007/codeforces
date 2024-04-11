#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

namespace PushRelabel {
#define sz(x) (int) (x).size()
#define forn(i, n) for (int i = 0; i < n; ++i)
const int maxn = 200500;

struct Edge {
  int to;
  ll c, f;
};
vector<Edge> edge;

int n;
vector<int> g[maxn];
ll e[maxn];
int h[maxn];
int onH[maxn];
int S, T;
int ptr[maxn];
int relabelTimer;

void addEdge(int u, int v, ll c) {
  g[u].push_back(sz(edge));
  edge.push_back({v, c, 0});
  g[v].push_back(sz(edge));
  edge.push_back({u, 0, 0});
}

void push(int id, ll delta) {
  int u = edge[id ^ 1].to;
  int v = edge[id].to;
  edge[id].f += delta;
  edge[id ^ 1].f -= delta;
  e[u] -= delta;
  e[v] += delta;
}

void gap(int ch) {
  forn (u, n) {
    if (h[u] > ch)
      h[u] = max(h[u], n);
  }
}

int o[maxn];
void globalRelabeling() {
  int oc = 0;
  forn (i, n) {
    h[i] = n;
    onH[i] = 0;
  }
  onH[0] = 1;
  h[T] = 0;
  o[oc++] = T;
  forn (ii, oc) {
    int u = o[ii];
    for (int id: g[u]) {
      if (edge[id ^ 1].c == edge[id ^ 1].f)
        continue;
      int v = edge[id].to;
      if (h[v] != n)
        continue;
      h[v] = h[u] + 1;
      onH[h[v]]++;
      o[oc++] = v;
    }
  }
}

void relabel(int u) {
  int oldh = h[u];
  int newh = 1e9;
  for (int id: g[u]) {
    if (edge[id].c == edge[id].f)
      continue;
    newh = min(newh, h[edge[id].to] + 1);
  }
  h[u] = newh;
  onH[oldh]--;
  onH[newh]++;
  if (onH[oldh] == 0)
    gap(oldh);
  if (++relabelTimer == n)
    globalRelabeling(), relabelTimer = 0;
}

void discharge(int u) {
  while (e[u] > 0) {
    int &i = ptr[u];
    if (i == sz(g[u])) {
      i = 0;
      relabel(u);
      if (h[u] >= n)
        break;
      continue;
    } else {
      int id = g[u][i++];
      int v = edge[id].to;
      if (h[v] + 1 != h[u])
        continue;
      int delta = min(e[u], ll(edge[id].c - edge[id].f));
      push(id, delta);
    }
  }
}

ll flow(int _S, int _T) {
  S = _S, T = _T;
  forn (i, n)
    ptr[i] = 0, e[i] = 0;
  for (int id: g[S]) {
    int delta = edge[id].c;
    push(id, delta);
  }
  globalRelabeling();
  bool ok = false;
  while (!ok) {
    ok = true;
    forn (u, n) {
      if (h[u] < n && u != T && e[u] > 0)
        discharge(u), ok = false;
    }
  }
  return e[T];
}

} //PushRelabel

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  vector<int> xs, ys;
  struct R {
    int x1, y1, x2, y2;
  };
  vector<R> a;
  for (int i = 0; i < m; ++i) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1;
    --y1;
    xs.push_back(x1);
    xs.push_back(x2);
    ys.push_back(y1);
    ys.push_back(y2);
    a.push_back(R{x1, y1, x2, y2});
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  PushRelabel::n = (int) xs.size() + (int) ys.size();
  int S = PushRelabel::n - 2;
  int T = PushRelabel::n - 1;
  int off = (int) xs.size() - 1;
  for (int i = 0; i < (int) xs.size() - 1; ++i) {
    PushRelabel::addEdge(S, i, xs[i + 1] - xs[i]);
  }
  for (int i = 0; i < (int) ys.size() - 1; ++i) {
    PushRelabel::addEdge(i + off, T, ys[i + 1] - ys[i]);
  }
  vector<vector<char>> e((int) xs.size(), vector<char>((int) ys.size()));
  for (auto& r : a) {
    r.x1 = lower_bound(xs.begin(), xs.end(), r.x1) - xs.begin();
    r.x2 = lower_bound(xs.begin(), xs.end(), r.x2) - xs.begin();
    r.y1 = lower_bound(ys.begin(), ys.end(), r.y1) - ys.begin();
    r.y2 = lower_bound(ys.begin(), ys.end(), r.y2) - ys.begin();
    for (int i = r.x1; i < r.x2; ++i) {
      for (int j = r.y1; j < r.y2; ++j) {
        e[i][j] = true;
      }
    }
  }
  for (int i = 0; i < (int) xs.size() - 1; ++i) {
    for (int j = 0; j < (int) ys.size() - 1; ++j) {
      if (e[i][j]) {
        PushRelabel::addEdge(i, j + off, 2e18);
      }
    }
  }
  ll res = PushRelabel::flow(S, T);
  cout << res << '\n';
}