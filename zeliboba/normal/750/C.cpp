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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  //  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vi c(n), d(n);
  vi s(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> d[i];
    s[i+1] = s[i] + c[i];
  }
  int ma = 1e9, mi = -1e9;
  for (int i = 0; i < n; ++i) {
    int add = s.back() - s[i];
    if (d[i] == 1) {
      mi = max(mi, 1900 + add);
    } else {
      ma = min(ma, 1899 + add);
    }
  }
  if (ma < mi) {
    cout << "Impossible\n";
  } else if (ma > 1e8) {
    cout << "Infinity\n";
  } else {
    cout << ma << endl;
  }
  return 0;
}