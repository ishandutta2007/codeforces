#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int mod = 1e9 + 7;
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

const int maxn = 4000100;
int res[maxn];
int delta[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n >> mod;
  res[1] = 1;
  int sum = 0;
  int bal = 0;
  for (int i = 1; i <= n; ++i) {
    udd(bal, delta[i]);
    udd(res[i], bal);
    udd(res[i], sum);
    for (int a = 2; i * a <= n; ++a) {
      udd(delta[i * a], res[i]);
      if ((i + 1) * a <= n) {
        uub(delta[(i + 1) * a], res[i]);
      }
    }
    udd(sum, res[i]);
  }
  cout << res[n] << '\n';
}