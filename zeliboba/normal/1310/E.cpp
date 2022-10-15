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
const int mod = 998244353;

int MAX = 2020;

vi f(vi v) {
  ll s = 0;
  for (int x : v) s += x;
  if (s > MAX) return vi(MAX + 1, 1);
  sort(v.rbegin(), v.rend());
  int it = 1;
  vi res;
  for (int c : v) {
    for (int i = 0; i < c; ++i) {
      res.push_back(it);
    }
    ++it;
  }
  return res;
}

vi f(vi v, int k) {
  for (int i = 0; i < k; ++i) {
    if (v.size() > MAX) return v;
    v = f(v);
  }
  return v;
}

int eval(vi v, int k) {
  return f(v, k).size();
}

vi cur;
vvi tot;
void rec(int mi, int k) {
  if (mi <= 30) rec(mi + 1, k);
  cur.push_back(mi);
  if (eval(cur, k) <= MAX) {
    tot.push_back(cur);
    rec(mi, k);
  }
  cur.pop_back();
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
//  cerr << eval({2}, 4) << endl;
//  cerr << eval({3}, 4) << endl;
//  cerr << eval({80}, 3) << endl;
//  cerr << eval(vi(30, 1), 3) << endl;
//  rec(1, 4);
//  cerr << tot.size() << endl;
  int n, k;
  cin >> n >> k;
  if (k >= 4) {
    MAX = n;
    rec(1, k);
    cout << tot.size() << endl;
  } else if (k == 1) {
    vi d(n + 1);
    d[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n - i; ++j) {
        d[j + i] = (d[j + i] + d[j]) % mod;
      }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) res = (res + d[i]) % mod;
    cout << res << endl;
  } else if (k == 2) {
    vvi d(80, vi(n + 1));
    d[0][0] = 1;
    for (int i = n; i > 0; --i) {
      for (int c = 0; c + 1 < d.size(); ++c) for (int j = 0; j + (c + 1) * i < d[c].size(); ++j) if (d[c][j]) {
        d[c + 1][j + (c + 1) * i] = (d[c + 1][j + (c + 1) * i] + d[c][j]) % mod;
      }
    }
    ll res = 0;
    for (int c = 1; c < d.size(); ++c) for (int i = 1; i <= n; ++i) res = (res + d[c][i]) % mod;
    cout << res << endl;
  } else {
    vector<vvi> d(30, vvi(500, vi(n + 1)));
    d[0][0][0] = 1;
    for (int i = min(n, 80); i > 0; --i) {
      for (int c = 0; c + 1 < d.size(); ++c) for (int s = 0; s + i * (c + 1) < d[c].size(); ++s) for (int j = 0; j <= n; ++j) if (d[c][s][j]) {
        int s1 = s + i * (c + 1);
        int j1 = j + (c + 1) * (i + 1) * i / 2 + i * s;
        if (j1 > n) break;
        d[c + 1][s1][j1] = (d[c + 1][s1][j1] + d[c][s][j]) % mod;
      }
    }
    ll res = 0;
    for (int c = 1; c < d.size(); ++c) for (int s = 0; s < d[c].size(); ++s) for (int i = 1; i <= n; ++i) {
      res = (res + d[c][s][i]) % mod;
//      if (d[c][s][i]) cerr << c << ' ' << s << ' ' << i << ' ' << d[c][s][i] << endl;
    }
    cout << res << endl;
  }
  return 0;
}