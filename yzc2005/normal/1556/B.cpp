#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N];
void solve() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i] %= 2;
    if (a[i]) ++cnt;
    else --cnt;
  }
  long long ans = 1e18;
  auto calc = [&](bool st) {
    long long res = 0;
    int m = 0;
    for (int i = st ? 2 : 1; i <= n; i += 2) b[++m] = i;
    for (int i = 1, j = 1; i <= n; ++i) 
      if (a[i]) res += abs(b[j++] - i);
    ans = min(ans, res); 
  };
  if (abs(cnt) > 1) puts("-1");
  else {
    if (!cnt) {
      calc(0), calc(1); 
    } else if (cnt == 1) {
      calc(0);
    } else {
      calc(1);
    }
    printf("%lld\n", ans);
  }
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}