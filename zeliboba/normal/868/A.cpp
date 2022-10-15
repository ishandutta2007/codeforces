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
  string s;
  int n;
  cin >> s >> n;
  vs v(n);
  bool e = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (v[i] == s) {
      cout << "YES\n";
      return 0;
    }
    if (v[i][1] == s[0]) b = 1;
    if (v[i][0] == s[1]) e = 1;
  }
  if (b && e) {
      cout << "YES\n";
  } else {
      cout << "NO\n";
  }
  return 0;
}