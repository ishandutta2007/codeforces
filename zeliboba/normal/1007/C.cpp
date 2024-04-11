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
//const int mod = ;

int ask(ll x, ll y) {
  cout << x << ' ' << y << endl;
  fflush(stdout);
  int ans;
  cin >> ans;
  if (ans == 0) exit(0);
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n;
  cin >> n;
  ll xl = 0, yl = 0, xr = n, yr = n, x0 = n, y0 = n;
  for (int t = 0; t < 1000; ++t) {
    if (x0 <= xl) {
      x0 = xr;
      yr = y0;
    }
    if (y0 <= yl) {
      y0 = yr;
      xr = x0;
    }
    if (x0 == xr && y0 == yr) {
      ll x = (xl + xr + 1) / 2, y = (yl + yr + 1) / 2;
      int ans = ask(x, y);
      if (ans == 1) xl = x;
      else if (ans == 2) yl = y;
      else {
        x0 = x - 1; y0 = y - 1;
      }
    } else {
      if ((x0 - xl)*(double)(yr - y0) < (y0 - yl)*(double)(xr - x0)) {
        ll x = x0, y = (y0 + yl + 1) / 2;
        int ans = ask(x, y);
        if (ans == 1) {
          xl = x0;
          x0 = xr;
          yr = y0;
        } else if (ans == 2) {
          yl = y;
        } else {
          x0 = x - 1;
          y0 = y - 1;
        }
      } else {
        ll x = (x0 + xl + 1) / 2, y = y0;
        int ans = ask(x, y);
        if (ans == 1) {
          xl = x;
        } else if (ans == 2) {
          yl = y0;
          y0 = yr;
          xr = x0;
        } else {
          x0 = x - 1;
          y0 = y - 1;
        }
      }
    }
  } 
  return 0;
}