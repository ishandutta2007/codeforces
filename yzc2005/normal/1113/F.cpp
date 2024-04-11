#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

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
  if (b < 0) {
    b = -b;
    a = power(a, mod - 2);
  }
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

int inv[N], fac[N], fac_inv[N];
inline void prework(int n) {
  for (int i = 0; i < 2; ++i) {
    inv[i] = fac[i] = fac_inv[i] = 1;  
  }
  for (int i = 2; i <= n; ++i) {
    fac[i] = Mul(i, fac[i - 1]);
    inv[i] = Mul(inv[mod % i], mod - mod / i);
    fac_inv[i] = Mul(fac_inv[i - 1], inv[i]);
  }
}
inline int binom(int n, int m) {
  return Mul(fac[n], Mul(fac_inv[m], fac_inv[n - m]));
}

int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  prework(max(n, m));
  int ans = 0;
  for (int i = 1; i < min(n, m + 1); ++i) {
    add(ans, Mul(binom(n - 2, i - 1), Mul(fac[i - 1], Mul(binom(m - 1, i - 1), Mul(power(m, n - 1 - i), Mul(i + 1, power(n, n - i - 2)))))));
  }
  cout << ans<< '\n';
  return 0;
}