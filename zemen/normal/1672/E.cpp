#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int inf = 1e9;

int ask(int c) {
  if (c <= 0) {
    return inf;
  }
  cout << "? " << c << endl;
  int x;
  cin >> x;
  return x;
}

signed main() {
  int n;
  cin >> n;
  int l = 0, r = 5e6;
  while (l + 1 < r) {
    int c = (l + r) / 2;
    if (ask(c) == 1) {
      r = c;
    } else {
      l = c;
    }
  }
  int res = r;
  for (int y = 2; y <= n; ++y) {
    int w = (res - 1) / y;
    auto cur = ask(w) * ll(w);
    if (cur > 0 && cur < res) {
      res = cur;
    }
  }
  cout << "! " << res << endl;
}