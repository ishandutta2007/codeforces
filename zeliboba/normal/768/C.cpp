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

int c[2][1025];

int main() {
  std::ios::sync_with_stdio(false);
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    c[0][a]++;
  }
  for (int t = 0; t < k; ++t) {
    int s = 0, tt = t % 2;
    memset(c[1-tt], 0, sizeof(c[1-tt]));
    for (int i = 0; i <= 1024; ++i) {
      if (s % 2 == 0) {
        c[1-tt][i ^ x] += (c[tt][i] + 1) / 2;
        c[1-tt][i] += c[tt][i] / 2;
      } else {
        c[1-tt][i ^ x] += c[tt][i] / 2;
        c[1-tt][i] += (c[tt][i] + 1) / 2;
      }
      s += c[tt][i];
    }
  }
  int tt = k % 2;
  int mi = 1e9, ma = 0;
  for (int i = 0; i < 1025; ++i) if (c[tt][i]) {
    mi = min(mi, i);
    ma = max(ma, i);
  }
  cout << ma << ' ' << mi << endl;
  return 0;
}