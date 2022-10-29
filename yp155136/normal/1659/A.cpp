#include <bits/stdc++.h>
using namespace std;

void go() {
  int n, r, b; cin >> n >> r >> b;
  int ans = ((r + b) / (b + 1));
  int left = r - ((ans - 1) * (b + 1));
  for (int i = 0; i < b + 1; ++i) {
    int _ = ans - 1;
    while (_--) cout << 'R';
    if (left) {
      --left;
      cout << 'R';
    }
    if (i == b) cout << endl;
    else cout << 'B';
  }
}

int main () {
  int T; cin >> T;
  while (T--) {
    go();
  }
}