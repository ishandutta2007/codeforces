# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h;
  scanf("%d%d", &n, &h);
  int ans = n;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x > h)
      ans++;
  }
  printf("%d\n", ans);
}