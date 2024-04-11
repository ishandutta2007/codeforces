#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 300300;
int a[maxn];
pair<int, int> d[maxn][2][2];
int n;

const int inf = 1e9;

void uin(pair<int, int>& a, pair<int, int> b) {
  a = min(a, b);
}

bool check(int init) {
  for (int iter = 0; iter < 2; ++iter) {
    for (int i = 0; i < maxn; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          d[i][j][k] = {inf, 0};
        }
      }
    }
    int mm = init / 10;
    int smm = init % 10;
    if (iter) {
      smm += 10;
      --mm;
      if (mm < 0) {
        continue;
      }
    }

    d[0][mm % 2][1] = {mm, 0};
    for (int i = 0; i < n; ++i) {
      for (int rem = 0; rem < 2; ++rem) {
        for (int sp = 0; sp < 2; ++sp) {
          if (d[i][rem][sp].first == inf)
            continue;
          int mm = d[i][rem][sp].first;
          int bonus = d[i][rem][sp].second;
          assert(mm % 2 == rem);
          if (mm >= a[i] / 10) {
            uin(d[i + 1][(mm - a[i] / 10) % 2][sp], {mm - a[i] / 10, bonus + a[i] / 10});
          }
          if (bonus >= a[i]) {
            uin(d[i + 1][rem][sp], {mm, bonus - a[i]});
          }
          if (sp && bonus >= (a[i] - smm)) {
            uin(d[i + 1][rem][0], {mm, bonus - (a[i] - smm)});
          }
        }
      }
    }
    for (int rem = 0; rem < 2; ++rem) {
      for (int sp = 0; sp < 2; ++sp) {
        if (d[n][rem][sp].first != inf)
          return true;
      }
    }
  }
  return false;
}

namespace Naive {
const int maxn = 1000;
int d[maxn][maxn];

template<typename T>
void uin(T& a, T b) {
  a = min(a, b);
}

int naive() {
  for (int i = 0; i <= n; ++i) {
    for (int b = 0; b < maxn; ++b) {
      d[i][b] = inf;
    }
  }
  d[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < maxn; ++b) {
      if (d[i][b] == inf)
        continue;
      for (int c = 0; c <= a[i]; ++c) {
        if (c > b)
          continue;
        int nb = c > 0 ? 0 : a[i] / 10;
        uin(d[i + 1][b + nb - c], d[i][b] + (a[i] - c));
      }
    }
  }
  int res = inf;
  for (int i = 0; i < maxn; ++i) {
    uin(res, d[n][i]);
  }
  return res;
}
} // namespace Naive

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] /= 100;
  }

  int L = 0, R = 20 * n;
  while (L + 1 < R) {
    int C = (L + R) / 2;
    if (check(C))
      R = C;
    else
      L = C;
  }
#ifdef LOCAL
  int real = Naive::naive();
  cerr << "real " << real * 100 << '\n';
  cerr << "mine " << R * 100 << '\n';
  assert(real == R);
#endif
  cout << R * 100 << '\n';
}