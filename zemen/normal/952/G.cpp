#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  string s;
  cin >> s;
  uint8_t c = 0;
  for (char cx : s) {
    uint8_t x = cx + 1;
    while (c != x) {
      --c;
      cout << "..." << '\n';
      cout << ".X." << '\n';
    }
    --c;
    cout << "..." << '\n';
    cout << ".X." << '\n';
    cout << ".X." << '\n';
  }
}