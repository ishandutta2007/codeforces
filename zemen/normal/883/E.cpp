#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n;
  string s;
  cin >> n >> s;
  set<char> opened;
  for (auto c : s) {
    if (c != '*')
      opened.insert(c);
  }
  int m;
  cin >> m;
  map<char, int> ok;
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t;
    bool fuck = false;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '*' && opened.count(t[j])) {
        fuck = true;
        break;
      }
      if (s[j] != '*' && s[j] != t[j]) {
        fuck = true;
        break;
      }
    }
    if (fuck)
      continue;
    ++cnt;
    set<char> was;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '*' && !was.count(t[j])) {
        was.insert(t[j]);
        ok[t[j]]++;
      }
    }
  }
  int res = 0;
  for (auto p : ok) {
    if (p.second == cnt)
      ++res;
  }
  cout << res << '\n';
}