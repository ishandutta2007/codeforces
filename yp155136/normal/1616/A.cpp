#include <bits/stdc++.h>
using namespace std;

int main () {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
      int x; cin >> x;
      mp[abs(x)]++;
    }
    int ans = 0;
    for (auto i : mp) {
      if (i.first != 0) ans += min(i.second, 2);
      else ++ans;
    }
    cout << ans << endl;
  }
}