#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int T, n, m, a[N], b[N], c[N];
long long sum[N];
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      c[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    sum[n + 1] = 0;
    for (int i = n; i; --i) 
      sum[i] = sum[i + 1] + a[i];
    long long ans = sum[max(1, n - m + 1)];
    for (int i = 1; i <= n; ++i) {
      int pos = lower_bound(a + 1, a + n + 1, b[i]) - a;
      int para = m - (n - pos + 1);
      if (para < 0) continue;
      if (c[i] >= b[i]) ans = max(ans, sum[pos] + 1ll * b[i] * para);
      else if (para) ans = max(ans, sum[pos] + c[i] + 1ll * b[i] * (para - 1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}