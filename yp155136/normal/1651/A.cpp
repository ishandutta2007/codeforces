#include <bits/stdc++.h>
using namespace std;

int main () {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    cout << (1ll << n) - 1 << endl;
  }
}