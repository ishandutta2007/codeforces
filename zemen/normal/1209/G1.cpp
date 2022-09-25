#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  int n, q;
  cin >> n >> q;
  assert(q == 0);
  vector<int> a(n);
  vector<int> r(200200);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    r[a[i]] = i;
  }
  int res = n;
  for (int l = 0; l < n; ++l) {
    int cr = l;
    int to = r[a[cr]];
    map<int, int> cnt;
    cnt[a[cr]]++;
    while (cr < to) {
      ++cr;
      cnt[a[cr]]++;
      to = max(to, r[a[cr]]);
    }
    int cur = 0;
    for (auto p : cnt) {
      cur = max(cur, p.second);
    }
    res -= cur;
    l = to;
  }
  cout << res << '\n';
}