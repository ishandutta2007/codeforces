#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> g[maxn];
vector<int> orig;
string s;

int rec(int l, int r, int pos) {
  if (r - l <= 1 || pos == -1) {
    return pos;
  }
  int m = (l + r) / 2;
  pos = rec(l, m, pos);
  pos = rec(m, r, pos);
  if (pos == -1) {
    return pos;
  }

  int lp = l, rp = m;
  vector<int> nv;
  nv.reserve(r - l);
  while (pos < (int) s.size() && lp < m && rp < r) {
    if (s[pos] == '0') {
      g[orig[rp]].push_back(orig[lp]);
      nv.push_back(orig[lp]);
      ++lp;
    } else {
      g[orig[lp]].push_back(orig[rp]);
      nv.push_back(orig[rp]);
      ++rp;
    }
    ++pos;
  }
  if (lp < m && rp < r) {
    return -1;
  }
  while (lp < m) {
    nv.push_back(orig[lp]);
    ++lp;
  }
  while (rp < r) {
    nv.push_back(orig[rp]);
    ++rp;
  }
  assert((int) nv.size() == r - l);
  for (int i = 0; i < r - l; ++i) {
    orig[i + l] = nv[i];
  }
  return pos;
}

int ptr = 1;
vector<int> p;
vector<char> used;

void dfs(int u) {
  used[u] = true;
  for (int v : g[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }
  p[u] = ptr++;
}

bool try_n(int n) {
  orig.resize(n);
  iota(orig.begin(), orig.end(), 0);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  int to = rec(0, n, 0);
  if (to == (int) s.size()) {
    cout << n << '\n';
    p.resize(n, -1);
    used.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        dfs(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << p[i] << ' ';
    }
    cout << '\n';
    exit(0);
  }
  return to == -1;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  cin >> s;
  int l = 0, r = maxn;
  while (l + 1 < r) {
    int c = (l + r) / 2;
    if (try_n(c)) {
      r = c;
    } else {
      l = c;
    }
  }
  for (int d = 0; ; ++d) {
    for (int c : {l - d, l + d}) {
      if (c > 0 && c < maxn) {
        try_n(c);
      }
    }
  }
}