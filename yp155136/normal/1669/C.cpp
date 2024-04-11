#include <bits/stdc++.h>
using namespace std;

int main () {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    string ans = "YES";
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i % 2 == j % 2) {
          if (a[i] % 2 != a[j] % 2) {
            ans = "NO";
          }
        }
      }
    }
    cout << ans << endl;
  }
}