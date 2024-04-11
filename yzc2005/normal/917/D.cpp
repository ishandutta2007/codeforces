#include <bits/stdc++.h>
const int mod = 1e9 + 7;
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
const int N = 105;
int n, f[N], a[N][N], ans[N];
bool g[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    g[x][y] = g[y][x] = 1;
  }
  for (int w = 0; w < n; ++w) {
    std::memset(a, 0, sizeof(a));
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        if (g[u][v]) {
          add(a[u][u], w);
          sub(a[u][v], w);
        } else if (u != v) {
          add(a[u][u], 1);
          sub(a[u][v], 1);
        }
      }
    }
    [&]() {
      int res = 1;
      for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (a[j][i]) {
            std::swap(a[i], a[j]);
            mul(res, mod - 1);
            break;
          }
        }
        for (int j = 1; j < n; ++j) {
          if (i != j) {
            int p = Mul(a[j][i], power(a[i][i], mod - 2));
            for (int k = i; k < n; ++k) {
              sub(a[j][k], Mul(p, a[i][k]));
            }
          }
        }
      }
      for (int i = 1; i < n; ++i) {
        mul(res, a[i][i]);
      } 
      std::memset(f, 0, sizeof(f));
      f[0] = 1;
      for (int i = 0; i < n; ++i) {
        if (i != w) {
          mul(res, power(Sub(w, i), mod - 2));
          for (int j = n - 1; ~j; --j) {
            f[j] = Sub(j ? f[j - 1] : 0, Mul(i, f[j]));
          }
        }
      }   
      for (int i = 0; i < n; ++i) {
        add(ans[i], Mul(res, f[i]));
      } 
    }();
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  } 
  return 0;
}