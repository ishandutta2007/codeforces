#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, pre[N];
long long t[N], x[N];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; ++i) 
      scanf("%lld %lld", &t[i], &x[i]);
    t[n + 1] = 1e18; 
    for (int i = 1, last = 0; i <= n; ++i) {
      long long ti = t[last] + abs(x[pre[last]] - x[last]);
      if (ti <= t[i]) {
        long long ttt = t[i] + abs(x[i] - x[last]);
        if (ttt <= t[i + 1]) ++ans;
        pre[i] = last;
        last = i;
      } else {
        int dir = x[last] > x[pre[last]] ? 1 : -1;  
        long long l = x[pre[last]] + (t[i] - t[last]) * dir;
        long long t1 = t[i + 1] - t[last], t2 = abs(x[last] - x[pre[last]]);
        long long r = x[pre[last]] + std::min(t1, t2) * dir;
        if (l > r) std::swap(l, r);
        if (l <= x[i] && x[i] <= r) ++ans;
      }
    }
    printf("%d\n", ans);
  }
}