#include <bits/stdc++.h>
using namespace std;
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
inline void dft(int *a, int n) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i < j) swap(a[i], a[j]);
    for (int k = n >> 1; (j ^= k) < k; k >>= 1);
  }
  for (int k = 1; k < n; k <<= 1) {
    int wn = power(3, (mod - 1) / (k << 1));
    for (int i = 0; i < n; i += k << 1)
      for (int w = 1, j = 0; j < k; ++j, mul(w, wn)) {
        int tmp = Mul(w, a[i + j + k]);
        a[i + j + k] = Sub(a[i + j], tmp);
        add(a[i + j], tmp);
      }
  }
}
inline void idft(int *a, int n) {
  reverse(a + 1, a + n), dft(a, n);
  int coef = power(n, mod - 2); for (int i = 0; i < n; ++i) mul(a[i], coef);
}
typedef std::vector<int> poly;
inline poly operator * (const poly &a, const poly &b) {
  static int x[N], y[N];
  int len = a.size() + b.size() - 1, n = 1;
  while (n < len) n <<= 1;
  for (int i = 0; i < n; ++i) x[i] = i < a.size() ? a[i] : 0, y[i] = i < b.size() ? b[i] : 0;
  dft(x, n), dft(y, n); 
  for (int i = 0; i < n; ++i) mul(x[i], y[i]);
  idft(x, n); poly c(len);
  for (int i = 0; i < len; ++i) c[i] = x[i];
  return c;
}
inline void read(poly &a, int n) { a.resize(n); for (int i = 0; i < n; ++i) scanf("%d", &a[i]);}
inline void print(const poly &a) {for (int i = 0; i < a.size(); ++i) printf("%d%c", a[i], i == a.size() - 1 ? '\n' : ' ');}
int n; long long m;
inline void trans(poly f, poly &g, int d) {
  for (int i = 0; i <= n; ++i) mul(f[i], fac[i]);
  reverse(f.begin(), f.end()); poly h(n + 1);
  for (int i = 0, p = 1; i <= n; ++i) h[i] = Mul(p, ifac[i]), mul(p, d);
  g = f * h, g.resize(n + 1), reverse(g.begin(), g.end());
  for (int i = 0; i <= n; ++i) mul(g[i], ifac[i]);
}
int main() {
  scanf("%d%lld", &n, &m), m %= mod - 1, init(n + 1);
  poly f, g; read(f, n + 1), trans(f, g, 1);
  for (int i = 0; i <= n; ++i) mul(g[i], power(inv[i + 1], m));
  trans(g, f, mod - 1), print(f);
  return 0;
}