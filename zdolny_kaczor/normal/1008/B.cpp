# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int last = 1e9 + 10;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    if (last >= y)
      last = y;
    else if (last >= x)
      last = x;
    else {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}