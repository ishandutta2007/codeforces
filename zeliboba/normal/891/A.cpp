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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  int c1 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c1 += a[i] == 1;
  }
  int d = a[0];
  bool hasneig = 0;
  for (int i = 1; i < n; ++i) {
    d = __gcd(d, a[i]);
    hasneig |= __gcd(a[i-1], a[i]) == 1;
  }
  if (d != 1) {
    cout << "-1\n";
    return 0;
  }
  if (hasneig || n == 1) {
    cout << n - c1 << endl;
    return 0;
  }
  vii v(1, pii(a[0], 0));
  int res = n - 1;
  for (int i = 1; i < n; ++i) {
    vii nv = v;
    for (int j = 0; j < nv.size(); ++j) {
      nv[j].second++;
      nv[j].first = __gcd(nv[j].first, a[i]);
    }
    nv.emplace_back(a[i], 0);
    sort(nv.begin(), nv.end());
    v.clear();
    for (pii p : nv) {
      if (v.empty() || v.back().first != p.first) v.push_back(p);
    }
//    for (pii p : v) cerr << i << ' ' << a[i] << ' ' << p.first << ' ' << p.second << endl;
    if (v[0].first == 1) res = min(res, v[0].second);
  }
  cout << res + n - 1 << endl;
  return 0;
}