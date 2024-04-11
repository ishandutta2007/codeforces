#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int s = a + b + c;
    if (s % 9) puts("NO");
    else {
      s /= 9;
      if (a < s || b < s || c < s) puts("NO");
      else puts("YES");
    }
  }
  return 0;
}