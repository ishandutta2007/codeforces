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

vvi d(200005);
const int DEBUG = 0;

bool issq(ll x) {
  ll t = sqrt(x);
  while (t * t > x) --t;
  while (t * t < x) ++t;
  return t * t == x;
}

void solve() {
  int n = 1000;
  if (!DEBUG) cin >> n;
  vl x(n, -1);
  if (!DEBUG) {
    for (int i = 1; i < n; i += 2) {
      cin >> x[i];
    }
  } else {
    vl a(n);
    int prev = 0;
    for (int i = 0; i < n; ++i) {
      a[i] = prev + 1 + rand() % 3;
      prev = a[i];
    }
//    for (int j = 0; j < n; ++j) cerr << a[j]*a[j] << ' '; cerr << endl;
    for (int i = 1; i < n; i += 2) x[i] = a[i] * a[i] - a[i-1] * a[i-1];
  }
  ll ma = 1e18;
  for (int i = n - 1; i >= 0; i -= 2) {
    bool fail = 1;
    for (int sub : d[x[i]]) {
      int sum = x[i] / sub;
      if (sub % 2 != sum % 2) continue;
      ll a = (sum + sub) / 2, b = (sum - sub) / 2;
      if (a * a >= ma || b <= 0) continue;
      fail = 0;
      if (i + 1 < n) {
        x[i + 1] = ma - a * a;
      }
      ma = b * b;
      break;
    }
    if (fail) {
//      for (int j = 0; j < n; ++j) cerr << x[j] << ' '; cerr << endl;
      assert(!DEBUG);
      cout << "No\n";
      return;
    }
  }
  x[0] = ma;
  cout << "Yes\n";
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    cout << x[i] << ' ';
    s += x[i];
    assert(issq(s));
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 1; i * i < (int)d.size(); ++i) {
    for (int j = i * i + i; j < (int)d.size(); j += i) d[j].push_back(i);
  }
  solve();
  return 0;
}