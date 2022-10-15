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

vl calc(string s, int add, ll& res) {
  int n = s.size();
  vl prec(n + 1);
  prec[1] = 1;
  for (ll i = 2; i < prec.size(); ++i) {
    prec[i] = prec[i - 1] + i * (i + 1) / 2;
  }
  vii v;
  for (int i = 0; i < n; ++i) if (s[i]) {
    int j = i;
    for (; j < n && s[j]; ++j) {}
    v.emplace_back(j - i, i);
    if (add) res += prec[j - i] - (j - i);
    i = j - 1;
  }
  vii a;
  vl todo;
  for (pii p : v) {
    int it = (int)a.size() - 1;
    for (ll l = 1; l <= p.first; ++l) {
      while (it >= 0 && a[it].first < l + add) --it;
      ll len = it == -1 ? p.second + 1 : p.second - (a[it].second + a[it].first - l - add);
      if (l == p.first) {
        todo.push_back(add ? l * len : len);
      } else {
        res += l * (len - 1);
      }
    }
    while (!a.empty() && a.back().first <= p.first) a.pop_back();
    a.push_back(p);
  }
  return todo;
}

ll stupid(string s) {
  ll res = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) {
    int ma = 0;
    for (int t = i; t <= j; ++t) if (s[t]) {
      int r = t;
      while (r <= j && s[r]) ++r;
      ma = max(ma, r - t);
      t = r - 1;
    }
    res += ma;
  }
  return res;
}

const int DEBUG = 0;

void solve(string s) {
  ll res = 0;
  vl x = calc(s, 1, res);
//  cerr << res << endl;
  reverse(s.begin(), s.end());
  vl y = calc(s, 0, res);
//  cerr << res << endl;
  reverse(y.begin(), y.end());
  for (int i = 0; i < x.size(); ++i) res += x[i] * y[i];
  cout << res << '\n';
  if (DEBUG) {
    assert(res == stupid(s));
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) {
    for (int n = 1; n <= 16; ++n) for (int mask = 0; mask < (1 << n); ++mask) {
      string s(n, 0);
      for (int i = 0; i < n; ++i) if (mask & (1 << i)) s[i] = 1;
      solve(s);
    }
  }
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) s[i] -= '0';
  solve(s);
  return 0;
}