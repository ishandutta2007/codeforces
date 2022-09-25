#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  string s;
  cin >> s;
  vector<pair<char, int>> b;
  for (int i = 0; i < (int) s.size(); ++i) {
    int r = i;
    while (r < (int) s.size() && s[i] == s[r]) {
      ++r;
    }
    b.emplace_back(s[i], r - i);
    i = r - 1;
  }
  int m = (int) b.size() / 2;
  if ((int) b.size() % 2 == 0 || b[m].second < 2) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < (int) b.size() / 2; ++i) {
    int j = (int) b.size() - i - 1;
    if (b[i].first != b[j].first || b[i].second + b[j].second < 3) {
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << b[m].second + 1 << '\n';
}