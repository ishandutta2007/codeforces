#include <bits/stdc++.h>
using namespace std;
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
const int N = 305;
int n, a[N], id[N], c[N], f[N][N], tot;
inline bool judge(long long x) {
  long long y = sqrt(x);
  return y * y == x;
}
void dfs(int u) {
  id[u] = tot;
  ++c[tot];
  for (int v = 1; v <= n; ++v) {
    if (!id[v] && judge(1ll * a[u] * a[v])) {
      dfs(v);
    }
  }
}
int fac[N], inv[N];
inline int binom(int n, int m) {
  if (m < 0 || n < m) {
    return 0;
  } else {
    return Mul(fac[n], Mul(inv[m], inv[n - m]));
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2; ++i) {
    fac[i] = inv[i] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    fac[i] = Mul(fac[i - 1], i);
    inv[i] = Mul(inv[mod % i], (mod - mod / i));
  }
  for (int i = 1; i <= n; ++i) {
    mul(inv[i], inv[i - 1]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  } 
  for (int i = 1; i <= n; ++i) {
    if (!id[i]) {
      ++tot;
      dfs(i);
    }
  }
  int s = 0;
  f[0][0] = 1;
  for (int i = 1; i <= tot; ++i) {
    int x = c[i];
    for (int j = 0; j <= s; ++j) {
      for (int b = 1; b <= x; ++b) {
        for (int a = 0; a <= b; ++a) {
          add(f[i][j + (x - b) - a], Mul(f[i - 1][j], Mul(binom(x - 1, b - 1), Mul(binom(j, a), binom(s + 1 - j, b - a)))));
        }
      }
    }
    s += x;
  }
  int ans = f[tot][0];
  for (int i = 1; i <= tot; ++i) {
    for (int j = 1; j <= c[i]; ++j) {
      mul(ans, j);
    }
  }
  printf("%d\n", ans);
  return 0;
}