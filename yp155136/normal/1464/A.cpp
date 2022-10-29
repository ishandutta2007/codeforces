#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

vector<int> G[N];
int deg[N];
bool vis[N];

void go() {
  int n, m; cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    deg[i] = 0;
    G[i].clear();
    vis[i] = false;
  }
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
    ++deg[y];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      // cerr << "here i = " << i << endl;
      int sz = 1;
      int _ = i;
      vis[i] = true;
      while (G[_].size() == 1) {
        _ = G[_][0];
        ++sz;
        vis[_] = true;
      }
      ans += (sz - 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i] && G[i].size() == 1) {
      if (G[i][0] == i) continue;
      // cycle
      vis[i] = true;
      int sz = 1;
      int _ = G[i][0];
      while (_ != i) {
        vis[_] = true;
        _ = G[_][0];
        ++sz;
      }
      ans += (sz + 1);
      // cerr << "i = " << i << " , sz = " << sz << endl;
    }
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}