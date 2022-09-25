#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

const int maxn = 300300;
int d[maxn];
vector<pair<int, int>> g[maxn];

vector<int> res;
bool inset[maxn];

bool used[maxn];
int dfs(int u) {
  used[u] = true;
  int ret = d[u] == 1;
  for (auto p : g[u]) {
    int v, id;
    tie(v, id) = p;
    if (used[v])
      continue;
    int cur = dfs(v);
    if (cur % 2) {
      res.push_back(id);
      inset[id] = true;
    }
    ret += cur;
  }
  return ret;
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  bool odd = false;
  forn (i, n) {
    scanf("%d", &d[i]);
    if (d[i] == 1)
      odd ^= 1;
  }
  forn (i, n) {
    if (odd && d[i] == -1) {
      d[i] = 1;
      odd ^= 1;
    }
  }
  if (odd) {
    cout << -1 << '\n';
    return 0;
  }
  forn (i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }
  dfs(0);
  cout << sz(res) << '\n';
  for (int id : res)
    cout << id + 1 << '\n';
}