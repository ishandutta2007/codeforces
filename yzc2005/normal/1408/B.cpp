  #include <bits/stdc++.h>
  using namespace std;
  const int N = 105;
  int t, n, k, a[N];
  int main() {
    scanf("%d", &t);
    while (t--) {
      scanf("%d%d", &n, &k);
      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (i > 1 && a[i] != a[i - 1]) {
          ++cnt;
        } 
      }
      if (cnt == 0) {
        puts("1");
      } else if (--k == 0) {
        puts("-1");
      } else {
        printf("%d\n", (cnt + k - 1) / k);
      }
    }
    return 0;
  }