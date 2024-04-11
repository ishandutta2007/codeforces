#include <bits/stdc++.h>
int t, n;
void solve() {
  scanf("%d", &n);
  int ans = 0;
  while (n) {
    ans = std::max(ans, n % 10);
    n /= 10;
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &t); while (t--) solve();
  return 0;
}