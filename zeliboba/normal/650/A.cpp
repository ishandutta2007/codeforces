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

ll c2(ll x) {
  return x*(x-1)/2;
}

ll f(const vii & x) {
  ll res = 0;
  int c = 1;
  for (int i = 1; i < x.size(); ++i) {
    if (x[i].first == x[i-1].first) {
      res += c;
      ++c;
    } else {
      c = 1;
    }
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  vii x(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i].first, &x[i].second);
  }
  sort(x.begin(), x.end());
  ll res = f(x);
  for (int i = 0; i < n; ++i) swap(x[i].first, x[i].second);
  sort(x.begin(), x.end());
  res += f(x);
  int c = 1;
  for (int i = 1; i < x.size(); ++i) {
    if (x[i] == x[i-1]) {
      res -= c;
      ++c;
    } else {
      c = 1;
    }
  }
  cout << res << endl;
  return 0;
}