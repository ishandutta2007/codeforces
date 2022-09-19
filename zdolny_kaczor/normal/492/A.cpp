# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < 100; ++i)
    if (i * (i + 1) * (i + 2) / 6 <= n)
      ans = i;
  printf("%d\n", ans);
}