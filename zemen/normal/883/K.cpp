#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 200200;
int a[maxn];
int b[maxn];
int res[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("k.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int s, g;
    cin >> s >> g;
    a[i] = s;
    b[i] = s + g;
  }
  for (int i = n - 2; i >= 0; --i) {
    b[i] = min(b[i], b[i + 1] + 1);
  }
  res[0] = b[0];
  for (int i = 1; i < n; ++i) {
    res[i] = min(res[i - 1] + 1, b[i]);
  }
  ll sh = 0;
  for (int i = 0; i < n; ++i) {
    if (res[i] < a[i] || res[i] > b[i]) {
      cout << -1 << '\n';
      return 0;
    }
    sh += res[i] - a[i];
  }
  cout << sh << '\n';
  for (int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}