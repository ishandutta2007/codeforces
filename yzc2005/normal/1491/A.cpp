#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, a[N];

void solve() {
  scanf("%d", &n);
  scanf("%d", &q);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt += a[i];
  }
  while (q--) {
    int t, x; scanf("%d%d", &t, &x);
    if (t == 1) {
      cnt -= a[x];
      a[x] = 1 - a[x];
      cnt += a[x];
    } else {
      printf("%d\n", cnt >= x ? 1 : 0);
    }
  }
}

int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}