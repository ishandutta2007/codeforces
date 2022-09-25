#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 2019;
using Mask = bitset<maxn>;
Mask g[maxn];
Mask unused;
vector<int> ord;
int n;

void flip_v(int u) {
  for (int i = 0; i < n; ++i) {
    if (u != i) {
      g[u][i].flip();
      g[i][u].flip();
    }
  }
}

void dfs(int u) {
  unused[u] = 0;
  while (true) {
    int v = (g[u] & unused)._Find_first();
    if (v >= n) {
      break;
    }
    dfs(v);
  }
  ord.push_back(u);
}

void dfs2(int u, vector<vector<int>>& comps) {
  unused[u] = 0;
  comps.back().push_back(u);
  while (true) {
    int v = (~g[u] & unused)._Find_first();
    if (v >= n) {
      break;
    }
    dfs2(v, comps);
  }
}

void topsort() {
  for (int i = 0; i < n; ++i) {
    unused[i] = 1;
  }
  ord.clear();
  for (int i = 0; i < n; ++i) {
    if (unused[i]) {
      dfs(i);
    }
  }
  reverse(ord.begin(), ord.end());
}

vector<vector<int>> get_comps() {
  topsort();
  for (int i = 0; i < n; ++i) {
    unused[i] = 1;
  }
  vector<vector<int>> comps;
  for (int u : ord) {
    if (unused[u]) {
      comps.emplace_back();
      dfs2(u, comps);
    }
  }
  return comps;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '1') {
        g[i][j] = 1;
      }
    }
  }
  auto comps = get_comps();
  if (comps.size() == 1) {
    cout << "0 1\n";
    return 0;
  }
  int res = 0;
  for (int u = 0; u < n; ++u) {
    flip_v(u);
    if (get_comps().size() == 1) {
      ++res;
    }
    flip_v(u);
  }
  if (res == 0) {
    assert(comps.size() == 2);
    if (comps[0].size() == 3 && comps[1].size() == 3) {
      cout << "2 18\n";
    } else if (comps[0].size() == 1 && comps[1].size() == 3) {
      cout << "-1\n";
    } else if (comps[0].size() == 3 && comps[1].size() == 1) {
      cout << "-1\n";
    } else {
      //assert(false);
    }
  } else {
    cout << 1 << ' ' << res << '\n';
  }
}