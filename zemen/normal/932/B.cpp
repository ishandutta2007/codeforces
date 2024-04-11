#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll calc_f(ll x) {
  ll res = 1;
  while (x) {
    ll d = x % 10;
    if (d) {
      res *= d;
    }
    x /= 10;
  }
  return res;
}

const int maxn = 1001000;
int g[maxn];
int cnt[maxn][10];

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  for (int i = 0; i < 10; ++i) {
    g[i] = i;
  }
  const int C = 1e6 + 10;
  for (int i = 10; i < C; ++i) {
    int j = calc_f(i);
    assert(j < i);
    g[i] = g[j];
  }
  for (int i = 0; i < C; ++i) {
    for (int j = 0; j < 10; ++j) {
      cnt[i + 1][j] = cnt[i][j] + (g[i] == j);
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    ++r;
    cout << cnt[r][k] - cnt[l][k] << '\n';
  }
}