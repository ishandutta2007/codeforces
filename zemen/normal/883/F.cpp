#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int n;
  cin >> n;
  set<string> ss;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    while (true) {
      auto it = find(s.begin(), s.end(), 'u');
      if (it == s.end())
        break;
      int pos = it - s.begin();
      s = s.substr(0, pos) + "oo" + s.substr(pos + 1);
    }
    while (true) {
      auto it = find(s.begin(), s.end(), 'h');
      if (it == s.end())
        break;
      int pos = it - s.begin();
      int p = pos - 1;
      while (p >= 0 && s[p] == 'k')
        --p;
      s = s.substr(0, p + 1) + "H" + s.substr(pos + 1);
    }
    ss.insert(s);
    cerr << s << '\n';
  }
  cout << int(ss.size()) << '\n';
}