#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  int as = accumulate(a.begin(), a.end(), 0);
  int bs = 0;
  int ap = 0, bp = 0;
  auto fit = [&]() {
    while (ap < (int) a.size() / 4) {
      as -= a[ap++];
    }
    while (bp < (int) b.size() - (int) b.size() / 4) {
      bs += b[bp++];
    }
  };
  fit();
  while (as < bs) {
    as += 100;
    a.push_back(100);
    b.push_back(0);
    fit();
  }
  cout << (int) a.size() - n << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}