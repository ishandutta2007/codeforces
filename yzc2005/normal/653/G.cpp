#include <bits/stdc++.h>
using namespace std;
namespace GTR {
  const int bufl = 1 << 15;
  char buf[bufl], *s = buf, *t = buf;
  inline int fetch() {
    if (s == t) { t = (s = buf) + fread(buf, 1, bufl, stdin); if (s == t) return EOF; }
    return *s++;
  }
  inline int read() {
    int a = 0, b = 1, c = fetch();
    while (c < 48 || c > 57) b ^= c == '-', c = fetch();
    while (c >= 48 && c <= 57) a = (a << 1) + (a << 3) + c - 48, c = fetch();
    return b ? a : -a;
  }
} using GTR::read;
const int P = 1e9 + 7;
inline void add(int &x, int y) { (x += y) >= P && (x -= P); }
inline int Add(int x, int y) { return add(x, y), x; }
inline void sub(int &x, int y) { (x -= y) < 0 && (x += P); }
inline int Sub(int x, int y) { return sub(x, y), x; }
inline void mul(int &x, int y) { x = 1ull * x * y % P; }
inline int Mul(int x, int y) { return 1ull * x * y % P; }
inline int power(int a, int b = P - 2) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) mul(res, a);
    mul(a, a);
  } 
  return res;
}
const int N = 3e5 + 5;
int n, buc[N], pwr[N], fac[N], ifac[N];
int tot, prime[N], mn[N];
void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = Mul(fac[i - 1], i);
  ifac[n] = power(fac[n]);
  for (int i = n - 1; ~i; --i) ifac[i] = Mul(ifac[i + 1], i + 1);
  pwr[0] = 1;
  for (int i = 1; i <= n; ++i) pwr[i] = Mul(pwr[i - 1], 2);
}
inline int binom(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return Mul(fac[n], Mul(ifac[m], ifac[n - m]));
}
void sieve(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!mn[i]) prime[++tot] = i, mn[i] = i;
    for (int j = 1; j <= tot && i * prime[j] <= n; ++j) {
      mn[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
int calc(int n, int m) {
  int ans = 0;
  if (n < m) swap(n, m);
  int s1 = pwr[n], s2 = pwr[m];
  for (int i = 1; i <= m; ++i) {
    sub(s1, binom(n, i - 1));
    sub(s2, binom(m, i - 1));
    add(ans, Mul(s1, s2));
  }
  return ans;
}
int main() {
  n = read();
  init(N - 1), sieve(N - 1);
  int A = 0, ans = 0;  
  for (int t = 0; t < n; ++t) {
    int a = read();
    ++buc[a], A = max(A, a);
  }
  for (int o = 1; o <= tot; ++o) {
    int v = prime[o], cnt[22], m = 0;
    memset(cnt, 0, sizeof cnt), cnt[0] = n;
    for (int i = v; i <= A; i += v) {
      if (!buc[i]) continue;
      int x = i, q = 0; 
      while (x % v == 0) ++q, x /= v;
      cnt[q] += buc[i], cnt[0] -= buc[i];
      m = max(m, q);
    }
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = 0; i < m; ++i) add(ans, calc(cnt[i], cnt[m] - cnt[i]));
  }
  printf("%d\n", ans);
  return 0;
}