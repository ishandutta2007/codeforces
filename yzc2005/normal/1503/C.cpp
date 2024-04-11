#include <bits/stdc++.h>
typedef long long ll;
const int N = 200005, M = N * 2;
int n, a[N], b[N], c[N], p[N], q[N * 2], t;
ll ans, dp[N], c1[M], c2[M];
inline void down(ll &x, ll y) {x > y ? x = y : 0;}
void modify(ll *c, int p, ll x) {
  for (; p <= t; p += p & -p) down(c[p], x);
}
ll query(ll *c, int p) {
  ll res = 1e18;
  for (; p; p -= p & -p) down(res, c[p]);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &c[i]), ans += c[i], b[i] = c[i] + a[i], q[++t] = a[i], q[++t] = b[i];
  std::sort(q + 1, q + t + 1), t = std::unique(q + 1, q + t + 1) - q - 1;
  std::iota(p + 1, p + n + 1, 1);
  std::sort(p + 1, p + n + 1, [&](int i, int j) {
    return a[i] < a[j];
  });
  memset(c1, 0x3f, sizeof c1);
  memset(c2, 0x3f, sizeof c2);
  for (int i = 1; i <= n; ++i) {
    int j = p[i];
    int A = std::lower_bound(q + 1, q + t + 1, a[j]) - q;
    int B = std::lower_bound(q + 1, q + t + 1, b[j]) - q;
    if (i == 1) dp[i] = 0;
    else dp[i] = std::min(a[j] + query(c1, A), query(c2, t - A + 1));
    modify(c1, B, dp[i] - b[j]), modify(c2, t - B + 1, dp[i]);
  }
  printf("%lld\n", ans + dp[n]);
  return 0;
}