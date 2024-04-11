#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, a[N];
int main() {
  int t; for (scanf("%d", &t); t; --t) {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    a[n + 1] = 0;
    for (int i = 1; i <= n + 1; ++i) ans += std::abs(a[i] - a[i - 1]);
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= a[i - 1] && a[i] >= a[i + 1]) ans -= std::min(a[i] - a[i - 1], a[i] - a[i + 1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}