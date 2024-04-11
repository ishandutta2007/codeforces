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

int sz(ll n) {
  ll t = 0, pw7 = 1;
  while (pw7 < n) {
    ++t;
    pw7 *= 7;
  }
  return max(t, 1LL);
}

vi f(int x, int s) {
  vi v(s);
  for (int i = 0; i < s; ++i) {
    v[i] = x % 7;
    x /= 7;
  }
  return v;
}

int main() {
  int n, m;
  cin >> n >> m;
  if (sz(n) + sz(m) > 7) {
    cout << 0 << endl;
    return 0;
  }
  int res = 0;
  for (int x = 0; x < n; ++x) {
    vi v = f(x, sz(n));
    for (int y = 0; y < m; ++y) {
      vi v1 = f(y, sz(m));
      vi was(7, 0);
      for (int i : v) was[i]++;
      for (int i : v1) was[i]++;
      bool ok = 1;
      for (int i : was) if (i > 1) ok = 0;
      if (ok) ++res;
    }
  }
  cout << res << endl;
  return 0;
}