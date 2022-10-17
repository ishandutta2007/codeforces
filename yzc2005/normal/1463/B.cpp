#include <bits/stdc++.h>
const int N = 55;
int n, a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      for (int k = 30; ~k; --k) if (a[i] >> k & 1) {
        printf("%d ", 1 << k);
        break;
      }
    }   
    puts("");
  }
  return 0;
}