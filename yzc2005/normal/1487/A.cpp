#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      if (a[i] != a[i - 1]) {
        ans = n - i + 1;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}