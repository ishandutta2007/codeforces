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
  string a, b;
  cin >> n >> a >> b;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      ++res;
      if (i + 1 < n && a[i+1] != b[i+1] && a[i] != a[i+1]) ++i;
    }
  }
  cout << res << endl;
  return 0;
}