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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<char> used(n + 1);
  int p = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    while (used[a[p]]) {
      ++p;
    }
    if (a[p] != b) {
      ++res;
    }
    used[b] = true;
  }
  cout << res << '\n';
}