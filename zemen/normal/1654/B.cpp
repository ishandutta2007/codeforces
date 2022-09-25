#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    string s;
    cin >> s;
    vector<char> used(26);
    int p = 0;
    for (int j = (int) s.size() - 1; j >= 0; --j) {
      int c = s[j] - 'a';
      if (!used[c]) {
        used[c] = true;
        p = j;
      }
    }
    cout << s.substr(p) << '\n';
  }
}