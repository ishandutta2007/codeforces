#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 500500;
vector<int> g[maxn];
int n;
string s;

bool calc() {
  if (n <= 2) {
    return true;
  }
  if (n == 3) {
    int c = 0;
    for (int j = 0; j < n; ++j) {
      c += s[j] == 'W';
    }
    return c < 2;
  }
  vector<int> twin(n, -1);
  set<int> tws;
  for (int i = 0; i < n; ++i) {
    if ((int) g[i].size() > 3) {
      return false;
    }
    if ((int) g[i].size() == 3) {
      vector<int> c;
      for (int v : g[i]) {
        if ((int) g[v].size() <= 1) {
          c.push_back(v);
        }
      }
      if ((int) c.size() <= 1) {
        return false;
      }
      twin[c[1]] = c[0];
      tws.insert(c[1]);
    }
  }
  assert((int) tws.size() <= 2);
  vector<int> ends;
  for (int i = 0; i < n; ++i) {
    if (twin[i] == -1 && (int) g[i].size() == 1) {
      ends.push_back(i);
    }
  }
  assert((int) ends.size() == 2);
  int u = ends[0];
  vector<char> a{s[u] == 'W'};
  int prev = -1;
  while (u != ends[1]) {
    vector<int> to;
    for (int v : g[u]) {
      if (twin[v] != -1 || v == prev) {
        continue;
      }
      to.push_back(v);
    }
    assert((int) to.size() == 1);
    prev = u;
    u = to[0];
    a.push_back(s[u] == 'W');
  }
  for (int i = 0; i < n; ++i) {
    if (twin[i] != -1) {
      assert(twin[i] == ends[0] || twin[i] == ends[1]);
      int id = twin[i] == ends[0] ? 0 : (int) a.size() - 1;
      if (s[i] == 'W' || a[id] == 1) {
        return false;
      }
      a[id] = 2;
    }
  }

  n = (int) a.size();
  assert(n >= 3);
  //for (int i = 0; i < n; ++i) {
    //cerr << int(a[i]);
  //}
  //cerr << '\n';
  for (int i = 1; i < n - 1; ++i) {
    if (a[i]) {
      return false;
    }
  }
  if ((n % 2) && a[0] && a[n - 1]) {
    return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin >> s;

  bool res = calc();
  cout << (res ? "Draw" : "White") << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}