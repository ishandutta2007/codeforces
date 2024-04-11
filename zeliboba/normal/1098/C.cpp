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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

vi p;

ll calcma(ll n) {
  return n * (n + 1) / 2;
}

vl calcmi(ll n, ll d) {
/*  if (n <= 0) return 0;
  if (n == 1) return 1;
  if (d == 1) return n * (n + 1) / 2;
  return n + calcmi()*/
  vl res(n + 1, 0);
  res[1] = 1;
  if (d == 1) {
    for (ll i = 2; i < (int)res.size(); ++i) {
      res[i] = calcma(i);
    }
  } else {
    for (ll i = 2; i < (int)res.size(); ++i) {
      ll rem = i - 1;
      res[i] = i + (d - rem % d) * res[rem / d] + (rem % d) * res[rem / d + 1];
    } 
  }
  return res;
}

void dfs(int v, ll n, ll s, ll d, const vl& mi) {
//  cerr << v << ' ' << n << ' ' << s << ' ' << d << endl;
  assert(s <= calcma(n) && s >= mi[n]);
  s -= n;
  if (n <= 1) {
    assert(s == 0);
    return;
  }
  if (d == 1) {
    p[v+1] = v;
    dfs(v + 1, n - 1, s, d, mi);
    return;
  }
  --n;
  int ind = v + 1;
  for (int t = 0; t < d; ++t) {
    if (n <= 0) {
      assert(n == 0 && s == 0);
      break;
    }
    assert(ind >= 0 && ind < (int)p.size());
    p[ind] = v;
    if (t == d - 1) {
      dfs(ind, n, s, d, mi);
      break;
    }
    int cnt = d - t - 1;
    int l = n / (cnt + 1), r = n + 1;
    while (r - l > 1) {
      int sz = (l + r) / 2;
      int rem = n - sz;
      ll summi = mi[sz] + (cnt - rem % cnt) * mi[rem / cnt] + (rem % cnt) * mi[rem / cnt + 1];
      if (summi <= s) {
        l = sz;
      } else {
        r = sz;
      }
    }
    int sz = l;
    int rem = n - sz;
    ll othermi = (cnt - rem % cnt) * mi[rem / cnt] + (rem % cnt) * mi[rem / cnt + 1];
    ll summi = mi[sz] + othermi;
    assert(summi <= s);
    ll s1 = min(calcma(sz), s - othermi);
    dfs(ind, sz, s1, d, mi);
    n = rem;
    ind += sz;
    s -= s1;
  }
}

void solve(ll n, ll s) {
  if (s < 2 * n - 1 || s > calcma(n)) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  p.assign(n, 0);
  ll l = 0, r = n - 1;
  while (r - l > 1) {
//    cerr << l << ' ' << r << endl;
    ll m = (l + r) / 2;
    vl v = calcmi(n, m);
    if (v[n] <= s) {
      r = m;
    } else {
      l = m;
    }
  }
  ll d = r;
  vl mi = calcmi(n, d);
//  cerr << n << ' ' << s << ' ' << d << endl;
  dfs(0, n, s, d, mi);
  for (int i = 1; i < n; ++i) {
    cout << p[i] + 1 << ' ';
  }
  cout << endl;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0) for (int n = 2; n <= 100; ++n) {
    for (int s = 1; s <= 10000; ++s) {
      solve(n, s);
    }
  }
  //solve(3e5, 1e10);
  ll n, s;
  cin >> n >> s;
  solve(n, s);
  return 0;
}