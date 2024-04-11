#include <bits/stdc++.h>
const int mod = 998244353;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
inline int power(int a, int b, int c = 1) {
  for (; b; b >>= 1, mul(a, a))
    if (b & 1) mul(c, a);
  return c;
}
const int N = 200005;
int n, inv[N], fac[N], ifac[N];
inline void init(int n) {
  for (int i = 0; i < 2; ++i) inv[i] = fac[i] = ifac[i] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = Mul(mod - mod / i, inv[mod % i]);
    fac[i] = Mul(fac[i - 1], i);
    ifac[i] = Mul(ifac[i - 1], inv[i]);
  }
}
inline int binom(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return Mul(fac[n], Mul(ifac[m], ifac[n - m]));
}
char s[N];
int a[N];
void solve() {
  scanf("%d%s", &n, s + 1);
  int m = 0, ans = 0, t = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') a[++m] = t;
    else ++t;
  }
  a[++m] = t;
  for (int i = m; i; --i) a[i] -= a[i - 1], a[i] /= 2;
  int tmp = std::accumulate(a + 1, a + m + 1, 0);
  ans = binom(tmp + m - 1, m - 1);
  printf("%d\n", ans);
}
int main() { 
  init(N - 1); int t;
  for (scanf("%d", &t); t; --t) solve();
  return 0;
}