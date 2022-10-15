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
  int n,m;
  cin >> n >> m;
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int h = (l+r)/2;
    int x2 = h / 2;
    int x3 = h / 3;
    int x6 = h / 6;
    if (x2 < n || x3 < m || x2+x3-x6 < n+m) l = h;
    else r = h;
  }
  cout << r << endl;
  return 0;
}