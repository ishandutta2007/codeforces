#include <bits/stdc++.h>
const int N = 105;
int n, a[N][N], b[66];
void work1(int x) {
  --b[0];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (!a[i][j] && (i + j) % 2 == 0) {
        a[i][j] = x;
        std::cout << x << " " << i << " " << j << "\n";
        return;
      }
    }
}
void work2(int x) {
  --b[1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (!a[i][j] && (i + j) % 2) {
        a[i][j] = x;
        std::cout << x << " " << i << " " << j << "\n";
        return;
      }
    }
}
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      ++b[(i + j) % 2];
  for (int i = 1; i <= n * n; ++i) {
    int x; std::cin >> x;
    if (x == 1) {
      if (b[1]) work2(2);
      else work1(3);
    } else if (x == 2) {
      if (b[0]) work1(1);
      else work2(3); 
    } else {
      if (b[0]) work1(1);
      else work2(2);
    }
  }
  return 0;
}