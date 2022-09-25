#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ll p, k;
  cin >> p >> k;
  vector<ll> a;
  int sgn = 1;
  while (p) {
    a.push_back((p % k) * sgn);
    p /= k;
    sgn *= -1;
  }
  while (true) {
    bool ch = false;
    for (int i = 0; i < (int) a.size(); ++i) {
      if (a[i] < 0) {
        a[i] += k;
        if (i + 1 == (int) a.size()) {
          a.push_back(0);
        }
        a[i + 1]++;
        ch = true;
      }
      if (a[i] >= k) {
        a[i] -= k;
        if (i + 1 == (int) a.size()) {
          a.push_back(0);
        }
        a[i + 1]--;
        ch = true;
      }
    }
    if (!ch) {
      break;
    }
  }

  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
  cout << (int) a.size() << '\n';
  for (auto x : a) {
    cout << x << ' ';
  }
  cout << '\n';
}