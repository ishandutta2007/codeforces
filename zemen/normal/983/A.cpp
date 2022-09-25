#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    ll p, q, b;
    cin >> p >> q >> b;
    if (p > 0) {
      ll g = gcd(p, q);
      p /= g;
      q /= g;
      while (true) {
        g = gcd(b, q);
        if (g == 1) {
          break;
        }
        while (q % g == 0) {
          q /= g;
        }
      }
    }
    if (p == 0 || q == 1) {
      cout << "Finite\n";
    } else {
      cout << "Infinite\n";
    }
  }
}