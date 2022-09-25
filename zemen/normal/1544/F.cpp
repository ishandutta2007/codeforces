#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 31607;
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
  return (x * mul(y...)) % mod;
}
template<typename T, typename... Ts>
void uul(T& x, Ts... y) {
  x = mul(x, y...);
}
int bin(int a, int deg) {
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

const int maxn = 22;

int n;
int a[maxn][maxn];
int inva[maxn][maxn];

int used[maxn][maxn];
int prod[maxn];
int res = 0;

void rec(int depth, int sgn, int p) {
  if (depth == n + 2) {
    //cerr << "p: " << p << " sgn: " << sgn << '\n';
    //for (int i = 0; i < n; ++i) {
      //cerr << prod[i] << ' ';
    //}
    //cerr << '\n';
    int w0 = sgn ? 0 : p, w1 = sgn ? p : 0;
    for (int i = 0; i < n; ++i) {
      int w01 = mul(w0, prod[i]);
      int w10 = mul(w1, prod[i]);
      udd(w0, w10);
      udd(w1, w01);
    }
    res = (res + w0 - w1) % mod;
    return;
  }
  rec(depth + 1, sgn, p);
  for (int i = 0; i < n; ++i) {
    int j = depth;
    if (depth == n) {
      j = i;
    } else if (depth == n + 1) {
      j = n - 1 - i;
    }
    if (used[i][j]++ == 0) {
      uul(p, a[i][j]);
      uul(prod[i], inva[i][j]);
    }
  }
  rec(depth + 1, !sgn, p);
  for (int i = 0; i < n; ++i) {
    int j = depth;
    if (depth == n) {
      j = i;
    } else if (depth == n + 1) {
      j = n - 1 - i;
    }
    if (--used[i][j] == 0) {
      uul(prod[i], a[i][j]);
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  const int den = inv(1e4);
  cin >> n;
  //n = 21;
  //mt19937 rnd(1337);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      //a[i][j] = rnd() % 9999 + 1;
      uul(a[i][j], den);
    }
  }
  for (int i = 0; i < n; ++i) {
    prod[i] = 1;
    for (int j = 0; j < n; ++j) {
      inva[i][j] = inv(a[i][j]);
      uul(prod[i], a[i][j]);
    }
  }
  rec(0, 0, 1);
  res = (1 - res) % mod;
  cout << (res + mod) % mod << '\n';
}