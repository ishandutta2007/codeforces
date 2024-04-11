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

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int A = 1;
  vector<int> p(n + 1);
  p[0] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    uul(A, a[i]);
    vector<int> np(n + 1);
    for (int j = 0; j <= n; ++j) {
      np[j] = mul(p[j], a[i]);
      if (j) {
        np[j] = sub(np[j], p[j - 1]);
      }
    }
    p = np;
  }
  int B = 0;
  int pw = bin(n, k);
  int in = inv(n);
  int fact = 1;
  for (int j = 0; j <= n; ++j) {
    udd(B, mul(fact, pw, p[j]));
    uul(pw, in);
    uul(fact, k - j);
  }
  uul(B, inv(bin(n, k)));
  cout << sub(A, B) << '\n';
}