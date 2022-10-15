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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi a(n), c(100001);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++c[a[i]];
  }
  int res = 1;
  for (int d = 2; d < c.size(); ++d) {
    int s = 0;
    for (int i = d; i < c.size(); i += d) s += c[i];
    res = max(res, s);
  }
  cout << res << endl;
  return 0;
}