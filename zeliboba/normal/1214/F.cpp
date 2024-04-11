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
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

ll m;
ll dist(ll i, ll j) {
  ll d = abs(i - j);
  return min(d, m - d);
}

vi nx;

vi frange(const vii& a, int l, int r, bool onemore = false) {
  if (l > r) return vi();
  auto it = lower_bound(a.begin(), a.end(), pii(l, 0)) - a.begin();
  vi v;
  for (int i = it % a.size(), t = 0; t < (int)a.size(); i = nx[i], t++) {
    bool good = a[i].first >= l && a[i].first <= r;
    if (onemore || good) v.push_back(i);
    if (!good) break;
  }
  return v;
}

vi range(const vii& a, int l, int r) {
  if (l > r) {
    auto v = frange(a, l, m - 1);
    for (auto x : frange(a, 0, r, true)) v.push_back(x);
    return v;
  } else return frange(a, l, r, true);
}

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  m = 10000;
  int n = 200000;
  if (!DEBUG) cin >> m >> n;
  nx.resize(n);
  for (int i = 0; i < n; ++i) nx[i] = (i + 1) % n;
  vii a(n), b(n);
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) cin >> a[i].first;
    else a[i].first = 1;//rand() % m + 1;
    --a[i].first;
    a[i].first *= 2;
    a[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) cin >> b[i].first;
    else b[i].first = rand() % m + 1;
    --b[i].first;
    b[i].first *= 2;
    b[i].second = i;
  }
  m *= 2;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vl x(n), y(n);
  for (int i = 0; i < n; ++i) {
    x[i] = a[i].first;
    y[i] = b[i].first;
  }
  ll best = 0, s = 0, add = 0;
  vl dynx(n);
  vi sign(n);
  for (int i = 0; i < n; ++i) {
    dynx[i] = dist(y[i], y[(i + 1) % n]);
  }
  vvi bad(n);
  for (int i = 0; i < n; ++i) {
    ll d = dist(x[i], y[i]);
    s += d;
    if (dist(y[(i + 1) % n], x[i]) > d) sign[i] = 1;
    else sign[i] = -1;
    add += sign[i] * dynx[i];
    //for (int j = 0; j < n; ++j) bad[i].push_back(j);
    if (dynx[i]) {
      ll a1 = (y[i] + 1) % m, b1 = y[(i + 1) % n];
      ll a2 = (a1 + m / 2) % m, b2 = (b1 + m / 2) % m;
      if (a1 + m / 2 < b1) {
        swap(a1, b1);
        swap(a2, b2);
      }
      //cerr << i << ' ' << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << endl;
      for (int x : range(a, a1, b1)) {
        bad[(i + 1 - x + n) % n].push_back(i);
      }
      for (int x : range(a, a2, b2)) {
        bad[(i + 1 - x + n) % n].push_back(i);
      }
    }
  }
  ll mi = s;
  int sumsz = 0;
  for (int t = 1; t < n; ++t) {
    sumsz += bad[t].size();
    sort(bad[t].begin(), bad[t].end());
    bad[t].resize(unique(bad[t].begin(), bad[t].end()) - bad[t].begin());
    for (int i : bad[t]) {
      add -= sign[i] * dynx[i];
      int j = (i - t + 1 + n) % n;
      //cerr << t << ' ' << i << ' ' << j << endl;
      s += dist(x[j], y[nx[i]]) - dist(x[j], y[i]);
      sign[i] = 0;
    }
    /*for (int i = 0; i < n; ++i) if (sign[i]) {
      int j = (i - t + 1 + n) % n;
      //cerr << x[j] << ' ' << y[i] << ' ' << y[(i + 1) % n] << ' ' << sign[i] << endl;
      assert(dist(x[j], y[nx[i]]) - dist(x[j], y[i]) == dynx[i] * sign[i]);
    }*/
    //cerr << "s " << s/2 << ' ' << add/2 << endl;
    s += add;
    if (mi > s) {
      mi = s;
      best = t;
    }
    for (int i : bad[t]) {
      int j = (i - t + n) % n;
      sign[i] = dist(y[nx[i]], x[j]) > dist(y[i], x[j]) ? 1 : -1;
      add += sign[i] * dynx[i];
    }
  }
  cerr << sumsz << endl;
  vi res(n);
  for (int i = 0; i < n; ++i) {
    res[a[i].second] = b[(i + best) % n].second + 1;
  }
  assert(mi % 2 == 0);
  cout << mi / 2 << endl;
  for (int x : res) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}