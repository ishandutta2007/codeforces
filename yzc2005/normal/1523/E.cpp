#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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
const int N = (1 << 18) + 5;
int inv[N], fac[N], ifac[N];
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
int t, n, k;
void solve() {
  int ans = 0; 
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    if ((k - 1) * (i - 1) > n) break;
    int res = binom(n - (k - 1) * (i - 1), i);
    add(ans, Mul(res, Mul(fac[i], fac[n - i])));
  } 
  printf("%d\n", Mul(ans, ifac[n]) + 1);
} 
int main() {
  init(N - 1);
  for (scanf("%d", &t); t; --t) solve();
  return 0;
}