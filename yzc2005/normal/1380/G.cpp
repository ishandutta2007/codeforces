#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void add(int &a, int b) { (a += b) >= mod && (a -= mod); }
int Add(int a, int b) { return add(a, b), a; }
void sub(int &a, int b) { (a -= b) < 0 && (a += mod); }
int Sub(int a, int b) { return sub(a, b), a; }
void mul(int &a, int b) { a = 1ll * a * b % mod; }
int Mul(int a, int b) { return 1ll * a * b % mod; }
inline int qpow(int a, int b) {
    int res = 1; 
    for (; b; b >>= 1, mul(a, a)) 
      if (b & 1) mul(res, a); 
    return res;
}
const int N = 300005;
int n, a[N], inv;
int main() {
  scanf("%d", &n);
  inv = qpow(n, mod - 2);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &a[i]);
  sort(a + 1, a + n + 1, [&](int i, int j) {return i > j;});
  for (int i = 1; i <= n; ++i) 
    add(a[i], a[i - 1]);
  for (int k = 1; k <= n; ++k) {
    int ans = 0;
    for (int i = k * 2, j = 1; i - k < n; i += k, ++j)
      add(ans, Mul(j, Sub(a[min(n, i)], a[i - k])));
    printf("%d ", Mul(ans, inv));
  }
  return 0;
}