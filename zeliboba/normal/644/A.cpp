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
  int n, a, b;
  cin >> n >> a >> b;
  if (n > a*b) {
    cout << -1 << endl;
    return 0;
  }
  vvi res(a, vi(b));
  int c0 = 1, c1 = 2;
  for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) {
    if ((i + j) % 2) {
      if (c1 <= n) res[i][j] = c1;
      c1 += 2;
    } else {
      if (c0 <= n) res[i][j] = c0;
      c0 += 2;
    }
  }
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      cout << res[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}