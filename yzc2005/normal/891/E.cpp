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
const int N = 5005;
int n, k, f[N][N];
int main() {
  std::cin >> n >> k;
  f[0][0] = 1;
  int ans = 1;
  for (int t = 1; t <= n; ++t) {
    int x;
    std::cin >> x;
    mul(ans, x);
    for (int i = 0; i <= t; ++i) {
      f[t][i] = Sub(Mul(x, f[t - 1][i]), i ? f[t - 1][i - 1] : 0);
    }
  }
  int res = 0, inv = power(n, mod - 2);
  int pwr = 1, fac = 1;
  for (int i = 0; i <= n; ++i) {
    add(res, Mul(f[n][i], Mul(fac, pwr)));
    mul(pwr, inv);
    mul(fac, k--);
  }
  std::cout << Sub(ans, res) << std::endl;
  return 0;
}