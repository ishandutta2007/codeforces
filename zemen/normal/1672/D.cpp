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
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int p = 0;
  int l = 0;
  vector<int> skip(n + 1);
  while (l < n) {
    int r = l + 1;
    while (r < n && b[l] == b[r]) {
      ++r;
    }
    while (a[p] != b[l] && skip[a[p]] > 0) {
      --skip[a[p]];
      ++p;
    }
    if (a[p] != b[l]) {
      cout << "NO\n";
      return;
    }
    for (int it = 0; it < r - l; ++it) {
      if (a[p] == b[l]) {
        ++p;
      } else {
        ++skip[b[l]];
      }
    }
    l = r;
  }
  cout << "YES\n";
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    solve();
  }
}