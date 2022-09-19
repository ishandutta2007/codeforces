# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l;
  scanf("%d%d", &n, &l);
  int a[100];
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  int ans = 0;
  for (int i = l; i <= 100; ++i) {
    int c = 0;
    for (int k = 0; k < n; ++k)
      c += a[k] / i;
    ans = max(ans, c * i);
  }
  printf("%d\n", ans);
}