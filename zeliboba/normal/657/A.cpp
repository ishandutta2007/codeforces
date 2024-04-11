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
  int n, d, h;
  cin >> n >> d >> h;
  if (n < h + 1 || h > d || n < d + 1 || d > 2*h || (n > 2 && d == 1)) {
    cout << -1 << endl;
    return 0;
  }
  int last = 0;
  for (int i = 1; i <= h; ++i) {
    printf("%d %d\n", i, i + 1);
    last = i + 1;
  }
  for (int i = 0; i < d-h; ++i) {
    printf("%d %d\n", (i == 0) ? 1 : last, last + 1);
    ++last;
  }
  while (last < n) {
    if (d > h) printf("1 %d\n", last + 1);
    else printf("2 %d\n", last + 1);
    ++last;
  }
  return 0;
}