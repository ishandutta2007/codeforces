#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  multiset<string> c, c2;
  for (int i = 0; i < n; ++i) {
    auto t = s[i];
    reverse(t.begin(), t.end());
    if (t == s[i]) {
      cout << "YES\n";
      return;
    }
    c.insert(t);
    if (t.size() == 3) {
      c2.insert(t.substr(0, 2));
    }
  }

  for (int i = 0; i < n; ++i) {
    auto t = s[i];
    reverse(t.begin(), t.end());
    c.erase(c.find(t));
    if (t.size() == 3) {
      c2.erase(c2.find(t.substr(0, 2)));
    }

    if (c.count(s[i]) || c2.count(s[i]) || (s[i].size() == 3 && c.count(s[i].substr(0, 2)))) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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