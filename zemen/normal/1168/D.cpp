#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 150100;
char sym[maxn];
int h[maxn];
int deg[maxn];
vector<int> g[maxn];
array<int, 26> a[maxn][2];
pair<int, int> up[maxn];
int pr[maxn];
int leaves_h = -1;
int q;
int bad_deg = 0;

void sosat() {
  //cerr << "sosat\n";
  for (int i = 0; i < q; ++i) {
    cout << "Fou\n";
  }
  exit(0);
}

bool important(int u) {
  return g[u].size() == 2 || u == 0;
}

vector<int> pre(int u) {
  assert((int) g[u].size() <= 2);
  if (g[u].empty()) {
    if (leaves_h == -1) {
      leaves_h = h[u];
    } else if (leaves_h != h[u]) {
      sosat();
    }
  }
  vector<int> res(26);
  for (int i = 0; i < (int) g[u].size(); ++i) {
    int v = g[u][i];
    h[v] = h[u] + 1;
    if (important(u)) {
      up[v] = {u, i};
    } else {
      up[v] = up[u];
    }
    auto arr = pre(v);
    if (sym[v] != '?') {
      arr[sym[v] - 'a']++;
    }
    for (int j = 0; j < 26; ++j) {
      a[u][i][j] = arr[j];
    }
    for (int j = 0; j < 26; ++j) {
      res[j] = max(res[j], arr[j]);
    }
  }
  if (important(u)) {
    deg[u] = leaves_h - h[u] - accumulate(res.begin(), res.end(), 0);
    bad_deg += deg[u] < 0;
  }
  return res;
}

bool update_arr(int u, int i, char sym, int delta) {
  assert(important(u));
  if (sym == '?') {
    return false;
  }
  int c = sym - 'a';
  bad_deg -= deg[u] < 0;
  int vold = max(a[u][i][c], a[u][i ^ 1][c]);
  deg[u] += max(a[u][i][c], a[u][i ^ 1][c]);
  a[u][i][c] += delta;
  int vnew = max(a[u][i][c], a[u][i ^ 1][c]);
  deg[u] -= max(a[u][i][c], a[u][i ^ 1][c]);
  bad_deg += deg[u] < 0;
  return vold != vnew;
}

void do_replace(int u, char from, char to) {
  while (u > 0) {
    int id;
    tie(u, id) = up[u];
    if (!update_arr(u, id, from, -1)) {
      from = '?';
    }
    if (!update_arr(u, id, to, +1)) {
      to = '?';
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int p;
    char c;
    cin >> p >> c;
    --p;
    pr[i] = p;
    g[p].push_back(i);
    sym[i] = c;
  }
  pre(0);
  for (int i = 0; i < q; ++i) {
    int u;
    char c;
    cin >> u >> c;
    --u;
    assert(u > 0);
    do_replace(u, sym[u], c);
    sym[u] = c;
    assert(bad_deg >= 0);
    if (bad_deg > 0) {
      cout << "Fou\n";
    } else {
      ll res = 0;
      for (int c = 0; c < 26; ++c) {
        res += (c + 1) * ll(max(a[0][0][c], a[0][1][c]) + deg[0]);
      }
      cout << "Shi " << res << '\n';
    }
  }
}