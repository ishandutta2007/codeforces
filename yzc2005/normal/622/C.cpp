#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, a[N], p[N], cnt = 1;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (i > 1 && a[i] != a[i - 1]) p[++cnt] = i - 1;
  }
  p[++cnt] = n;
  for (int i = 1, l, r, x; i <= m; ++i) {
    scanf("%d%d%d", &l, &r, &x);
    bool flag = 0; 
    for (int j = lower_bound(p + 1, p + cnt + 1, l) - p; ; ++j) {
      if (a[p[j]] != x) {
        printf("%d\n", max(l, p[j - 1] + 1));
        flag = 1;
        break;
      }
      if (p[j] >= r) break;
    }
    if(!flag) puts("-1");
  }
  return 0;
}