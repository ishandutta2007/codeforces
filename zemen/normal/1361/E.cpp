#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> g[maxn];
mt19937 rnd;

int timer;
int in[maxn];
int out[maxn];
int par[maxn];
int ord[maxn];
bool used[maxn];

void dfs1(int u) {
  ord[timer] = u;
  in[u] = timer++;
  used[u] = true;
  for (int v : g[u]) {
    if (used[v]) {
      continue;
    }
    par[v] = u;
    dfs1(v);
  }
  out[u] = timer;
}

bool is_prev(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

vector<char> good;
vector<int> up;
vector<int> dfs2(int u) {
  vector<int> up;
  for (int v : g[u]) {
    if (par[v] == u) {
      auto nup = dfs2(v);
      up.insert(up.end(), nup.begin(), nup.end());
    } else {
      up.push_back(in[v]);
    }
    sort(up.begin(), up.end());
    up.resize(min((int) up.size(), 2));
  }
  while (!up.empty() && up.back() >= in[u]) {
    up.pop_back();
  }
  if (up.size() > 1) {
    good[u] = false;
  } else if (up.size() == 1) {
    ::up[u] = ord[up.front()];
  }
  return up;
}

void dfs3(int u) {
  if (up[u] != -1 && !good[up[u]]) {
    good[u] = false;
  }
  for (int v : g[u]) {
    if (par[v] == u) {
      dfs3(v);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }
  for (int it = 0; it < 100; ++it) {
    fill(used, used + n, false);
    timer = 0;
    int u = rnd() % n;
    par[u] = -1;
    dfs1(u);
    bool fail = false;
    for (int i = 0; i < n; ++i) {
      for (int j : g[i]) {
        if (par[j] != i && !is_prev(j, i)) {
          fail = true;
        }
      }
    }
    if (fail) {
      continue;
    }
    good.assign(n, true);
    up.assign(n, -1);
    dfs2(u);
    dfs3(u);
    assert(good[u]);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      total += good[i];
    }
    if (total * 5 < n) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; ++i) {
        if (good[i]) {
          cout << i + 1 << ' ';
        }
      }
      cout << '\n';
    }
    return;
  }
  cout << -1 << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll seed = __rdtsc();
  rnd = mt19937(seed);

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}