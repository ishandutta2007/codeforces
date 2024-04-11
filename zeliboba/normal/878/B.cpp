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

int n, k, m;

ll eval(const vii & a) {
  ll s = 0;
  for (pii p : a) s += p.second;
  return s;
}

ll f(vii a, vii b) {
  reverse(b.begin(), b.end());
  for (pii p : b) {
    if (a.empty() || p.first != a.back().first) {
      a.push_back(p);
    } else {
      a.back().second += p.second;
    }
    a.back().second %= k;
    if (a.back().second == 0) a.pop_back();
  }
  return eval(a);
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  scanf("%d%d%d", &n, &k, &m);
  vi a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  vii v;
  for (int i = 0; i < a.size(); ++i) {
    if (v.empty() || a[i] != v.back().first) {
      v.emplace_back(a[i], 1);
    } else {
      v.back().second++;
    }
    if (v.back().second >= k) {
      v.back().second -= k;
      if (v.back().second == 0) v.pop_back();
    }
  }
  vii l, r;
  while (1) {
    int sz = l.size();
    if (v.size() == sz) {
      cout << f(l, r) << endl;
      return 0;
    }
    if (v.size() == sz + 1) {
      int rem = v[sz].second * (ll)m % k;
      if (rem) l.emplace_back(v[sz].first, rem);
      cout << f(l, r) << endl;
      return 0;
    }
    bool eq = v[sz].first == v.back().first;
    int sp = eq ? v[sz].second + v.back().second : 0;
//    cerr << eq << ' ' << sp << endl;
    if (eq && sp % k == 0) {
      l.push_back(v[sz]);
      r.push_back(v.back());
      v.pop_back();
    } else {
      ll d = sp / k * k;
      cout << eval(l) + eval(r) + (eval(v) - eval(l)) * (ll)m - d * (m - 1) << endl;
      return 0;
    }
  }
  return 0;
}