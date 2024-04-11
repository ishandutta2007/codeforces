#include <bits/stdc++.h>
using namespace std;

void go() {
  int k, n; cin >> n >> k;
  if (n == 1) {
    cout << "R" << endl;
    return;
  }
  if (k <= (n + 1) / 2) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j && i % 2 == 1 && i / 2 < k) cout << "R";
        else cout << ".";
      }
      cout << endl;
    }
  }
  else {
    cout << -1 << endl;
  }
}

int main () {
  int T; cin >> T;
  while (T--) {
    go();
  }
}