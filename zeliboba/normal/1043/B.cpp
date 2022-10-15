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
#include <chrono>
#include <random>
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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vi res;
  for (int k = 1; k <= n; ++k) {
    bool ok = 1;
    for (int i = k + 1; i < a.size(); ++i) {
      if (a[i] - a[i-1] != a[i-k] - a[i - k - 1]) ok = 0;
    }
    if (ok) res.push_back(k);
  }
  cout << res.size() << endl;
  for (int x : res) cout << x << ' ';
  cout << endl;
  return 0;
}