#include <bits/stdc++.h>
using namespace std;

void solve() {
  int u, v; scanf("%d%d", &u, &v);
  if (u > v || (u & -u) > (v & -v)) puts("NO");
  else {
    int cnt = 0;
    for (int i = 0; i < 30; ++i) {
      if (u >> i & 1) ++cnt;
      if (v >> i & 1) --cnt;
      if (cnt < 0) {puts("NO"); return;}
    }
    puts("YES");
  }
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}