#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a, int b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int r, c;
  cin >> r >> c;
  if (r + c == 2) {
    cout << 0 << '\n';
  } else {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        int a = i + 1, b = j + 1 + r;
        if (c == 1) {
          a = j + 1, b = i + 1 + c;
        }
        cout << lcm(a, b) << ' ';
      }
      cout << '\n';
    }
  }
}