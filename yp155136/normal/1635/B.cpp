#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int a[N], b[N];

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      b[i] = a[i];
    }
    b[0] = b[n + 1] = 1000000000;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (b[i] > b[i - 1] && b[i] > b[i + 1]) {
        b[i + 1] = max(b[i], b[i + 2]);
        ++ans;
      }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) {
      cout << b[i] << " \n"[i == n];
    }
  }
}