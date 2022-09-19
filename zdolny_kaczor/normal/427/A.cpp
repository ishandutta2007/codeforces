# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    b += x;
    if (b < 0) {
      ans += -b;
      b = 0;
    }
  }
  printf("%d\n", ans);
}