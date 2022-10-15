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
int t, s;
int Q;
vi pos(10);

bool same(const vi& v) {
  for (int i = 0; i + 1 < v.size(); ++i) if (v[i] != v[i + 1]) return false;
  return true;
}

void done() {
  cout << "done" << endl;
  if (DEBUG) {
    assert(same(pos) && pos[0] == t);
  } else {
    exit(0);
  }
}

vi next(vi v) {
  if (DEBUG) {
    --Q;
    assert(Q >= 0);
  }
  assert(!v.empty());
  cout << "next";
  for (int x : v) cout << ' ' << x;
  cout << endl;
  if (DEBUG) {
    for (int x : v) {
      pos[x]++;
      if (pos[x] == t + s) pos[x] = t;
    }
    return pos;
  } else {
    vi pos(10, -1);
    int c = 0, g = 0;
    while (c < 10) {
      string s;
      cin >> s;
      c += s.size();
      for (int i = 0; i < s.size(); ++i) {
        pos[s[i]-'0'] = g;
      }
      ++g;
    }
    return pos;
  }
}

void solve() {
  if (DEBUG) {
    pos.assign(pos.size(), 0);
    Q = 3 * (t + s);
  }
  vi all(10);
  for (int i = 0; i < 10; ++i) all[i] = i;
  vi pos(10, 0);
  while (true) {
    pos = next(vi(1, 0));
    pos = next({0, 1});
    if (pos[0] == pos[1]) {
      while (!same(pos)) {
        pos = next(all);
      }
      done();
      break;
    }
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) {
    for (s = 1; s <= 100; ++s) for (t = 1; t <= 100; ++t) {
      solve();
    }
    for (s = 990; s <= 1000; ++s) for (t = 990; t <= 1000; ++t) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}