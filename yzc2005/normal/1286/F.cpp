#include <bits/stdc++.h>
typedef long long ll;
inline void up(int &x, const int y) {x < y ? x = y : 0;}

const int N = 20, M1 = 1 << 20, M2 = 1 << 10;

int n, m, ans;
ll a[N], b[N], s1[M2], s2[M2];
int f[M1], g[M1], pw[5][M1];
int x[N + 1][M1], y[N + 1][M1], z[N + 1][M1];

inline bool check(int msk) {
  ll sum = 0; m = 0;
  for (int i = 0; i < n; ++i) 
    if (msk >> i & 1) b[m++] = a[i], sum += a[i];
  if ((sum + m) % 2 == 0) return false;
  int n1 = m / 2, n2 = m - n1, t1 = 1 << n1, t2 = 1 << n2;
  s1[0] = s2[0] = 0;
  for (int i = 1, x; i < t1; ++i) 
    x = __builtin_ctz(i), s1[i] = s1[i ^ (1 << x)] + b[x];
  for (int i = 1, x; i < t2; ++i) 
    x = __builtin_ctz(i), s2[i] = s2[i ^ (1 << x)] + b[n1 + x];
  ll L = (sum - --m) / 2, R = (sum + m) / 2;   
  auto in = [&](ll x) {return L <= x && x <= R;};
  for (int i = 1; i < t1; ++i) if (in(s1[i])) return true;
  for (int i = 1; i < t2; ++i) if (in(s2[i])) return true;
  for (int i = 0; i < t1 - 1; ++i) if (in(s2[t2 - 1] + s1[i])) return true;
  for (int i = 0; i < t2 - 1; ++i) if (in(s1[t1 - 1] + s2[i])) return true; 
  std::sort(s1, s1 + t1), std::sort(s2, s2 + t2);
  for (int i = t1 - 2, l = 1, r = 1; i; --i) {
    while (l < t2 && s1[i] + s2[l] < L) ++l;
    while (r < t2 && s1[i] + s2[r] <= R) ++r; // [l, r)
    if (r - l > 0) return true;
  } 
  return false;
}

inline void FMT(int *a) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 1 << n; ++j)
      if (j >> i & 1) a[j] += a[j ^ (1 << i)];
}
inline void IFMT(int *a) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 1 << n; ++j)
      if (j >> i & 1) a[j] -= a[j ^ (1 << i)];
}
inline void Mul(const bool f[], const bool g[], bool *h) {
  memset(x, 0, sizeof(x)), memset(y, 0, sizeof(y)), memset(z, 0, sizeof(z));
  for (int s = 0; s < 1 << n; ++s)
    x[__builtin_popcount(s)][s] = f[s], y[__builtin_popcount(s)][s] = g[s];
  for (int i = 0; i <= n; ++i) FMT(x[i]), FMT(y[i]);
  for (int i = 0; i <= n; ++i)
    for (int s = 0; s < 1 << n; ++s) {
      for (int j = 0; j <= i; ++j)
        z[i][s] += x[j][s] * y[i - j][s];
    }
  for (int i = 0; i <= n; ++i) IFMT(z[i]);
  for (int s = 0; s < 1 << n; ++s) 
    h[s] = bool(z[__builtin_popcount(s)][s]);
} 

int main() {                                 
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]), (!a[i]) && (--n, --i);
  for (int s = 0; s < 1 << n; ++s) 
    if (__builtin_popcount(s) > 1) f[s] = pw[0][s] = check(s);
  for (int s = 0; s < 1 << n; ++s) 
    for (int t = s; t; t = (t - 1) & s) 
      up(f[s], f[t] + f[s ^ t]);
  printf("%d\n", n - f[(1 << n) - 1]);
//  memset(f, 1, sizeof(f));
//  int i = 1, j = 2;
//  for (; j <= n; j <<= 1, ++i) 
//    Mul(pw[i - 1], pw[i - 1], pw[i]);
//  for (--i, j >>= 1; ~i; --i, j >>= 1)
//    if (Mul(f, pw[i], g), std::count(g, g + (1 << n), true)) 
//      memcpy(f, g, sizeof(f)), ans += j;
//  return printf("%d\n", n - ans), 0;
}