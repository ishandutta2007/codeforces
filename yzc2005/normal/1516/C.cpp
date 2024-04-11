#include <bits/stdc++.h>
using namespace std;
int t, n, a[2005];
bool f[200005];
int main() {
  scanf("%d", &n);
  f[0] = 1;
  int s = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
    for (int j = s; j >= a[i]; --j) f[j] |= f[j - a[i]];
  }
  if (s & 1 || !f[s / 2]) puts("0"), exit(0);
  puts("1");
  int mn = 1e9, p = 1;
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    while (a[i] % 2 == 0) ++cnt, a[i] >>= 1;
    if (mn > cnt) mn = cnt, p = i;
  } 
  printf("%d\n", p);
  return 0;
}