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

int g(const vii & v, int x) {
  int ma = -1e9;
  for (pii p : v) {
    if (p.first <= x) ma = max(ma, p.second);
  }
  return ma;
}

int f(vii v, int x) {
  int ma = -1e9;
  int it = v.size() - 1;
  for (int i = 1; i < v.size(); ++i) {
    int rem = x - v[i].first;
    while (it >= 0 && v[it].first > rem) --it;
    if (it < 0) break;
    ma = max(ma, v[i].second + v[min(it, i-1)].second);
    v[i].second = max(v[i].second, v[i-1].second);
  }
  return ma;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, c, d;
  cin >> n >> c >> d;
  vii a, b;
  for (int i = 0; i < n; ++i) {
    int t, p;
    string s;
    cin >> t >> p >> s;
    if (s == "C") {
      a.emplace_back(p, t);
    } else {
      b.emplace_back(p, t);
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int res = max(max(f(a, c), f(b, d)), g(a, c) + g(b, d));
  if (res < 0) {
    cout << 0 << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}