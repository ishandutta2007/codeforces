#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int t, n, a[N], last[N], mx[N], ans[N];
int main() {
  for (scanf("%d", &t); t; --t) {
    scanf("%d", &n);
    fill(mx + 1, mx + n + 1, 0);
    fill(last + 1, last + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mx[a[i]] = max(mx[a[i]], i - last[a[i]]);
      last[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      if (last[i]) {
        mx[i] = max(mx[i], n - last[i] + 1);
      }
    }
    fill(ans, ans + n + 1, 1e9);
    for (int i = n; i; --i) {
      if (mx[i]) {
        ans[mx[i]] = i;
      }
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] = min(ans[i], ans[i - 1]);
      printf("%d ", ans[i] > n ? -1 : ans[i]);
    }
    puts("");
  }
  return 0;
}