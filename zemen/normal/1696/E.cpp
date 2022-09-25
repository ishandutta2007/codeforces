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

const int M = 1e6;
vector<int> fac(M, 1), ifac(M, 1);

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i < M; ++i) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = inv(fac[i]);
  }

  int n;
  cin >> n;
  ++n;
  vector<int> a(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 0) {
      continue;
    }
    int cur = mul(fac[a[i] + i], ifac[i + 1], ifac[a[i] - 1]);
    //cerr << cur << '\n';
    udd(res, cur);
  }
  cout << res << '\n';
}