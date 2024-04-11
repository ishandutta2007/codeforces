#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, k;
  string s, t;
  cin >> n >> k >> s >> t;
  ll res = 0;
  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    cnt *= 2;
    if (s[i] == 'b') {
      --cnt;
    }
    if (t[i] == 'a') {
      --cnt;
    }
    cnt = max(1, min(cnt, k));
    res += cnt;
  }
  cout << res << '\n';
}