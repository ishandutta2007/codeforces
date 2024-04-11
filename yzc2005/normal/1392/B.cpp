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
const int N = 666666;
int t, n, a[N];
long long k;
int main() {
  for (read(t); t; --t) {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    k %= 2;
    if (!k) {
      k = 2;
    }
    for (int i = 1; i <= k; ++i) {
      int mx = *max_element(a + 1, a + n + 1);
      for (int j = 1; j <= n; ++j) {
        a[j] = mx - a[j];
      }
    }
   for (int j = 1; j <= n; ++j) {
      printf("%d%c", a[j], " \n"[j == n]);
    }
  }
  return 0;
}