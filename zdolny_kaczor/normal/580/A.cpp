# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int curr = 0, last = -1, ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (last <= x)
      curr++;
    else
      curr = 1;
    last = x;
    ans = max(ans, curr);
  }
  printf("%d\n", ans);
}