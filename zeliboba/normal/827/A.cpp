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
  vs t(n);
  vvi x(n);
  int L = 0;
  vector<array<int, 2>> ts;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    int k;
    cin >> k;
    x[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> x[i][j];
      --x[i][j];
      L = max(L, (int)t[i].size() + x[i][j]);
      ts.push_back({x[i][j], i});
    }
//    cerr << i << ' ' << k << endl;
  }
  string res(L, 'a');
//  cerr << L << ' ' << res << ' ' << ts.size() << endl;
  sort(ts.begin(), ts.end());
  int r = 0;
  for (int it = 0; it < ts.size(); ++it) {
    int l = ts[it][0], i = ts[it][1];
    r = max(r, l);
    while (r < l + t[i].size()) {
//      cerr << l << ' ' << r << ' ' << i << ' ' << r-l << endl;
      res[r] = t[i][r-l];
      ++r;
    }
  }
  cout << res << endl;
  return 0;
}