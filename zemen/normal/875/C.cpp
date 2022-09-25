#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> s[maxn];
bool bad[maxn];
bool used[maxn];
vector<int> g[maxn];

void dfs(int u) {
  used[u] = true;
  for (int v : g[u]) {
    if (used[v])
      continue;
    bad[v] = true;
    dfs(v);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int len;
    cin >> len;
    for (int j = 0; j < len; ++j) {
      int x;
      cin >> x;
      --x;
      s[i].push_back(x);
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int len = min(int(s[i].size()), int(s[i + 1].size()));
    bool eq = true;
    for (int j = 0; j < len; ++j) {
      if (s[i][j] != s[i + 1][j]) {
        eq = false;
        if (s[i][j] > s[i + 1][j]) {
          bad[s[i][j]] = true;
        }
        g[s[i + 1][j]].push_back(s[i][j]);
        break;
      }
    }
    if (eq && int(s[i].size()) > int(s[i + 1].size())) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (!used[i] && bad[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int len = min(int(s[i].size()), int(s[i + 1].size()));
    for (int j = 0; j < len; ++j) {
      if (s[i][j] != s[i + 1][j]) {
        if (bad[s[i + 1][j]] && !bad[s[i][j]]) {
          cout << "No\n";
          return 0;
        }
        if (bad[s[i + 1][j]] == bad[s[i][j]] && s[i][j] > s[i + 1][j]) {
          cout << "No\n";
          return 0;
        }
        break;
      }
    }
  }
  cout << "Yes\n";
  vector<int> res;
  for (int i = 0; i < m; ++i) {
    if (bad[i]) {
      res.push_back(i);
    }
  }
  cout << int(res.size()) << '\n';
  for (int x : res)
    cout << x + 1 << ' ';
  cout << '\n';
}