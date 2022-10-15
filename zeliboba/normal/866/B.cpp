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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi a(n), b(n), s(n);
  ll res = 0;
  vii v;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> a[i] >> b[i];
    sum += s[i];
    res += (ll)s[i] * a[i];
    v.emplace_back(a[i] - b[i], s[i]);
  }
  sort(v.begin(), v.end());
  ll cur = res;
  ll sp = 0;
  int rem = sum % k;
  for (int i = 0; i < n; ++i) {
//    cerr << v[i].first << ' ' << v[i].second << endl;
    if (v[i].first > 0) {
      int r = 0;
      if (sp % k < rem) {
        r = rem - sp % k;
      }
      if (rem == 0) r = (k - sp % k) % k;
      if (r <= v[i].second) {
        res = max(res, cur - r * (ll)v[i].first);
//        cerr << i << ' ' << r << ' ' << sp % k << ' ' << rem << ' ' << res << ' ' << cur << ' ' << r * v[i].first << endl;
      }
    } else {
      int r = v[i].second;
      ll sp1 = sp + v[i].second;
      if (sp1 % k < rem || rem == 0) {
        r -= sp1 % k;
      }
      if (r >= 0) {
        res = max(res, cur - r * (ll)v[i].first);
//        cerr << i << ' ' << r << ' ' << (sp + r) % k << ' ' << rem << ' ' << res << ' ' << cur << ' ' << r * v[i].first << endl;
      }
    }
    cur -= (ll)v[i].second * v[i].first;
    sp += v[i].second;
  }
//  cerr << cur << endl;
  res = max(res, cur);
  cout << res << endl;
  return 0;
}