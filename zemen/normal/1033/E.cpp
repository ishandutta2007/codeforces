#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 605;
vector<int> g[maxn];
int col[maxn];
bool used[maxn];
int n, m;

bool G[maxn][maxn];

int qs = 0;
int ask(vector<int> s) {
  assert(++qs <= 20000);
  set<int> ss;
  for (int x : s) {
    assert(0 <= x && x < n);
    assert(ss.insert(x).second);
  }
  cout << "? " << (int) s.size() << endl;
  for (int i = 0; i < (int) s.size(); ++i) {
    if (i) {
      cout << ' ';
    }
    cout << s[i]+1;
  }
  cout << endl;
#ifdef LOCAL
  int es = 0;
  for (int i = 0; i < (int) s.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      int u = s[i], v = s[j];
      es += G[u][v];
    }
  }
  return es;
#else
  int x;
  cin >> x;
  return x;
#endif
}

void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

vector<int> dfs(int u, int t, int prev = -1) {
  if (u == t) {
    return {t};
  }
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    auto p = dfs(v, t, u);
    if (!p.empty()) {
      p.push_back(u);
      return p;
    }
  }
  return {};
}

void suck(int a, int b, int c) {
  auto p = dfs(a, b);
  p.push_back(c);
  cout << "N " << (int) p.size() << endl;
  for (auto x : p) {
    cout << x+1 << ' ';
  }
  cout << endl;
  exit(0);
}

void addv() {
  vector<int> usd, rest;
  for (int v = 0; v < n; ++v) {
    if (used[v]) {
      usd.push_back(v);
    } else {
      rest.push_back(v);
    }
  }

  int musd = ask(usd);
#ifdef LOCAL
  int cnt = m - musd - ask(rest);
  assert(cnt > 0);
#endif

  while ((int) rest.size() > 1) {
    int m = (int) rest.size() / 2;
    vector<int> ra(rest.begin() + m, rest.end());
    rest.resize(m);
    vector<int> p = rest;
    for (auto x : usd) {
      p.push_back(x);
    }
    if (ask(p) - musd - ask(rest) == 0) {
      rest = ra;
    }
  }
  int v = rest[0];
  used[v] = true;
  cerr << "add " << v << endl;

  vector<int> s[2];
  for (int x : usd) {
    s[col[x]].push_back(x);
  }
  vector<int> to;
  for (int q : {0, 1}) {
    s[q].push_back(v);
    int cnt = ask(s[q]);
    s[q].pop_back();
    if (cnt == 0) {
      continue;
    }
    while ((int) s[q].size() > 1) {
      int m = (int) s[q].size() / 2;
      vector<int> ra(s[q].begin() + m, s[q].end());
      s[q].resize(m);
      s[q].push_back(v);
      int cnt = ask(s[q]);
      s[q].pop_back();
      if (cnt == 0) {
        s[q] = ra;
      }
    }
    to.push_back(s[q][0]);
  }
  assert((int) to.size() > 0);
  if ((int) to.size() == 2) {
    suck(to[0], to[1], v);
  } else {
    add_edge(to[0], v);
    col[v] = col[to[0]] ^ 1;
  }
}

signed main() {
#ifdef LOCAL
  n = 600;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i % 2 != j % 2) {
        G[i][j] = G[j][i] = 1;
      }
    }
  }
  G[295][297] = G[297][295] = 1;
#else
  cin >> n;
#endif

  vector<int> vall(n);
  iota(vall.begin(), vall.end(), 0);
  m = ask(vall);

  used[0] = true;
  for (int iter = 0; iter < n - 1; ++iter) {
    addv();
  }

  vector<int> c0;
  for (int i = 0; i < n; ++i) {
    if (col[i] == 0) {
      c0.push_back(i);
    }
  }
  cout << "Y " << (int) c0.size() << endl;
  for (auto p : c0) {
    cout << p+1 << ' ';
  }
  cout << endl;
  cerr << "qs: " << qs << endl;
}