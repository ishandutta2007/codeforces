  #include <bits/stdc++.h>
  using namespace std;
  const int N = 105;
  int t, n, p[N], a[N][3];
  int main() {
    scanf("%d", &t);
    while (t--) {
      memset(p, 0, sizeof(p));
      scanf("%d", &n);
      for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
          scanf("%d", &a[i][j]);
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
          if (a[i][j] != p[i - 1] && a[i][j] != p[(i + 1) % n]) {
            p[i] = a[i][j];
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        printf("%d%c", p[i], " \n"[i == n - 1]);
      }
    }
    return 0;
  }