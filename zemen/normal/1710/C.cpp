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

const int maxn = 200200;
int d[maxn][8][8];

bool bit(int mask, int i) {
  return mask & (1 << i);
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> tbig(8, 7);
  for (int dig = 1; dig < 7; ++dig) {
    int xall = bit(dig, 0) ^ bit(dig, 1) ^ bit(dig, 2);
    for (int b = 0; b < 3; ++b) {
      int cur = bit(dig, b) ^ xall;
      if (!cur) {
        tbig[dig] ^= 1 << b;
      }
    }
  }

  string s;
  cin >> s;
  //mt19937 rnd(1337);
  //s.resize(200000);
  //for (int i = 0; i < (int) s.size(); ++i) {
    //s[i] = rnd() % 2 + '0';
  //}

  d[0][7][7] = 1;
  for (int i = 0; i < (int) s.size(); ++i) {
    for (int en = 0; en < 8; ++en) {
      for (int big = 0; big < 8; ++big) {
        if (d[i][en][big] == 0) {
          continue;
        }
        int cur = s[i] - '0';
        for (int dig = 0; dig < 8; ++dig) {
          if (!cur && (dig & en)) {
            continue;
          }
          int nen = cur ? (en & dig) : en;
          int nbig = big & tbig[dig];
          udd(d[i + 1][nen][nbig], d[i][en][big]);
        }
      }
    }
  }
  int res = 0;
  for (int en = 0; en < 8; ++en) {
    udd(res, d[(int) s.size()][en][0]);
  }
  cout << res << '\n';
}