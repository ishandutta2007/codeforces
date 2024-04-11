#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int x = n - 1;
  vector<bool> a(n);
  int res = 1;
  cout << res << ' ';
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    a[p] = true;
    ++res;
    while (x >= 0 && a[x] == 1) {
      --x;
      --res;
    }
    cout << res << ' ';
  }
  cout << '\n';
}