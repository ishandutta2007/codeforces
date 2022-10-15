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
//const int mod = ;

const int N = 1 << 18;
ll mi[2 * N], ma[2 * N];

void put(int i, ll a, ll b) {
  i += N;
  while (i) {
    mi[i] = min(mi[i], a);
    ma[i] = max(ma[i], b);
    i /= 2;
  }
}

ll getmi(int l, int r) {
  l += N;
  r += N;
  ll res = 1e18;
  while (l <= r) {
    if (l & 1) {
      res = min(res, mi[l]);
      ++l;
    }
    if (!(r & 1)) {
      res = min(res, mi[r]);
      --r;
    }
    l /= 2;
    r /= 2;
  }
  return res;
}

ll getma(int l, int r) {
  l += N;
  r += N;
  ll res = 0;
  while (l <= r) {
    if (l & 1) {
      res = max(res, ma[l]);
      ++l;
    }
    if (!(r & 1)) {
      res = max(res, ma[r]);
      --r;
    }
    l /= 2;
    r /= 2;
  }
  return res;
}

vl v;

int lb(ll x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

ll solve(ll l, ll r, const vii& ts) {
  for (int i = 0; i < 2 * N; ++i) {
    mi[i] = 1e18;
    ma[i] = 0;
  }
  vl d(ts.size());
  ll maxd = 0;
  for (int i = 0; i < ts.size(); ++i) {
    if (ts[i].first > r) break;
    if (ts[i].first <= l) d[i] = 0;
    else {
      d[i] = min(getmi(lb(ts[i].first), N - 1), ts[i].first - getma(0, lb(ts[i].first)));
//      d[i] = max(0LL, ts[i].first - ma);
    }
//    ma = max(ma, ts[i].first + ts[i].second - d[i]);
    put(lb(ts[i].first + ts[i].second), d[i], ts[i].first + ts[i].second - d[i]);
    maxd = max(maxd, d[i]);
  }
  return maxd;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl a(n), c(n);
  vii ts(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> c[i];
    v.push_back(a[i] + c[i]);
    v.push_back(a[i]);
    ts[i] = pii(a[i], c[i]);
    sum += c[i];
  }
  sort(v.begin(), v.end());
  sort(ts.begin(), ts.end());
  cout << sum + solve(ts[0].first, ts.back().first, ts) << endl;
  //cout << sum + min(solve(ts[0].first, ts.back().first, ts), solve(ts[0].first, a[0], ts) + solve(a[0], ts.back().first, ts)) << endl;
  return 0;
}