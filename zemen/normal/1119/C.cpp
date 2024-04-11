#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 505;
int a[maxn][maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      a[i][j] ^= x;
    }
  }
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = 0; j < m; ++j) {
      x ^= a[i][j];
    }
    if (x) {
      cout << "No\n";
      return 0;
    }
  }
  for (int j = 0; j < m; ++j) {
    int x = 0;
    for (int i = 0; i < n; ++i) {
      x ^= a[i][j];
    }
    if (x) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}