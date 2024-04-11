#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 500500;
bool used[maxn];
int f = 1;
int a, b;

void dfs(int u, int bd) {
  used[u] = true;
  ++f;
  if (u - b >= 0 && !used[u - b]) {
    dfs(u - b, bd);
  }
  if (u + a <= bd && !used[u + a]) {
    dfs(u + a, bd);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  used[0] = true;
  int m;
  cin >> m >> a >> b;
  ll res = 0;
  const int M = 500000;
  for (int i = 0; i <= min(m, M); ++i) {
    if (i - a >= 0 && used[i - a]) {
      dfs(i, i);
    }
    res += f;
  }
  if (m > M) {
    res += ll(f) * (m - M);
    for (int rem = 0; rem < a; ++rem) {
      if (!used[rem]) {
        continue;
      }
      ll l = M / a * a + rem;
      if (l <= M) {
        l += a;
      }
      ll r = m / a * a + rem;
      if (r > m) {
        r -= a;
      }
      if (l > r) {
        continue;
      }
      ll cnt = (r - l) / a + 1;
      res += cnt * (m - r + 1);
      res += a * cnt * (cnt - 1) / 2;
    }
  }
  cout << res << '\n';
}