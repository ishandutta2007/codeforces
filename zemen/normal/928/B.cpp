#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    --a;
    if (a == -1) {
      d[i] = min(i + k, n - 1) - max(i - k, 0) + 1;
    } else {
      d[i] = d[a] + max(0, min(i + k, n - 1) - max(i - k, a + k + 1) + 1);
    }
    cout << d[i] << ' ';
  }
  cout << '\n';
}