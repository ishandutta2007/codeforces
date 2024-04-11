#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> s(c + 2);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s[x + 1] = 1;
  }
  for (int i = 0; i <= c; ++i) {
    s[i + 1] += s[i];
  }
  for (int y = 1; y <= c; ++y) {
    if (s[y + 1] - s[y] == 0) {
      continue;
    }
    for (int z = 1; y * z <= c; ++z) {
      if (s[z + 1] - s[z] > 0) {
        continue;
      }
      int l = y * z;
      int r = min(y * (z + 1), c + 1);
      if (s[r] - s[l] > 0) {
        //cerr << "fail " << y << ' ' << z << ' ' << l << ' ' << r << '\n';
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}