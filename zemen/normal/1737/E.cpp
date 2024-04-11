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

const int inv2 = inv(2);

void solve() {
  int n;
  cin >> n;
  vector<int> p(n + 1), psum(n * 2 + 2);
  for (int i = n; i > 0; --i) {
    int deg = (i + 1) / 2;
    if (i == n) {
      --deg;
    }
    p[i] = bin(inv2, deg);
    uul(p[i], sub(1, psum[i * 2]));
    psum[i] = add(psum[i + 1], p[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << p[i + 1] << '\n';
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    solve();
  }
}