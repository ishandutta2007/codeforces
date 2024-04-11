#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int B = 19;

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> d(n, vector<int>(B, n));
  vector<int> last(B, n);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < B; ++j) {
      if (!(a[i] & (1 << j))) {
        continue;
      }
      d[i][j] = i;
      if (last[j] < n) {
        for (int k = 0; k < B; ++k) {
          d[i][k] = min(d[i][k], d[last[j]][k]);
        }
      }
      last[j] = i;
    }
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int to = n;
    for (int b = 0; b < B; ++b) {
      if (!(a[r] & (1 << b))) {
        continue;
      }
      to = min(to, d[l][b]);
    }
    cout << (to <= r ? "Shi" : "Fou") << '\n';
  }
}