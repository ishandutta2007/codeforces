#include <bits/stdc++.h>
const int mod = 998244353;
inline void add(int &a, int b) {
  (a += b) >= mod && (a -= mod);
} 
inline int Add(int a, int b) {
  add(a, b);
  return a;
}
inline void mul(int &a, int b) {
  a = 1ll * a * b % mod;
}
inline int Mul(int a, int b) {
  return 1ll * a * b % mod;
}
const int N = 5005;
int n, a[N], b[N], dp[N], fac[N], inv[N];
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 0; i < 2; ++i) {
    fac[i] = inv[i] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    inv[i] = Mul(mod - mod / i, inv[mod % i]);
    fac[i] = Mul(fac[i - 1], i);
  }
  for (int i = 2; i <= n; ++i) {
    mul(inv[i], inv[i - 1]);
  }
  dp[0] = 1;
  b[0] = -1;
  for (int i = 1; i <= n; ++i) {
    b[i] = b[i - 1];
    while (a[b[i] + 1] * 2 <= a[i]) {
      ++b[i];
    }
    for (int j = 0; j <= b[i]; ++j) {
      int x = n - 2 - b[j], y = b[i] - b[j] - 1;
      add(dp[i], Mul(dp[j], Mul(fac[x], inv[x - y])));
    }
  }
  if (b[n] != n - 1) {
    puts("0");
  } else {
    std::cout << dp[n] << std::endl;
  }
  return 0;
}