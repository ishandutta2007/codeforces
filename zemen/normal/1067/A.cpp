#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 998244353;
template<typename T>
T add(T x) {
  return x;
}
template<typename T, typename... Ts>
T add(T x, Ts... y) {
  T res = x + add(y...);
  if (res >= mod)
    res -= mod;
  return res;
}
template<typename T, typename... Ts>
T sub(T x, Ts... y) {
  return add(x, mod - add(y...));
}
template<typename T, typename... Ts>
void udd(T& x, Ts... y) {
  x = add(x, y...);
}
template<typename T, typename... Ts>
void uub(T& x, Ts... y) {
  x = sub(x, y...);
}
template<typename T>
T mul(T x) {
  return x;
}
template<typename T, typename... Ts>
T mul(T x, Ts... y) {
  return (x * 1ll * mul(y...)) % mod;
}
template<typename T, typename... Ts>
void uul(T& x, Ts... y) {
  x = mul(x, y...);
}
int bin(int a, ll deg) {
  int r = 1;
  while (deg) {
    if (deg & 1)
      uul(r, a);
    deg >>= 1;
    uul(a, a);
  }
  return r;
}
int inv(int x) {
  assert(x);
  return bin(x, mod - 2);
}

const int B = 200;
int d[2][B+1][2];

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  int q = 0;
  d[0][0][1] = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    memset(d[q ^ 1], 0, sizeof(d[q ^ 1]));
    int tot[2] = {0, 0};
    for (int y = 0; y <= B; ++y) {
      for (int w : {0, 1}) {
        udd(tot[w], d[q][y][w]);
      }
    }
    int cur[2] = {0, 0};
    for (int y = 0; y <= B; ++y) {
      d[q ^ 1][y][1] = add(sub(tot[1], cur[1]), d[q][y][0]);
      d[q ^ 1][y][0] = add(cur[0], cur[1]);
      udd(cur[0], d[q][y][0]);
      udd(cur[1], d[q][y][1]);
    }
    d[q ^ 1][0][0] = d[q ^ 1][0][1] = 0;
    if (x != -1) {
      for (int i = 0; i <= B; ++i) {
        if (i != x) {
          d[q ^ 1][i][0] = d[q ^ 1][i][1] = 0;
        }
      }
    }

    q ^= 1;
  }
  int res = 0;
  for (int i = 1; i <= B; ++i) {
    udd(res, d[q][i][1]);
  }
  cout << res << '\n';
}