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

const int DEBUG = 0;
vi hidden;
vi start;

int ask(int l, int r) {
  cout << "? " << l + 1 << ' ' << r + 1 << endl;
  fflush(stdout);
  int t = 0;
  if (!DEBUG) {
    cin >> t;
  } else {
    if (rand() % 2) {
      for (int i = 0; i <= r; ++i) hidden[i] ^= 1;
    } else {
      for (int i = l; i < (int)hidden.size(); ++i) hidden[i] ^= 1;
    }
    for (int i : hidden) t += i;
  }
  return t;
}

int rem(int l, int r, int t, int n) {
  int res = -1;
  int len = n - (r - l + 1);
  assert(len % 2 == 1);
  while (1) {
    ask(l, r);
    int cur = ask(l, r);
    if (cur != t) {
      int d = t - cur + len;
      assert(d % 2 == 0 && d >= 0 && d / 2 <= t);
      res = d / 2;
    } else if (res >= 0) {
      return res;
    }
  }
  return res;
}

void solve(int n0) {
  int n = n0, t = 0;
  if (!DEBUG) cin >> n >> t;
  else {
    start.assign(n, 0);
    for (int i = 0; i < n; ++i) start[i] = rand() % 2;
    hidden = start;
    for (int i : hidden) t += i;
  }
  vi res(n);
  if (n == 1) {
    res[0] = t;
  } else if (n % 2 == 0) {
    for (int i = 0; i < n; ++i) {
      res[i] = t - rem(i, i, t, n);
    }
  } else {
    vi s(n);
    for (int i = 0; i + 1 < n; ++i) {
      s[i] = t - rem(i, i + 1, t, n);
    }
    for (int i = 0; i < n; i += 2) {
      res[i] = t;
      for (int j = 0; j < i; j += 2) res[i] -= s[j];
      for (int j = i + 1; j < n; j += 2) res[i] -= s[j];
    }
    for (int i = 1; i < n; i += 2) {
      res[i] = s[i - 1] - res[i - 1];
    }
  }
  if (DEBUG) assert(start == res);
  cout << "! ";
  for (int i : res) cout << i;
  cout << endl;
  fflush(stdout);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) { 
    for (int n = 1; n <= 200; ++n) {
      cerr << n << endl;
      for (int t = 0; t < 1000; ++t)
        solve(n);
    }
  } else {
    solve(1);
  }
  return 0;
}