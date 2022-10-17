#include <bits/stdc++.h>
#define ctz __builtin_ctz
#define pop __builtin_popcountll 
typedef long long ll;
const int N = 65, mod = 998244353;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
inline int power(int a, int b, int c = 1) {for (b += b >> 31 & (mod - 1); b; b >>= 1, mul(a, a)) if (b & 1) mul(c, a); return c;}
int inv[N], fac[N], ifac[N];
inline void init() {
  for (int i = 0; i < 2; ++i) inv[i] = fac[i] = ifac[i] = 1;
  for (int i = 2; i < N; ++i) 
    inv[i] = Mul(mod - mod / i, inv[mod % i]),
    fac[i] = Mul(fac[i - 1], i),
    ifac[i] = Mul(ifac[i - 1], inv[i]);
}
inline int binom(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return Mul(fac[n], Mul(ifac[m], ifac[n - m]));
}
int n, m, rank, o[N], ans[N];
ll x, a[N], b[N];
inline bool insert(ll x) {
  for (int i = m - 1; ~i; --i) if (x >> i & 1) {
    if (!b[i]) return b[i] = x, o[rank++] = i;
    else x ^= b[i];
  }
  return false;
} 
inline void normalize() {
  for (int i = 0; i < m; ++i) 
    for (int j = 0; j < i; ++j) 
      if (b[i] >> j & 1) b[i] ^= b[j];
}
inline int g(int i, int j) {
  int ans = 0;
  for (int k = 0, x; k <= j; ++k) 
    x = Mul(binom(j, k), binom(m - j, i - k)), (k & 1) ? sub(ans, x) : add(ans, x);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m), init();
  for (int i = 1; i <= n; ++i) scanf("%lld", &x), insert(x);
  if (rank <= m / 2) {
    x = 0; for (int i = 0, j = 1 << rank; i < j; x ^= b[o[ctz(++i)]]) ++ans[pop(x)];
    int coef = power(2, n - rank);
    for (int i = 0; i <= m; ++i) printf("%d ", Mul(ans[i], coef));
  } else {
    int cnt = 0; normalize();
    for (int i = 0; i < m; ++i) if (!b[i]) {
      for (int j = 0; j < rank; ++j) 
        if (b[o[j]] >> i & 1) a[cnt] |= 1ll << j;
      ++cnt;
    }
    x = 0; for (int i = 0, j = 1 << cnt, pc = 0; i < j; x ^= a[ctz(i)]) 
      ++ans[pop(x) + pc], ++i, i >> ctz(i) & 2 ? --pc : ++pc;
    int coef = power(2, n - m);
    for (int i = 0; i <= m; ++i) {
      int res = 0;
      for (int j = 0; j <= m; ++j) add(res, Mul(ans[j], g(i, j)));
      printf("%d ", Mul(res, coef));
    }
  }
  return 0;
}