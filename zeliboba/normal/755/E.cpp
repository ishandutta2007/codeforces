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
  int n, k;
  cin >> n >> k;
  if (n <= 3 || k <= 1 || (k == 2 && n == 4) || k > 3) {
    cout << -1 << endl;
    return 0;
  }
  if (k == 2) {
    cout << n-1 << endl;
    for (int i = 1; i < n; ++i) cout << i << ' ' << i + 1 << endl;
    return 0;
  }
  if (k == 3) {
    cout << n-1 << endl;
    cout << "1 2\n" << "2 3\n";
    for (int i = 4; i <= n; ++i) cout << 3 << ' ' << i << endl;
    return 0;
  }
  return 0;
}