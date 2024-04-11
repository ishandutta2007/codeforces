#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
const int N = 1e6 + 5;
int n, g[N][3], f[3], p[10];
inline void upd(int *f, int *g) {
  f[2] = Add(Mul(f[2], g[0]), Add(Mul(g[2], f[0]), Mul(2, Mul(f[1], g[1]))));
  f[1] = Add(Mul(f[1], g[0]), Mul(g[1], f[0]));
  mul(f[0], g[0]);
}
inline int get(int j, int i) {
  while (1) {
    if (!j) return i % 10;
    i /= 10, --j;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 1000000; ++i) g[i][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x; scanf("%d", &x);
    f[0] = 2, f[1] = x, f[2] = Mul(x, x);
    upd(g[x], f);
  }
  p[0] = 1; for (int i = 1; i <= 5; ++i) p[i] = Mul(p[i - 1], 10);
  for (int i = 0; i < 6; ++i)
    for (int j = 999999; ~j; --j)
      if (get(i, j) != 9) upd(g[j], g[j + p[i]]);
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 1000000; ++j)
      if (get(i, j) != 9) sub(g[j][2], g[j + p[i]][2]);
  long long ans = 0;
  for (int i = 0; i < 1000000; ++i) ans ^= 1ll * i * g[i][2];
  printf("%lld\n", ans);
  return 0;
}