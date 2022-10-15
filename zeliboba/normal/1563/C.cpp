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

vi res;

void rev(vi& v, int l) {
  assert(l % 2);
  res.push_back(l);
  for (int i = 0; i < l / 2; ++i) swap(v[i], v[l - i - 1]);
}

int fnd(const vi& v, int a) {
  for (int i = 0; i < v.size(); ++i) if (v[i] == a) return i;
  return 0;
}

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1000000;
  if (!DEBUG) cin >> T;
  for (int test = 0; test < T; ++test) {
    res.clear();
    int n = rand() % 10 * 2 + 1;
    if (!DEBUG) cin >> n;
    vi a(n);
    if (!DEBUG) for (int i = 0; i < n; ++i) cin >> a[i];
    else {
      a.clear();
      vi b[2];
      for (int i = 0; i < n; ++i) b[i % 2].push_back(i);
      random_shuffle(b[0].begin(), b[0].end());
      random_shuffle(b[1].begin(), b[1].end());
      for (int i = 0; i < n; ++i) {
        a.push_back(b[i%2].back() + 1);
        b[i%2].pop_back();
      }
    }
    bool fail = 0;
    for (int i = 0; i < n; ++i) if (a[i] % 2 == i % 2) fail = 1;
    if (fail) {
      cout << -1 << '\n';
      continue;
    }
    for (int x = n; x > 1; x -= 2) {
      int i = fnd(a, x);
      if (i != 0) rev(a, i + 1);
      i = fnd(a, x - 1);
      if (i != 1) rev(a, i);
      rev(a, i + 2);
      i = fnd(a, x);
      assert(i > 0 && a[i - 1] == x - 1);
      rev(a, i + 1);
      rev(a, x);
      assert(a[x - 1] == x && a[x - 2] == x - 1);
    }
    cout << res.size() << '\n';
    for (int x : res) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}