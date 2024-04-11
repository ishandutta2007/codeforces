#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <unordered_set>
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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vii v(m);
  unordered_set<ll> was;
  for (int i = 0; i < m; ++i) {
    cin >> v[i].first >> v[i].second;
    if (v[i].first > v[i].second) {
      swap(v[i].first, v[i].second);
    }
    --v[i].first;
    --v[i].second;
    was.insert(v[i].first * (ll)n + v[i].second);
  }
  random_shuffle(v.begin(), v.end());
  bool yes = false;
  for (int d = 1; d < n; ++d) if (n % d == 0) {
    bool ok = true;
    for (pii p : v) {
      int a = (p.first + d) % n, b = (p.second + d) % n;
      if (a > b) swap(a, b);
      if (!was.count(a * (ll)n + b)) {
        ok = false;
        break;
      }
    }
    if (ok) {
//      cerr << d << endl;
      yes = true;
      break;
    }
  }
  if (yes) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}