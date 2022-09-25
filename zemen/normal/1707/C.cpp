#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct DSU {
  vector<int> col, rk;

  DSU(int n): col(n), rk(n) {
    iota(col.begin(), col.end(), 0);
  }

  int get(int u) {
    if (u == col[u]) {
      return u;
    }
    return col[u] = get(col[u]);
  }

  bool join(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) {
      return false;
    }
    if (rk[u] > rk[v]) {
      swap(u, v);
    }
    if (rk[u] == rk[v]) {
      ++rk[v];
    }
    col[u] = v;
    return true;
  }
};

const int maxn = 100100;
vector<int> g[maxn];
int c[maxn];
int in[maxn];
int out[maxn];
int depth[maxn];
int timer;

//mt19937 rnd(random_device{}());
mt19937 rnd(1337);

void dfs1(int u, int prev = -1) {
  in[u] = timer++;
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    depth[v] = depth[u] + 1;
    dfs1(v, u);
  }
  out[u] = timer;
}

vector<int> qs[maxn];
vector<int> st;
void dfs2(int u, int prev = -1) {
  st.push_back(u);
  for (auto q : qs[u]) {
    c[st[q]]--;
  }
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    dfs2(v, u);
  }
  st.pop_back();
}

string res;

void dfs3(int u, int bal, int prev = -1) {
  bal += c[u];
  assert(bal <= 0);
  res[u] = '0' + (bal == 0);
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    dfs3(v, bal, u);
  }
}

bool is_prev(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  DSU dsu(n);
  vector<pair<int, int>> es;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (dsu.join(u, v)) {
      g[u].push_back(v);
      g[v].push_back(u);
    } else {
      es.emplace_back(u, v);
    }
  }
  int root = rnd() % n;
  //cerr << "root: " << root << '\n';
  dfs1(root);
  for (auto [u, v] : es) {
    if (is_prev(v, u)) {
      swap(u, v);
    }
    if (is_prev(u, v)) {
      qs[v].push_back(depth[u] + 1);
      c[v]++;
      c[root]++;
    } else {
      c[u]++;
      c[v]++;
    }
  }
  dfs2(root);
  res.resize(n, ' ');
  dfs3(root, -(int) es.size());
  cout << res << '\n';
}