#include <bits/stdc++.h>
using namespace std;
const int N = 666666;

const int mod = 998244353;
inline void add(int &a, int b) { 
  (a += b) >= mod && (a -= mod); 
}
inline int Add(int a, int b) { 
  return add(a, b), a;
}
inline void sub(int &a, int b) { 
  (a -= b) < 0 && (a += mod); 
}
inline int Sub(int a, int b) { 
  return sub(a, b), a; 
}
inline void mul(int &a, int b) { 
  a = 1ll * a * b % mod; 
}
inline int Mul(int a, int b) { 
  return 1ll * a * b % mod; 
}
inline int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      mul(res, a);
    }
    mul(a, a);
    b >>= 1;
  }
  return res;
}
inline void dft(int *a, int n) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > j) {
      swap(a[i], a[j]);
    }
    for (int k = n >> 1; (j ^= k) < k; k >>= 1);
  }
  for (int m = 2, k = 1; k < n; k <<= 1, m <<= 1) {
    int wn = power(3, (mod - 1) / m);
    for (int i = 0; i < n; i += m) {
      for (int j = 0, w = 1; j < k; ++j) {
        int tmp = Mul(a[i + k + j], w);
        a[i + k + j] = Sub(a[i + j], tmp);
        add(a[i + j], tmp);
        mul(w, wn);
      }
    }
  }
}
inline void idft(int *a, int n) {
  reverse(a + 1, a + n);
  dft(a, n);
  int div = power(n, mod - 2);
  for (int i = 0; i < n; ++i) {
    mul(a[i], div);
  }
}
inline int extend(int x) {
  int n = 1;
  while (n < x) {
    n <<= 1;
  }
  return n;
}
inline void polymul(int *a, int A, int *b, int B, int *f) {
  int n = extend(A + B - 1);
  static int x[N], y[N];
  for (int i = 0; i < n; ++i) {
    x[i] = i < A ? a[i] : 0;
    y[i] = i < B ? b[i] : 0;
  } 
  dft(x, n);
  dft(y, n);
  for (int i = 0; i < n; ++i) {
    f[i] = Mul(x[i], y[i]);
  }
  idft(f, n);
}
void polyinv(int *f, int *g, int n) {
  static int h[N];
  if (n == 1) {
    f[0] = power(g[0], mod - 2);
    return;
  }
  polyinv(f, g, (n + 1) / 2);
  int m = extend(n * 2 - 1);
  for (int i = 0; i < m; ++i) {
    h[i] = i < n ? g[i] : 0;
  }
  dft(h, m);
  dft(f, m);
  for (int i = 0; i < m; ++i) {
    mul(f[i], Sub(2, Mul(f[i], h[i])));
  }
  idft(f, m);
  for (int i = n; i < m; ++i) {
    f[i] = 0;
  }
}
void polysqrt(int *f, int *g, int n) {
  if (n == 1) {
    f[0] = 1;
    return;
  }
  polysqrt(f, g, (n + 1) / 2);
  static int a[N], b[N];
  static const int inv2 = (mod + 1) / 2;
  int m = extend(n * 2 - 1);
  for (int i = 0; i < m; ++i) {
    b[i] = 0;
  }
  polyinv(b, f, n);
  for (int i = 0; i < m; ++i) {
    a[i] = i < n ? g[i] : 0; 
  }
  dft(a, m), dft(b, m), dft(f, m);
  for (int i = 0; i < m; ++i) {
    f[i] = Mul(inv2, Add(f[i], Mul(a[i], b[i])));
  }
  idft(f, m);
  for (int i = n; i < m; ++i) {
    f[i] = 0;
  }
}

int n, m, f[N], g[N];

int main() {
  scanf("%d%d", &m, &n);
  ++n;
  for (int i = 1, x; i <= m; ++i) {
    scanf("%d", &x);
    g[x] = (x < n);
  }
  for (int i = 0; i < n; ++i) {
    f[i] = Sub(i == 0, Mul(g[i], 4));
  }
  polysqrt(g, f, n);
  ++g[0];
  memset(f, 0, sizeof(f));
  polyinv(f, g, n);
  for (int i = 1; i < n; ++i) {
    printf("%d\n", Mul(f[i], 2));
  }
  return 0;
}