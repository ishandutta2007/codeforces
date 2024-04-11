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
  int n, k;
  cin >> n >> k;
  vii e;
  int res = 0;
  while (k * 2 < n) {
    for (int i = 0; i < k; ++i) {
      e.emplace_back(n - i - 1, n - i - 1 - k);
    }
    n -= k;
    res += 2;
  }
  for (int i = 1; i < n-k; ++i) {
    e.emplace_back(0, i);
    e.emplace_back(i, i + k);
  }
  for (int i = n - k; i < 1 + k; ++i) {
    e.emplace_back(0, i);
  }
  if (k + 1 == n) res += 2;
  else if (k + 2 == n) res += 3;
  else res += 4; 
  cout << res << endl;
  for (pii x : e) {
    cout << x.first+1 << ' ' << x.second+1 << endl;
  }
  return 0;
}