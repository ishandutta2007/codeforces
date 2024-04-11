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

bool in(int x) {
  return x >= 0 && x <= 9;
}

bool ok(int i, const vl& v, const vl& a) {
  int add = v[i] > 0 ? 1 : -1;
  return v[i] && in(a[i] + add) && in(a[i+1] + add);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  string a0, b0;
  cin >> n >> a0 >> b0;
  vl a(n), b(n);
  for (int i = 0; i < n; ++i) {
    a[i] = a0[i] - '0';
    b[i] = b0[i] - '0';
  }
  ll res = 0;
  bool fail = 0;
  vl v(n - 1);
  vl a1 = a;
  for (int i = 0; i + 1 < n; ++i) {
    res += abs(a[i] - b[i]);
    v[i] = b[i] - a[i];
    a[i + 1] += b[i] - a[i];
  }
  if (a.back() != b.back()) fail = 1;
  if (fail) {
    cout << -1 << endl;
    return 0;
  }
  a = a1;
  vii td;
  vi q, added(v.size());
  for (int i = 0; i < v.size(); ++i) if (ok(i, v, a)) {
//    cerr << i << endl;
    q.push_back(i);
    added[i] = 1;
  }
  while (!q.empty()) {
    int i = q.back();
    q.pop_back();
    added[i] = 0;
    int add = v[i] > 0 ? 1 : -1;
    while (ok(i, v, a)) {
      v[i] -= add;
      a[i] += add;
      a[i + 1] += add;
      td.emplace_back(i, add);
    }
    for (int j = max(0, i - 1); j <= min(i + 1, n - 2); ++j) {
      if (ok(j, v, a) && !added[j]) {
        q.push_back(j);
        added[j] = 1;
      }
    }
    if (td.size() > 100000) break;
  }
//  if (td.size() < res) res = -1;
  cout << res << endl;
  for (int i = 0; i < min(100000, (int)td.size()); ++i) {
    cout << td[i].first + 1 << ' ' << td[i].second << '\n';
  }
  return 0;
}