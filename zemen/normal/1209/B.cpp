#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  int res = 0;
  for (int iter = 0; iter < 10000; ++iter) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (iter >= b[i] && (iter - b[i]) % a[i] == 0) {
        s[i] = s[i] == '0' ? '1' : '0';
      }
      cnt += s[i] == '1';
    }
    res = max(res, cnt);
  }
  cout << res << '\n';
}