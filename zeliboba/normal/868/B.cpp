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
  int h, m, s, t1, t2;
  cin >> h >> m >> s >> t1 >> t2;
  m = (m / 5 + 11) % 12 + 1;
  s = (s / 5 + 11) % 12 + 1;
  if (t1 > t2) swap(t1, t2);
  bool in = 1, out = 1;
  if (t1 <= h && h < t2) {
    in = 0;
  } else {
    out = 0;
  }
  if (t1 <= m && m < t2) {
    in = 0;
  } else {
    out = 0;
  }
  if (t1 <= s && s < t2) {
    in = 0;
  } else {
    out = 0;
  }
  if (in || out) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}