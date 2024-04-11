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
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef pair<double, double> pdd;
typedef vector<string> vs;

vll prec(1000000, pll(-1, -1));

ll p3(ll x) {
  return x*x*x;
}

ll sq3(ll y) {
  ll t = pow(y, 1./3.);
  while (p3(t) > y) --t;
  while (p3(t+1) <= y) ++t;
  return t;
}

pll f(ll y) {
  if (y < (ll)prec.size() && prec[y].first != -1) {
    return prec[y];
  }
  ll t = sq3(y);
  ll t3 = p3(t);
  pll a = f(y - t3);
  pll b = f(t3 - 1 - p3(t-1));
  a.second += t3;
  b.second += p3(t-1);
  pll res = max(a, b);
  res.first++;
  return res;
}

int main() {
  prec[0] = pll(0, 0);
  prec[1] = pll(1, 1);
  for (int i = 2; i < (int)prec.size(); ++i) prec[i] = f(i);
  ll m;
  cin >> m;
  pll res = f(m);
  cout << res.first << ' ' << res.second << endl;
  return 0;
}