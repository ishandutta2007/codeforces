# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  int ans = 0;
  for (int i = 0; a * i <= n; ++i)
    for (int j = 0; a * i + b * j <= n; ++j) {
      int k = n - a * i - b * j;
      if (k % c == 0)
        ans = max(ans, i + j + k / c);
    }
  printf("%d\n", ans);
}