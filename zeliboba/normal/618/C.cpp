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

ll vect(ll x1, ll y1, ll x2, ll y2) {
  return x1*y2-x2*y1;
}

int main() {
  int n;
  cin >> n;
  vvi x(n, vi(3));
  for (int i = 0; i < n; ++i) {
    cin >> x[i][0] >> x[i][1];
    x[i][2] = i + 1;
  }
  sort(x.begin(), x.end());
  ll mi = 9e18, best = 2;
  for (int i = 2; i < x.size(); ++i) {
    ll s = abs(vect(x[i][0]-x[0][0], x[i][1] - x[0][1], x[1][0] - x[0][0], x[1][1] - x[0][1]));
    if (s && s < mi) {
      mi = s;
      best = x[i][2];
    }
  }
  cout << x[0][2] << ' ' << x[1][2] << ' ' << best << endl;
  return 0;
}