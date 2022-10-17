#include <bits/stdc++.h>
const int N = 1e5 + 5;
int t, n, a[N], b[N];
bool check(int mid) {
  int k = n + mid;
  int lim = std::min(n, k - k / 4);
  int sum = 0;
  for (int i = 1; i <= lim; ++i) sum += b[i];
  int tmp = std::min(k - k / 4, mid);
  int cur = tmp * 100;
  for (int i = 1; i <= k - k / 4 - tmp; ++i) cur += a[i];
  return cur >= sum;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  std::sort(a + 1, a + n + 1, std::greater<int>());
  std::sort(b + 1, b + n + 1, std::greater<int>());
  int l = 0, r = n, ans;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &t); while (t--) solve();
  return 0;
}