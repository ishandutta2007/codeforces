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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vl a(n), c(n);
  ll d = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    d = __gcd(d, a[i]);
  }
//  cerr << "gcd: " << d << endl;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    assert(a[i] % d == 0);
    a[i] /= d;
  }
  // d = 1
  vl p, q;
  for (ll i = 2; i * i <= d; ++i) if (d % i == 0) {
    p.push_back(i);
    q.push_back(1);
    while (d % i == 0) {
      d /= i;
      q.back() *= i;
    }
  }
  if (d > 1) {
    p.push_back(d);
    q.push_back(d);
  }
  ll qmax = 1;
  for (ll x : q) {
//    cerr << x << endl;
    qmax = max(qmax, x);
  }
  if (qmax > k) {
    cout << -1 << endl;
    return 0;
  }
  vii v;
  for (int i = 0; i < n; ++i) {
    ll prod = 1;
    for (ll j : p) while (a[i] % j == 0) {
      a[i] /= j;
      prod *= j;
    }
//    cerr << "prod: " << prod << endl;
    v.emplace_back(c[i], prod);
  }
  const ll INF = 1e17;
  vl precmul(1 << p.size(), 1), minouterq(1 << p.size(), INF);
  for (int mask = 0; mask < precmul.size(); ++mask) {
    for (int i = 0; i < p.size(); ++i) {
      if (mask & (1 << i)) {
        precmul[mask] *= q[i];
      } else {
        minouterq[mask] = min(minouterq[mask], q[i]);
      }
    }
  }
  sort(v.begin(), v.end());
  vvl dyn(1 << p.size(), vl(p.size() + 1, INF));
  dyn[0][0] = 0;
  set<ll> useless;
  vl prec(1 << p.size(), 1);
  for (auto it : v) {
    ll cost = it.first, prod = it.second;
//    cerr << cost << ' ' << prod << endl;
    if (useless.count(prod)) continue;
    bool useful = false;
    vl factors(p.size(), 1);
    for (int i = 0; i < p.size(); ++i) {
      ll cur = prod;
      while (cur % p[i] == 0) {
        cur /= p[i];
        factors[i] *= p[i];
      }
    }
    for (int i = 0; i < p.size(); ++i) for (int mask = 0; mask < (1 << i); ++mask) {
      prec[mask | (1 << i)] = prec[mask] * factors[i];
    }
    for (int old = (int)dyn.size() - 2; old >= 0; --old) {
      for (int mask = 1; mask < (1 << p.size()); ++mask) if ((old | mask) != old) {
        if (prec[mask] <= k / precmul[mask]) {// && prec[mask] > k / precmul[mask] / minouterq[mask]) {
          int nmask = old | mask;
          for (int t = 0; t + 1 < dyn[old].size(); ++t) {
            ll ndyn = dyn[old][t] + cost;
            if (ndyn < dyn[nmask][t+1]) {
//              cerr << cost << ' ' << old << ' ' << nmask << ' ' << t + 1 << ' ' << ndyn << endl;
              dyn[nmask][t+1] = ndyn;
              useful = true;
            }
          }
        }
      }
    }
    if (!useful) {
      useless.insert(prod);
    }
  }
  ll res = INF;
  for (int i = 0; i < dyn.back().size(); ++i) if (dyn.back()[i] < INF) {
    res = min(res, dyn.back()[i] * i);
  }
  if (res >= INF) res = -1;
  cout << res << endl;
  return 0;
}