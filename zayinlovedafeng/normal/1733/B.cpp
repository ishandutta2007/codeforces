#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    if (x && y) {
      cout << -1 << endl;
      continue;
    }
    if (!x && !y) {
      cout << -1 << endl;
      continue;
    }

    int k = x + y;
    if ((n - 1) % k) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 2; i <= n; i += k) {
      for (int t = 0; t < k; ++t) cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}