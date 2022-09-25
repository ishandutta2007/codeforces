#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int L = 0, R = n + 1;
  while (L + 1 < R) {
    int C = (L + R) / 2;
    vector<int> b = a;
    b.resize(C);
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    ll ch = 0;
    for (int i = 0; i < (int) b.size(); i += 2) {
      ch += b[i];
    }
    if (ch > h) {
      R = C;
    } else {
      L = C;
    }
  }
  cout << L << '\n';
}