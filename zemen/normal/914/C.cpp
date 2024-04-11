#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
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
void udd(T &x, Ts... y) {
  x = add(x, y...);
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
void uul(T &x, Ts... y) {
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

const int maxn = 1005;
int d[maxn][maxn][2];

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  string s;
  int K;
  cin >> s >> K;
  if (K == 0) {
    cout << 1 << '\n';
    return 0;
  }
  d[0][0][1] = 1;
  for (int i = 0; i < (int) s.size(); ++i) {
    for (int j = 0; j <= (int) s.size(); ++j) {
      for (int eq = 0; eq < 2; ++eq) {
        for (int dig = 0; dig < 2; ++dig) {
          int cdig = s[i] - '0';
          if (dig > cdig && eq)
            continue;
          int neq = eq && dig == cdig;
          udd(d[i + 1][j + dig][neq], d[i][j][eq]);
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= (int) s.size(); ++i) {
    int x = i;
    int k = 1;
    while (x > 1) {
      int y = 0;
      while (x) {
        if (x & 1) {
          ++y;
        }
        x >>= 1;
      }
      x = y;
      ++k;
    }
    if (k == K) {
      //cerr << "num: " << i << '\n';
      udd(res, d[(int) s.size()][i][0]);
      udd(res, d[(int) s.size()][i][1]);
    }
  }
  if (K == 1) {
    udd(res, mod - 1);
  }
  cout << res << '\n';
}