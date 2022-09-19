# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int prev1 = -1, prev2 = -1, ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (prev1 != -1) {
      if (prev2 > prev1 && prev2 > x)
        ans++;
      if (prev2 < prev1 && prev2 < x)
        ans++;
    }
    prev1 = prev2;
    prev2 = x;
  }
  printf("%d\n", ans);
}