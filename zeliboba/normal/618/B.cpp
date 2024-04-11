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
  vvi v(n, vi(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> v[i][j];
  vi p(n);
  for (int t = 1; t <= n; ++t) for (int i = 0; i < n; ++i) if (p[i] == 0) {
    bool ok = 1;
    for (int j = 0; j < n; ++j) {
      if (v[i][j] != 0 && v[i][j] != t) ok = 0;
    }
    if (ok) {
      p[i] = t;
      for (int j = 0; j < n; ++j) v[i][j] = v[j][i] = 0;
      break;
    }
  }
  for (int i = 0; i < p.size(); ++i) {
    cout << p[i] << ' ';
  }
  return 0;
}