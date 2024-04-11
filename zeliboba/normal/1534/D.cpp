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

int n;
set<pii> w;

vi ask(int v) {
  cout << "? " << v + 1 << endl;
  vi d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    if (d[i] == 1) {
      w.insert(pii(min(v, i), max(v, i)));
    }
  }
  return d;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> n;
  vi d = ask(0);
  int rem = (n - 1) / 2;
  vi c(2);
  for (int i = 0; i < n; ++i) c[d[i] % 2]++;
  if (c[0] - 1 <= rem) {
    for (int i = 1; i < n; ++i) if (d[i] % 2 == 0) {
      ask(i);
    }
  } else {
    for (int i = 1; i < n; ++i) if (d[i] % 2 == 1) {
      ask(i);
    }
  }
  assert(w.size() == n - 1);
  cout << "!\n";
  for (pii p : w) cout << p.first + 1 << ' ' << p.second + 1 << endl;
  return 0;
}