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
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 5>> v(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) cin >> v[i][j];
  }
  vi res;
  if (n <= 200) for (int i = 0; i < n; ++i) {
    bool good = 1;
    for (int j = 0; j < n; ++j) for (int l = j + 1; good && l < n; ++l) if (j != i && l != i) {
      int s = 0;
      for (int k = 0; k < 5; ++k) s += (v[l][k] - v[i][k]) * (v[j][k] - v[i][k]);
      if (s > 0) {
        good = 0;
        break;
      }
    }
    if (good) res.push_back(i + 1);
  }
  cout << res.size() << endl;
  for (int x : res) cout << x << ' ';
  return 0;
}