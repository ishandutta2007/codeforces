# include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  for (int i = 0; i < 5; ++i)
    for (int k = 0; k < 5; ++k) {
      int x;
      scanf("%d", &x);
      ans += x * (abs(2 - i) + abs(2 - k));
    }
  printf("%d\n", ans);
}