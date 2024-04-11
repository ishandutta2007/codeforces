#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> cnt(26);
    for (auto c : s) {
      cnt[c - 'a']++;
    }
    string res;
    for (int i = 0; i < k; ++i) {
      int j = 0;
      while (j < n / k && cnt[j] > 0) {
        --cnt[j];
        ++j;
      }
      res += 'a' + j;
    }
    cout << res << '\n';
  }
}