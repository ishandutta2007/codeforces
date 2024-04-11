#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  map<int, int> cnt;
  map<pair<int, int>, int> cnt_pair;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    int w, h;
    cin >> w >> h;
    if (w > h) {
      swap(w, h);
    }
    if (w == h) {
      res += cnt[w];
      ++cnt[w];
    } else {
      res += cnt[w] + cnt[h] - cnt_pair[{w, h}];
      ++cnt[w];
      ++cnt[h];
      ++cnt_pair[{w, h}];
    }
  }
  cout << res << '\n';
}