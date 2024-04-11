#include <bits/stdc++.h>
using namespace std;

char s[15];

void solve() {
  scanf("%s", s + 1);
  int ans = 10;
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= 10; ++i) {
    if (s[i] == '?') {
      if (i & 1) ++c1;
    } else if (s[i] == '1') {
      if (i & 1) ++c1;
      else ++c2;
    }
    if (c1 > c2 + (10 - i + 1) / 2) {
      ans = i; break;
    }
  }
  c1 = 0, c2 = 0;
  for (int i = 1; i <= 10; ++i) {
    if (s[i] == '?') {
      if (!(i & 1)) ++c2;
    } else if (s[i] == '1') {
      if (i & 1) ++c1;
      else ++c2;
    }
    if (c2 > c1 + (10 - i) / 2) {
      ans = min(ans, i); break;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}