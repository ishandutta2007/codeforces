#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
struct comp {
  double x, y;
  inline comp operator + (const comp &rhs) const {
    return (comp) {x + rhs.x, y + rhs.y};
  }
  inline comp operator - (const comp &rhs) const {
    return (comp) {x - rhs.x, y - rhs.y};
  }
  inline comp operator * (const comp &rhs) const {
    return (comp) {x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x};
  }
};
inline void dft(comp *a, int n) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > j) {
      swap(a[i], a[j]);
    }
    for (int k = n >> 1; (j ^= k) < k; k >>= 1);
  }
  for (int m = 2, k = 1; k < n; m <<= 1, k <<= 1) {
    comp wn = (comp) {cos(PI / k), sin(PI / k)}; 
    for (int i = 0; i < n; i += m) {
      comp w = (comp) {1, 0};
      for (int j = 0; j < k; ++j) {
        comp tmp = a[i + j + k] * w;
        a[i + j + k] = a[i + j] - tmp;
        a[i + j] = a[i + j] + tmp;
        w = w * wn;
      }
    }
  }
}
inline void idft(comp *a, int n) {
  reverse(a + 1, a + n);
  dft(a, n);
  for (int i = 0; i < n; ++i) {
    a[i].x /= n;
  }
}
const int N = 666666;
const int MAXN = 100000;
int n, m, q, a[N], b[N];
long long f[N], g[N];
inline void polymul(int *a, int A, int *b, int B, long long *f) {
  int n = 1;
  while (n < A + B - 1) {
    n <<= 1;
  }
  static comp x[N], y[N];
  for (int i = 0; i < n; ++i) {
    x[i] = (comp) {i < A ? a[i] : 0, 0};
    y[i] = (comp) {i < B ? b[i] : 0, 0};
  }
  dft(x, n);
  dft(y, n);
  for (int i = 0; i < n; ++i) {
    x[i] = x[i] * y[i];
  }
  idft(x, n);
  for (int i = 0; i < n; ++i) {
    f[i] = floor(x[i].x + 0.5);
  }
}
inline void solve(int *a, int *b, long long *f) {
  static int x[N], y[N];
  for (int i = 0; i <= MAXN; ++i) {
    x[i] = y[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    ++x[a[i]];
    if (i < n) {
      --x[max(a[i], a[i + 1])];
    }
  }
  for (int i = 1; i <= m; ++i) {
    ++y[b[i]];
    if (i < m) {
      --y[max(b[i], b[i + 1])];
    }
  }
  polymul(x, MAXN + 1, y, MAXN + 1, f);
  for (int i = 1; i <= 2 * MAXN; ++i) {
    f[i] += f[i - 1];
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  solve(a, b, f);
  for (int i = 1; i <= n; ++i) {
    a[i] = MAXN - a[i];
  }
  for (int i = 1; i <= m; ++i) {
    b[i] = MAXN - b[i];
  }
  solve(a, b, g);
  for (int i = 1, x; i <= q; ++i) {
    scanf("%d", &x);
    printf("%lld\n", g[2 * MAXN - x] - f[x - 1]);
  }
  return 0;
}