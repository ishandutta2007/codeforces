#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, d, m, a[N];
long long sum[N];
int main() {
  scanf("%d%d%d", &n, &d, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1, [&](int i, int j) { return i > j; });
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= m) {
      sum[cnt + 1] = sum[cnt] + a[i];
      ++cnt;
    }
  }
  long long cur = 0, ans = sum[cnt];
  for (int i = 1, j = 0; j < n && a[i] > m; ++i, j += d + 1) {
    cur += a[i];
    int left = n - 1 - j;
    ans = max(ans, cur + sum[min(cnt, left)]);
  }
  printf("%lld\n", ans);
  return 0;
}