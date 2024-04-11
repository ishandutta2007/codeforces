#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, u, v, a[N];

void solve() {
  scanf("%d%d%d", &n, &u, &v);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (count(a + 1, a + n + 1, a[1]) == n) {
    printf("%d\n", min(u, v) + v);
  } else {
    bool f = true;
    for (int i = 2; i <= n; ++i) {
      if (abs(a[i] - a[i - 1]) > 1) {
        f = false;
        break;
      }
    } 
    if (f) printf("%d\n", min(u, v));
    else puts("0");
  }
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}