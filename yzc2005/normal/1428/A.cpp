#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int ans = 2;
    if (x1 == x2 || y1 == y2) ans = 0;
    printf("%d\n", ans + abs(x1 - x2) + abs(y1 - y2));
  }
  return 0;
}