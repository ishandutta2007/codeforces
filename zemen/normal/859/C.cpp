#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 55;
int a[maxn];
int n;

int d[maxn][2];
int solve(int i, int who) {
  if (i == n) {
    return 0;
  }
  if (d[i][who] != 1e9)
    return d[i][who];
  int& res = d[i][who];
  if (who)
    res = max(solve(i + 1, who), solve(i + 1, !who) + a[i]);
  else
    res = min(solve(i + 1, who) + a[i], solve(i + 1, !who));
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      d[i][j] = 1e9;
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int bob = solve(0, 1);
  int alice = accumulate(a, a + n, 0) - bob;
  cout << alice << ' ' << bob << '\n';
}