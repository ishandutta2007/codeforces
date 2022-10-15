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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vii d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d.rbegin(), d.rend());
  for (int i = 0; i + 1 < n; ++i) {
    cout << 2 * d[i].second + 1 << ' ' << 2 * d[i + 1].second + 1 << '\n';
  }
  vi v(3 * n + 5, -1);
  for (int i = 0; i < n; ++i) v[i] = 2 * d[i].second + 1;
  for (int i = 0; i < n; ++i) {
    int ind = i + d[i].first - 1;
    assert(v[ind] != -1);
    int j = 2 * d[i].second + 2;
    cout << v[ind] << ' ' << j << '\n';
    if (v[ind + 1] == -1) v[ind + 1] = j;
  }
  return 0;
}