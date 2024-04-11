#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    while (!a.empty() && a.back() == 0) {
      a.pop_back();
    }
    reverse(a.begin(), a.end());
    while (!a.empty() && a.back() == 0) {
      a.pop_back();
    }
    if (a.empty()) {
      cout << 0 << '\n';
    } else {
      bool nonz = true;
      for (int x : a) {
        if (x == 0) {
          nonz = false;
        }
      }
      cout << (nonz ? 1 : 2) << '\n';
    }
  }
}