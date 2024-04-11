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
const int N = 14, S = 1 << 14 | 5;
int n, a[N], dp[S], f[N][S];
int calc(int st) {
  memset(dp, 0, sizeof dp);
  for (int s = 0; s < 1 << n; ++s) {
    if (!(s >> st & 1)) continue;
    dp[s] = 1;
    for (int t = s & (s - 1); t; t = (t - 1) & s) {
      if (!(t >> st) & 1) continue;
      int coef = 1;
      for (int j = 0; j < n; ++j)
        if ((s ^ t) >> j & 1) mul(coef, f[j][t]);
      sub(dp[s], Mul(dp[t], coef));
    }
  }
  return dp[(1 << n) - 1];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) {
    for (int s = 0; s < 1 << n; ++s) {
      if (s >> i & 1) continue;
      f[i][s] = 1;
      for (int j = 0; j < n; ++j) 
        if (s >> j & 1) mul(f[i][s], power(a[i] + a[j], mod - 2, a[i]));
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) add(ans, calc(i));
  printf("%d\n", ans);
  return 0;
}