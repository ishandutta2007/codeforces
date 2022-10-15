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
int A;

bool ask(int x, int y) {
  cout << "? " << x << ' ' << y << endl;
  if (DEBUG) {
    return x % A < y % A;
  } else {
    string s;
    cin >> s;
    return s == "y";
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string start;
  for (int t = 1; ; ++t) {
    if (!DEBUG) {
      cin >> start;
      if (start != "start") return 0;
    } else {
      A = rand() % (int)(1e9);// - t + 1;
      if (t > 1e6) return 0;
    }
    int l = 1, r = 1e9, was = 0;
    int res = 1;
    for (int b = 0; b < 30; ++b) {
      if (ask(1 << (b + 1), 1 << b)) {
        was = 1;
        l = 1 << b;
        r = 1 << (b + 1);
        break;
      }
    }
    if (was) {
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask((m + 1) / 2, m)) {
          l = m;
        } else {
          r = m;
        }
      }
      res = r;
    }
    cout << "! " << res << endl;
    if (DEBUG && res != A) {
      cerr << A << ' ' << res << endl;
      assert(res == A);
    }
  }
  return 0;
}