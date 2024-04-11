#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  if ((a + b) & 1) puts("-1");
  else if (a == b) {
    if (a == 0) puts("0");
    else puts("1");
  } else puts("2");
}
int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}