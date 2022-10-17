#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, k, a[N];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int s = 0, t = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
    for (int i = 1; i < n; ++i) {
      if (k >= a[i]) printf("0 "), k -= a[i];
      else printf("%d ", a[i] - k), t += a[i] - k, k = 0;
    } 
    printf("%d\n", s - t);
  }
  return 0;
}