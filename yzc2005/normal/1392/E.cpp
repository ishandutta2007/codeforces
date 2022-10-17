#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
int t, n, q;
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%lld%c", i & 1 ? 1ll << (i + j) : 0, " \n"[j == n]);
    }
    fflush(stdout);
  }
  read(q);
  while (q--) {
    long long k;
    scanf("%lld", &k);
    for (int x = 1, y = 1; ; ) {
      printf("%d %d\n", x, y);
      fflush(stdout);
      if (x == n && y == n) {
        break;
      }
      if (k >> (x + y + 1) & 1) {
        if (x & 1) {
          ++y;
        } else {
          ++x;
        }
      } else {
        if (x & 1) {
          ++x;
        } else {
          ++y;
        }
      }
    }
  }
  return 0;
}