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

const ll MAX = 1e18;

int main() {
  int n, k;
  cin >> n >> k;
  ++n;
  vi a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  vl s(n);
  vi ok(n, 1);
  s[0] = a[0];
  for (int i = 1; i < n; ++i) {
    ok[i] = ok[i-1];
    s[i] = a[i] + s[i-1] / 2;
    if (s[i-1] % 2) ok[i] = 0;
  }
  ll res = 0;
  ll add = 0;
  for (int i = n-1; i >= 0; --i) {
    if (ok[i] && abs(add + s[i] - a[i]) <= k && (i != n-1 || s[i] != a[i])) {
      ++res;
//      cerr << i << ' ' << add << ' ' << s[i] << endl;
    }
    add += a[i];
    add *= 2;
    add = min(MAX, max(add, -MAX));
  }
  cout << res << endl;
  return 0;
}