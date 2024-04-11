#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int n, r[N][5], p[N];

void solve() {
  scanf("%d", &n);
  int cur = 0; 
  auto check = [&](int i, int j) {
    int cnt = 0;
    for (int k = 0; k < 5; ++k) cnt += r[i][k] > r[j][k];
    return cnt >= 3;
  };
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 5; ++j)
      scanf("%d", &r[i][j]);
    if (cur == 0 || check(cur, i)) cur = i; 
  }
  for (int i = 1; i <= n; ++i) {
    if (i == cur) continue;
    if (!check(i, cur)) {
      puts("-1");
      return;
    }
  }
  printf("%d\n", cur);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}