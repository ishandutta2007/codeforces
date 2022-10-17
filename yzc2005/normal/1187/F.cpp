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
const int N = 200005;
int n, p[N], q[N], l[N], r[N], len[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &l[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &r[i]);
    len[i] = r[i] - l[i] + 1;
  }
  int cnt = 0, ans = 0;
  r[0] = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    int L = max(l[i - 1], l[i]), R = min(r[i - 1], r[i]);
    if (L <= R) {
      p[i] = Mul(R - L + 1, power(Mul(len[i - 1], len[i]), mod - 2));
    } 
    q[i] = Sub(1, p[i]);
    if (i > 1) {
      L = max(L, l[i - 2]);
      R = min(R, r[i - 2]);
      int tmp = Sub(1, Add(p[i - 1], p[i]));
      if (L <= R) {
        add(tmp, Mul(R - L + 1, power(Mul(len[i - 2], Mul(len[i - 1], len[i])), mod - 2)));
      } 
      add(ans, Mul(tmp, 2));
    }
    add(ans, q[i]);
    add(ans, Mul(2, Mul(q[i], cnt)));
    add(cnt, q[i - 1]);
  }
  printf("%d\n", ans);
  return 0;
}