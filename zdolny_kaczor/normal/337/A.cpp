# include <bits/stdc++.h>
using namespace std;
const int MN = 101;
int a[MN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i)
    scanf("%d", a + i);
  sort(a, a + m);
  int ans = 1e9;
  for (int i = 0; i + n <= m; ++i)
    ans = min(ans, a[i + n - 1] - a[i]);
  printf("%d\n", ans);
}