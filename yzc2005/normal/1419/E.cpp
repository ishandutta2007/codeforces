#include <bits/stdc++.h>
const int N = 25;
int t, n, p[N], q[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int cnt = 0, tmp = n, m = sqrt(n);
    for (int i = 2; i <= m; ++i) {
      if (n % i == 0) {  
        p[++cnt] = i;
        q[cnt] = 0;
        while (n % i == 0) {
          ++q[cnt];
          n /= i;
        }
      }
    }
    if (n > 1) {
      p[++cnt] = n;
      q[cnt] = 1;
    }
    if (cnt == 2) {
      if (*std::max_element(q + 1, q + cnt + 1) == 1) {
        printf("%d %d %d\n1\n", p[1], p[2], tmp);
      } else {
        for (int i = 1, x = 1; i <= q[1]; ++i) {
          x *= p[1];
          for (int j = 0, y = 1; j <= q[2]; ++j) {
            if (x * y != tmp && (i != 1 || j != 1)) {
              printf("%d ", x * y);
            }
            y *= p[2];
          }
        }
        printf("%d ", p[1] * p[2]);
        for (int i = 1, x = 1; i <= q[2]; ++i) {
          x *= p[2];
          printf("%d ", x);
        }
        printf("%d\n0\n", tmp);
      }
    } else {
      for (int i = 1; i <= cnt; ++i) {
        std::function<void(int, int)> dfs = [&](int x, int y) {
          if (y == cnt + 1) {
            if (x != p[1] * p[cnt]) {
              printf("%d ", x);
            }
            return;
          }
          for (int z = 0; z <= q[y]; ++z) {
            if (z || y != i) {
              dfs(x, y + 1); 
            }
            x *= p[y];
          }
        };
        dfs(1, i);
      }
      printf("%d\n0\n", p[1] * p[cnt]);
    }
  }
  return 0;
}