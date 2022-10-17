#include <bits/stdc++.h>
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
const int N = 5005;
int n, m, k, s[N][N], ans;
int main() {
  std::cin >> n >> m >> k;
  if (m == 1) {
    ans = power(n, k);
  } else {
    int p = power(m, mod - 2), q = Sub(1, p);
    int t = Mul(p, power(q, mod - 2));
    s[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j <= i; ++j) {
        s[i][j] = Add(s[i - 1][j - 1], Mul(s[i - 1][j], j));
      }
    }  
    int dec = 1, cur = n;
    for (int i = 0; i <= std::min(n, k); ++i) {
      add(ans, Mul(Mul(Mul(s[k][i], dec), power(t, i)), power(Add(t, 1), n - i)));
      mul(dec, cur--);
    }
    mul(ans, power(q, n));
  }
  std::cout << ans << std::endl;
  return 0;
}