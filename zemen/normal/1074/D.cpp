#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 500500;
map<int, int> conv;
vector<pair<int, int>> g[maxn];
int p[maxn];
int up[maxn];
int s[maxn];

int compr(int u) {
  if (!conv.count(u)) {
    int v = (int) conv.size();
    return conv[u] = v;
  }
  return conv[u];
}

pair<int, int> root(int u) {
  if (p[u] == -1) {
    return {u, 0};
  }
  auto x = root(p[u]);
  x.second ^= up[u];
  return x;
}

void recolor(int u, int x) {
  for (auto& p : g[u]) {
    p.second ^= x;
    up[p.first] ^= x;
    recolor(p.first, x);
  }
}

void join(int u, int v, int x) {
  u = compr(u), v = compr(v);
  auto pu = root(u), pv = root(v);
  if (pu.first == pv.first) {
    return;
  }
  x ^= pu.second ^ pv.second;
  u = pu.first, v = pv.first;
  if (s[u] > s[v]) {
    swap(u, v);
  }
  g[v].emplace_back(u, x);
  s[v] += s[u];
  p[u] = v;
  up[u] = x;
}

int ask(int u, int v) {
  u = compr(u), v = compr(v);
  auto pu = root(u), pv = root(v);
  if (pu.first != pv.first) {
    return -1;
  }
  return pu.second ^ pv.second;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int q;
  cin >> q;
  int last = 0;
  for (int i = 0; i < maxn; ++i) {
    p[i] = -1;
    s[i] = 1;
  }
  for (int i = 0; i < q; ++i) {
    int t, l, r, x;
    cin >> t >> l >> r;
    l ^= last, r ^= last;
    if (l > r) {
      swap(l, r);
    }
    ++r;
    if (t == 1) {
      cin >> x;
      x ^= last;
      join(l, r, x);
    } else {
      int ans = ask(l, r);
      last = abs(ans);
      cout << ans << '\n';
    }
  }
}