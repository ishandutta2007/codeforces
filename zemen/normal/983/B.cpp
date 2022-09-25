#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 5005;
int a[maxn][maxn];
int mx[maxn][maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[1][i];
    mx[1][i] = a[1][i];
  }
  for (int l = 2; l <= n; ++l) {
    for (int i = 0; i + l <= n; ++i) {
      a[l][i] = a[l - 1][i] ^ a[l - 1][i + 1];
      mx[l][i] = max({a[l][i], mx[l - 1][i], mx[l - 1][i + 1]});
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << mx[r - l][l] << '\n';
  }
}