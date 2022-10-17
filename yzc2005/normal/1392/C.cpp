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
int main() {
  for (read(t); t; --t) {
    read(n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      read(a[i]);
      ans += max(a[i - 1] - a[i], 0);
    }
    printf("%lld\n", ans);
  }
  return 0;
}