#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

/*bool ok(ll n, ll k, ll x, ll l, ll r) {
  ll L = n + l, R = n + R;
  if (k < x) return false;
}*/

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, l0, r0, k;
  cin >> n >> l0 >> r0 >> k;
  ll x = (r0 - l0 + n) % n + 1;
  if (k < x) {
    cout << -1 << endl;
    return 0;
  }
  if (x == n) {
    ll res = -1;
    for (ll k1 : {k, k + 1}) {
      ll l = k1 == k ? 0 : 1;
      for (ll d = 1; d * d <= k1; ++d) if (k1 % d == 0) {
        for (ll t : {d - n, k1 / d - n}) {
          if (t >= l && t <= n) {
            res = max(res, t);
          }
        }
      }
    }
    cout << res << endl;
    return 0;
  }
  const ll N = 2000000;
  if (n <= N) {
    for (int t = n; t >= 0; --t) {
      int rem = k % (n + t) - x;
//      if (t == 2) cerr << x << ' ' << rem << endl;
      if (rem < 0) continue;
      bool ok = 0;
      for (int t1 : {rem, rem + 1}) {
        if (t1 >= 0 && t1 <= min(x, (ll)t) && t - t1 <= n - x) {
          ok = 1; break;
        }
      }
      if (ok) {
        cout << t << endl;
        return 0;
      }
    }
    cout << -1 << endl;
  } else {
    ll res = -1;
    for (ll m = 0; m <= k / N; ++m) {
      for (ll D : {k - x, k - x + 1}) {
        ll l = 0, r = n;
        //k - x >= m(n + t)
        if (m) {
          r = min(r, (k - x) / m - n);
        }
        // D - m(n + t) <= x
        if (m) {
          l = max(l, (D - x + m - 1) / m - n);
        } else if (D > x) {
          l = r + 1;
        }
        //if (m == 0) cerr << D << ' ' << l << ' ' << r << endl;
        // D - m(n + t) <= t
        ll D1 = (D - m * n);
        if (D1 >= 0) {
          l = max(l, (D1 + m) / (m + 1));
        } else {
          l = max(l, D1 / (m + 1));
        }
        //if (m == 0) cerr << D << ' ' << l << ' ' << r << endl;
        // D - m(n + t) >= t + x - n
        ll D2 = D - x + n - m * n;
        if (D2 >= 0) {
          r = min(r, D2 / (m + 1));
        } else {
          r = min(r, (D2 - m) / (m + 1));
        }
        //if (m == 0) cerr << D << ' ' << l << ' ' << r << endl;
        if (l <= r) {
          res = max(res, r);
        }
      }
    }
    cout << res << endl;
  }
/*  ll l = 0, r = n;
  if (!ok(n, k, x, l, r)) {
    cout << -1 << endl;
    return 0;
  }
  while (r - l > 0) {
    ll m = (l + r) / 2 + 1;
    assert(m > l && m <= r);
    if (ok(n, k, x, m, r)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  assert(l == r);
  cout << r << endl;*/
  return 0;
}