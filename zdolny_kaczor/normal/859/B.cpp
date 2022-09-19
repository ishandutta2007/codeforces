# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, 2 * (i + (n + i - 1) / i));
  }
  printf("%d\n", ans);
}