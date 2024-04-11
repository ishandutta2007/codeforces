#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int N = 105;
char win[N][N][2][2];

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int odd = 0; odd < N; ++odd) {
    for (int even = 0; even < N; ++even) {
      for (int p = 0; p < 2; ++p) {
        for (int who = 0; who < 2; ++who) {
          auto& res = win[odd][even][p][who];
          if (odd + even == 0) {
            res = !p;
          } else if (!who) {
            res = false;
            if (odd > 0) {
              res |= win[odd - 1][even][p ^ 1][who ^ 1];
            }
            if (even > 0) {
              res |= win[odd][even - 1][p][who ^ 1];
            }
          } else {
            res = false;
            if (odd > 0) {
              res |= !win[odd - 1][even][p][who ^ 1];
            }
            if (even > 0) {
              res |= !win[odd][even - 1][p][who ^ 1];
            }
            res ^= 1;
          }
        }
      }
    }
  }
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x % 2) {
        ++odd;
      } else {
        ++even;
      }
    }
    cout << (win[odd][even][0][0] ? "Alice" : "Bob") << '\n';
  }
}