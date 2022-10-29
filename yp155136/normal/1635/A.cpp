#include <bits/stdc++.h>
using namespace std;

int main () {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      ans |= x;
    }
    cout << ans << endl;
  }
}