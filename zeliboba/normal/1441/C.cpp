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

const int N = 1 << 12;
ll d[2][N][3001];

void umax(ll& x, ll y) {
  x = max(x, y);
}

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  //int n = 3000, k = 3000;
  for (int tt = 0; tt < (DEBUG ? 100 : 1); ++tt) {
  int n = 10, k = rand() % 10;
  if (!DEBUG) cin >> n >> k;
  vvi a(n);
  vi l(n);
  vl sum(n);
  for (int i = 0; i < n; ++i) {
    //int t = 300;
    int t = 1 + rand() % 10;
    if (!DEBUG) cin >> t;
    a[i].resize(t);
    l[i] = t;
    for (int j = 0; j < t; ++j) {
      if (!DEBUG) cin >> a[i][j];
      else a[i][j] = j > 0 ? a[i][j - 1] + rand() % 5 : rand() % 2;
      sum[i] += a[i][j];
    }
  }
  int pw = 1;
  while (pw < n) pw *= 2;
  while (l.size() < pw) {
    l.push_back(0);
    sum.push_back(0);
  }
  memset(d[0], 0, sizeof(d[0]));
  int pr = 0, nx = 1;
  while (pw > 1) {
    pw /= 2;
    for (int s = 0; s < l.size(); s += 2 * pw) {
      memcpy(d[nx][s], d[pr][s], sizeof(d[nx][s]));
      memcpy(d[nx][s + pw], d[pr][s], sizeof(d[nx][s]));
      for (int i = s; i < s + pw; ++i) for (int j = k; j >= l[i]; --j) {
        umax(d[nx][s + pw][j], d[nx][s + pw][j - l[i]] + sum[i]);
      }
      for (int i = s + pw; i < s + 2 * pw; ++i) for (int j = k; j >= l[i]; --j) {
        umax(d[nx][s][j], d[nx][s][j - l[i]] + sum[i]);
      }
    }
    swap(pr, nx);
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll s = 0;
    for (int j = 0; j < min(k + 1, (int)a[i].size() + 1); ++j) {
      res = max(res, d[pr][i][k - j] + s);
//      cerr << res << ' ' << i << ' ' << j << ' ' << s << ' ' << d[pr][i][k - j] << endl;
      if (j < a[i].size()) s += a[i][j];
    }
  }
  cout << res << endl;
  if (DEBUG) {
    vl v(k + 1);
    for (int i = 0; i < n; ++i) {
      ll s = 0;
      vl res = v;
      for (int j = 0; j < min(k + 1, (int)a[i].size() + 1); ++j) {
        vl v1 = v;
        for (int t = k; t >= j; --t) {
          v1[t] = max(v1[t], v1[t - j] + s);
        }
        for (int t = 0; t <= k; ++t) res[t] = max(res[t], v1[t]);
        if (j < a[i].size()) s += a[i][j];
      }
      v = res;
    }
    cerr << v[k] << endl;
    if (v[k] != res) {
      cout << n << ' ' << k << endl;
      for (int i = 0; i < n; ++i) {
        for (int x : a[i]) cout << x << ' '; cout << endl;
      }
    }
    assert(v[k] == res);
  }
  }
  return 0;
}