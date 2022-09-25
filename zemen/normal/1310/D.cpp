#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxk = 11;
const int maxn = 85;

int a[maxn][maxn];
vector<int> p[2];
int d[maxk][maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  mt19937 rnd{random_device{}()};
  int res = 2e9;
  for (int it = 0; it < 40000; ++it) {
    p[0].clear();
    p[1].clear();
    for (int i = 0; i < n; ++i) {
      int s = i == 0 ? 0 : rnd() % 2;
      p[s].push_back(i);
    }
    for (int i = 0; i <= k; ++i) {
      fill(d[i], d[i] + n, int(2e9));
    }
    d[0][0] = 0;
    for (int i = 0; i < k; ++i) {
      for (int u : p[i % 2]) {
        for (int v : p[(i + 1) % 2]) {
          d[i + 1][v] = min(d[i + 1][v], d[i][u] + a[u][v]);
        }
      }
    }
    res = min(res, d[k][0]);
  }
  cout << res << '\n';
}