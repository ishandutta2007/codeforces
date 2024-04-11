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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1e9 + 7;

pii rem(int i, vi& pr, vi& nx) {
  pii res(pr[i], nx[i]);
  if (pr[i] >= 0) nx[pr[i]] = nx[i];
  if (nx[i] < pr.size()) pr[nx[i]] = pr[i];
  return res;
}

ll c2(ll x) {
  return x * (x - 1) / 2;
}

ll inter(pii a, pii b) {
  assert(a.first <= b.first && a.second <= b.second);
  if (a.second >= b.first) return c2(a.second - b.first);
  else return 0;
}

ll eval(const set<pii>& q, set<pii>::iterator it) {
  pii p1(-1, -1), p2((int)2e9, (int)2e9);
  if (it != q.begin()) {
    auto it1 = it; --it1;
    p1 = *it1;
  }
  auto it2 = it; ++it2;
  if (it2 != q.end()) {
    p2 = *it2;
  }
  return c2(it->second - it->first) - inter(*it, p2) - inter(p1, *it) + inter(p1, p2);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, k, L;
  cin >> n >> k >> L;
  ll res = 0;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    --a[i][2];
  }
  sort(a.begin(), a.end());
  int pri = -1;
  vector<vii> cols(k);
  vvi nx(k), pr(k);
  vi pos(n);
  for (int i = 0; i < n; ++i) {
    if (a[i][0] == pri) continue;
    ll mul = a[i][0] - pri;
    pri = a[i][0];
    for (int c = 0; c < k; ++c) {
      cols[c].clear();
      cols[c].emplace_back(-1, -1);
      cols[c].emplace_back(L, -1);
    }
    for (int j = i; j < n; ++j) cols[a[j][2]].emplace_back(a[j][1], j);
    vii bad;
    bool fail = 0;
    for (int c = 0; !fail && c < k; ++c) {
      if (cols[c].size() == 2) fail = 1;
      sort(cols[c].begin(), cols[c].end());
      pr[c].resize(cols[c].size()); 
      nx[c].resize(cols[c].size()); 
      for (int j = 0; j < cols[c].size(); ++j) {
        if (cols[c][j].second >= 0) pos[cols[c][j].second] = j;
        pr[c][j] = j - 1;
        nx[c][j] = j + 1;
        if (j + 1 < cols[c].size() && cols[c][j].first + 1 != cols[c][j + 1].first) {
          bad.emplace_back(cols[c][j].first + 1, cols[c][j + 1].first + 1);
        }
      }
    }
    if (fail) continue;
//    cerr << mul << endl;
    sort(bad.begin(), bad.end());
    vii v;
    if (!bad.empty()) {
      v.push_back(bad[0]);
      for (int i = 1; i < bad.size(); ++i) {
        if (bad[i].second <= v.back().second) continue;
        v.push_back(bad[i]);
      }
    }
    int nxi = a.back()[0];
    ll curs = c2(L + 1);
    set<pii> q;
    for (int j = 0; j < v.size(); ++j) {
      q.insert(v[j]);
      curs -= c2(v[j].second - v[j].first);
      if (j && v[j - 1].second >= v[j].first) curs += inter(v[j - 1], v[j]);
    }
    res = (res + curs % mod * mul % mod * (L - a.back()[0])) % mod;
//    cerr << "i: " << i << ' ' << mul << ' ' << curs << ' ' << (L - a.back()[0]) << endl;
    for (int j = n - 1; j > i; --j) {
      ll mul1 = mul * (nxi - a[j - 1][0]) % mod;
      nxi = a[j - 1][0];
      pii p = rem(pos[j], pr[a[j][2]], nx[a[j][2]]);
      p.first = cols[a[j][2]][p.first].first + 1;
      p.second = cols[a[j][2]][p.second].first + 1;
      auto it = q.lower_bound(p);
      bool changed = true;
      if (it != q.end() && it->first == p.first && it->second >= p.second) changed = false;
      if (it != q.begin()) {
        auto it1 = it; --it1;
        if (it1->second >= p.second) changed = false;
      }
      if (changed) {
        while (it != q.end()) {
          if (it->second <= p.second) {
            curs += eval(q, it);
            q.erase(it++);
          } else break;
        }
        it = q.insert(p).first;
        curs -= eval(q, it);
      }
      res = (res + curs % mod * mul1) % mod;
//      cerr << mul1 << ' ' << i << ' ' << j << ' ' << curs << endl;
    }
  }
  cout << (res + mod) % mod << endl;
  return 0;
}