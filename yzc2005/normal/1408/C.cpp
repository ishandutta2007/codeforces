#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, L, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    double l = 0, r = L, ans;
    a[n + 1] = L;
    for (int i = 1; i <= 100; ++i) {
      double mid = (l + r) / 2;
      double x = 0, y = 0;
      for (int i = 1; i <= n + 1; ++i) {
        if (a[i] >= mid) {
          x += (mid - a[i - 1]) * 1.0 / i;
          break;
        } else {
          x += (a[i] - a[i - 1]) * 1.0 / i;
        }
      }
      for (int i = n, j = 1; ~i; --i, ++j) {
        if (a[i] <= mid) {
          y += (a[i + 1] - mid) * 1.0 / j;
          break;
        } else {
          y += (a[i + 1] - a[i]) * 1.0 / j;
        }
      }
      if (x <= y) {
        ans = x;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    printf("%lf\n", ans);
  }
  return 0;
}