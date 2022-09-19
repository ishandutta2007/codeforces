#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int x = (240 - k) / 5;
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    if (i * (i + 1) / 2 <= x)
      ans = i;
  printf("%d\n", ans);
}