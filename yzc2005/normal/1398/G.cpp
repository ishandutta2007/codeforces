#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 1000000;
int m, n, y, q, f[N], g[N];
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
  int par = power(n, mod - 2);
  for (int i = 0; i < n; ++i) {
    mul(a[i], par);
  }
}
const int M = 500005;
vector<int> d[M]; 
int main() {
  read(m), read(n), read(y);
  for (int i = 1; i < M; ++i) {
    for (int j = i; j < M; j += i) {
      d[j].push_back(i);
    } 
  }
  for (int i = 1, x; i <= m + 1; ++i) {
    read(x);
    g[x] = 1;
    f[n - x] = 1;
  }
  int lim = 1;
  while (lim < n * 2) {
    lim <<= 1;
  }
  dft(g, lim);
  dft(f, lim);
  for (int i = 0; i < lim; ++i) {
    mul(f[i], g[i]);
  }
  idft(f, lim);
  read(q);
  for (int i = 1, v; i <= q; ++i) {
    read(v); 
    v /= 2;
    int res = -1;
    for (auto x : d[v]) {
      if (x > y && f[n + x - y]) {
        res = max(res, x);
      }
    }
    if (res > 0) {
      res *= 2;
    }
    printf("%d ", res);
  }
  return 0;
}