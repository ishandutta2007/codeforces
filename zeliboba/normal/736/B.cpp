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
  ll n;
  cin >> n;
  vi v = {0, 0, 1, 1, 2, 1};
  if (n < v.size()) {
    cout << v[n] << endl;
    return 0;
  }
  if (n % 2 == 0) {
    cout << 2 << endl;
    return 0;
  }
  bool pr = 1;
  for (ll i = 2; i * i <= n; ++i) if (n % i == 0) pr = 0;
  if (pr) cout << 1 << endl;
  else {
    bool pr = 1;
    n -= 2;
    for (ll i = 2; i * i <= n; ++i) if (n % i == 0) pr = 0;
    if (pr) cout << 2 << endl;
    else cout << 3 << endl;
  }
  return 0;
}