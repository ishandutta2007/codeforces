#include <cstdio>
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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vvi d(3, vi(n + 1, 1e9));
  d[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) for (int t = 0; t < 3; ++t) if (t != j || t + j == 0) {
      if (t && !(a[i] & (1 << (t - 1)))) continue;
//      cerr << i << ' ' << j << ' ' << t << ' ' << d[j][i] << endl;
      int add = t == 0;
      d[t][i+1] = min(d[t][i+1], d[j][i] + add);
    }
  }
  cout << min(d[1].back(), min(d[2].back(), d[0].back())) << endl;
  return 0;
}