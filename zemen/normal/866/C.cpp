#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

const int maxn = 55;
const int maxs = maxn * 100;
int f[maxn];
int s[maxn];
ld p[maxn];
ld d[maxn][maxs];

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n, r;
  cin >> n >> r;
  for (int i = 0; i < n; ++i) {
    cin >> f[i] >> s[i] >> p[i];
    p[i] *= 1e-2;
  }
  ld L = 0;
  ld R = 1e20;
  for (int iter = 0; iter < 110; ++iter) {
    ld e = (L + R) / 2;
    for (int i = 0; i <= r; ++i)
      d[n][i] = 0;
    for (int i = r + 1; i < maxs; ++i) {
      d[n][i] = e;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int t = 0; t + s[i] < maxs; ++t) {
        ld t1 = d[i + 1][t + f[i]] + f[i];
        ld t2 = d[i + 1][t + s[i]] + s[i];
        d[i][t] = p[i] * t1 + (1 - p[i]) * t2;
        if (i > 0)
          d[i][t] = min(d[i][t], e);
      }
    }
    cerr << d[0][0] << ' ' << e << '\n';
    if (d[0][0] > e) {
      L = e;
      //cerr << "sos\n";
    } else {
      R = e;
      //cerr << "ok\n";
    }
  }
  cout << fixed;
  cout.precision(15);
  cout << (L + R) / 2 << '\n';
}