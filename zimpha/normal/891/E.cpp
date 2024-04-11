#include <cstdio>
#include <vector>

using int64 = long long;

const int mod = 1e9 + 7;

int64 pow_mod(int64 a, int64 n) {
  int64 r = 1;
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % mod;
    a = a * a % mod;
  }
  return r;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int64> c = {1};
  int64 prod = 1;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    prod = prod * a % mod;
    std::vector<int64> t(i + 1, 0);
    for (int j = 0; j < i; ++j) {
      t[j + 1] = c[j];
    }
    for (int j = 0; j < i; ++j) {
      t[j] = (t[j] - a * c[j] % mod + mod) % mod;
    }
    c.swap(t);
  }
  int64 inv = pow_mod(pow_mod(n, k), mod - 2);
  int64 ret = 0, fac = 1;
  for (size_t i = 0; i < c.size() && i <= k; ++i) {
    // k! / (k - i)! * c[i] * n^(k-i) * inv
    ret += fac * c[i] % mod * pow_mod(n, k - i) % mod * inv % mod;
    fac = fac * (k - i) % mod;
    ret %= mod;
  }
  if (n & 1) ret = mod - ret;
  printf("%lld\n", (prod - ret + mod) % mod);
  return 0;
}