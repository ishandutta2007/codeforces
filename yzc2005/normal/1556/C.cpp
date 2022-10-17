#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, c[N];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  long long ans = 0;
  for (int i = 1; i <= n; i += 2) {
    long long sum = 0, mn = 0;
    for (int j = i + 1; j <= n; j += 2) {
      long long inf = max(1ll, -mn);
      long long sup = min(1ll * c[i], c[j] - sum);
      ans += max(0ll, sup - inf + 1);
      sum -= c[j];
      mn = min(mn, sum);
      sum += c[j + 1];
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}