#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
const int maxm = 11;
int a[maxm][maxn];
int ar[maxm][maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      cin >> a[j][i];
      --a[j][i];
      ar[j][a[j][i]] = i;
    }
  }
  int r = 0;
  ll res = 0;
  for (int l = 0; l < n; ++l) {
    r = max(r, l + 1);
    while (r < n) {
      bool ok = true;
      int pval = a[0][r-1];
      int val = a[0][r];
      for (int j = 0; j < m; ++j) {
        int p1 = ar[j][pval];
        int p2 = ar[j][val];
        if (p2 != p1 + 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ++r;
      } else {
        break;
      }
    }
    res += r - l;
  }
  cout << res << '\n';
}