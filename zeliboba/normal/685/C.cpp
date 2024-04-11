#include <cstdio>
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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvl d(2, vl(2));
bool ok(ll a, ll & b, ll & c, const vvl &v) {
  d[0][0] = max(v[0][0]-a, a-v[3][1]);
  d[0][1] = min(v[0][1]-a, a-v[3][0]);
  d[1][0] = max(v[1][0]-a, a-v[2][1]);
  d[1][1] = min(v[1][1]-a, a-v[2][0]); // b-c
//  cerr << d[0][0] << ' ' << d[0][1] << ' ' << d[1][0] << ' ' << d[1][1] << endl;
  for (ll s1 = d[0][0]; s1 <= d[0][0] + 1; ++s1) for (ll s2 = d[1][0]; s2 <= d[1][0] + 1; ++s2) {
    b = (s1 + s2) / 2;
    c = (s1 - s2) / 2;
    vl x(4);
    x[0] = a+b+c;
    x[1] = a+b-c;
    x[2] = a-b+c;
    x[3] = a-b-c;
    bool ok = 1;
    for (int i = 0; i < 4; ++i) {
      if (x[i] < v[i][0] || x[i] > v[i][1]) ok = 0;
    }
    if (ok) return 1;
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  cin >> T;
  vvl t(4);
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    if (n == 1) {
      ll x,y,z;
      cin >> x >> y >> z;
      cout << x << ' ' << y << ' ' << z << '\n';
      continue;
    }
    //vl x0(n), y(n), z(n);
    for (int i = 0; i < 4; ++i) t[i].resize(n);
    for (int i = 0; i < n; ++i) {
      ll x,y,z;
      cin >> x >> y >> z;
      t[0][i] = x+y+z;
      t[1][i] = x+y-z;
      t[2][i] = x-y+z;
      t[3][i] = x-y-z;
    }
    vvl v(4, vl(2));
    for (int i = 0; i < 4; ++i) {
      sort(t[i].begin(), t[i].end());
      v[i][0] = t[i][0];
      v[i][1] = t[i].back();
    }
    ll l = -1, r = 3.1e18;
    ll rx = 0, ry = 0, rz = 0;
    vvl x(4, vl(2));
    while (r - l > 1) {
      ll m = (l + r) / 2;
      bool fail = 0;
      for (int i = 0; i < 4; ++i) {
        x[i][0] = v[i][1] - m;
        x[i][1] = v[i][0] + m;
        if (x[i][0] > x[i][1]) fail = 1;
      }
      ll mi2a = max(x[0][0] + x[3][0], x[1][0] + x[2][0]);
      if (mi2a % 2) mi2a++;
      ll ma2a = min(x[0][1] + x[3][1], x[1][1] + x[2][1]);
      if (mi2a > ma2a) {
        fail = 1;
      }
      ll a = mi2a / 2, b = 0, c = 0;
//      cerr << l << ' ' << r << ' ' << mi2a << ' ' << ma2a << ' ' << fail << endl;
      if (!ok(a, b, c, x)) {
        ++a;
        if (!ok(a, b, c, x)) {
          fail = 1;
        }
      }
//      cerr << l << ' ' << r << ' ' << fail << endl;
      if (fail) {
        l = m;
      } else {
        r = m;
        rx = a;
        ry = b;
        rz = c;
      }
    }
    cout << rx << ' ' << ry << ' ' << rz << '\n';
  }
  return 0;
}