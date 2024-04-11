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
  int n, m;
  cin >> n >> m;
  vi v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());
  v.push_back(1e9);
  vi h;
  for (int i = 0; i < m; ++i) {
    int x1,x2,y;
    cin >> x1 >> x2 >> y;
    if (x1 == 1) {
      h.push_back(x2);
    }
  }
  sort(h.begin(), h.end());
  int res = n + m;
  int it = 0;
  for (int i = 0; i < v.size(); ++i) {
    while (it < h.size() && h[it] < v[i]) ++it;
    res = min(res, i + (int)h.size() - it);
  }
  cout << res << endl;
  return 0;
}