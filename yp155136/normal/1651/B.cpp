#include <bits/stdc++.h>
using namespace std;

int main () {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    long long v = 1;
    vector<long long> ans;
    string ans2 = "YES";
    for (int i = 1; i <= n; ++i) {
      if (v > 1000000000) {
        ans2 = "NO";
        break;
      }
      ans.push_back(v);
      v *= 3;
    }
    cout << ans2 << endl;
    if (ans2 == "YES") {
      for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
      }
    }
  }
}