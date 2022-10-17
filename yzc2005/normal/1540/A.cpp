#include <bits/stdc++.h>
const int N = 100005;
int t, n, d[N];
int main() {
  for (scanf("%d", &t); t; --t) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
    std::sort(d + 1, d + n + 1);
    long long ans = d[n], sum = 0;
    for (int i = 1; i <= n; ++i) {
      ans -= 1ll * d[i] * (i - 1) - sum;
      sum += d[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}