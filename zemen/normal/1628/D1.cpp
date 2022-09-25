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

const int inv2 = (mod + 1) / 2;
const int N = 2005;
int d[N][N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << mul(d[n][m], k) << '\n';
}

void pre() {
  for (int n = 0; n < N; ++n) {
    d[n][n] = n;
    for (int m = 1; m < n; ++m) {
      d[n][m] = mul(inv2, add(d[n - 1][m - 1], d[n - 1][m]));
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  pre();

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}