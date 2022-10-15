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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
    --f[i];
  }
  bool ok = 1;
  int m = 0;
  vi v, ind(n);
  for (int i = 0; i < n; ++i) {
    if (f[i] == i) {
      ind[i] = m;
      ++m;
      v.push_back(i);
    }
    if (f[f[i]] != f[i]) {
      ok = 0;
      break;
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  cout << m << endl;
  for (int i = 0; i < n; ++i) cout << ind[f[i]] + 1 << ' '; cout << endl;
  for (int i = 0; i < m; ++i) cout << v[i] + 1 << ' '; cout << endl;
  return 0;
}