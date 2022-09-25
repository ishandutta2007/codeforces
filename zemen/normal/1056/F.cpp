#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
const ld inf = 1e18;

const int maxn = 105;
const int maxp = maxn * 10;
ld d[maxn][maxp];
vector<pair<ld, int>> a;

void solve() {
  int n;
  ld C, T;
  cin >> n >> C >> T;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= 10 * n; ++j) {
      d[i][j] = inf;
    }
  }
  d[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int cn = i; cn >= 0; --cn) {
      for (int p = 0; p <= cn * 10; ++p) {
        if (d[cn][p] == inf) {
          continue;
        }
        ld& to = d[cn + 1][p + a[i].second];
        to = min(to, (d[cn][p] + a[i].first) / 0.9);
      }
    }
  }

  for (int p = 10 * n; p >= 0; --p) {
    for (int cn = 0; cn <= n; ++cn) {
      ld D = d[cn][p];
      if (D == inf) {
        continue;
      }
      ld t0 = (sqrt(D * C) - 1) / C;
      t0 = max(t0, 0.);
      ld t = D / (1 + C * t0) + t0 + 10 * cn;
      if (t <= T) {
        //cerr << D << ' ' << t0 << ' ' << t << '\n';
        cout << p << '\n';
        return;
      }
    }
  }
  assert(false);
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}