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
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

int f(ll a, ll b, const vi & v) {
  if (a == 1 && b == 1) return 0;
  if (a > b) swap(a, b);
  vi d(a + 1, 0);
  d[1] = 1;
  for (int i = 0; i < v.size(); ++i) {
    vi nd = d;
    for (int j = 1; j < d.size(); ++j) {
      nd[j] = min(b, d[j] * (ll)v[i]);
    }
    for (int j = 1; j < d.size(); ++j) if (d[j]) {
      int ind = min(a, j * (ll)v[i]);
      nd[ind] = max(nd[ind], d[j]);
    }
    d.swap(nd);
    if (d[a] >= b) return i + 1;
  }
  return v.size() + 1;
}

int main() {
  std::ios::sync_with_stdio(false);
  int a, b, h, w, n;
  cin >> a >> b >> h >> w >> n;
  vi v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.rbegin(), v.rend());
  int res = min(f((a + h - 1) / h, (b + w - 1) / w, v), f((b + h - 1) / h, (a + w - 1) / w, v));
  if (res > n) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}