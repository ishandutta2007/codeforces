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
const int mod = 1000000007;

void add0(int & x, int y) {
  x += y;
  if (x >= mod) x-=mod;
}

int main() {
  int n, k;
  cin >> n >> k;
  vi a(n+1);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  vvi d(n/2+1, vi(k + 1));
  d[0][0] = 1;
  for (int it = 1; it < a.size(); ++it) {
    vvi nd(d.size(), vi(d[0].size()));
    for (int i = 0; i < d.size(); ++i) {
      int add = i * (a[it] - a[it-1]);
      for (int j = 0; j + add < d[i].size(); ++j) nd[i][j + add] = (i + 1) * (ll)d[i][j] % mod;
    }
    for (int i = 0; i + 1 < d.size(); ++i) {
      int add = i * (a[it] - a[it-1]);
      for (int j = 0; j + add < d[i].size(); ++j) add0(nd[i+1][j + add], d[i][j]);
    }
    for (int i = 1; i < d.size(); ++i) {
      int add = i * (a[it] - a[it-1]);
      for (int j = 0; j + add < d[i].size(); ++j) add0(nd[i-1][j + add], i*(ll)d[i][j]%mod);
    }
    d.swap(nd);
//    for (int i = 0; i < d.size(); ++i) for (int j = 0; j < d[i].size(); ++j) if (d[i][j]) cerr << it << ' ' << i << ' ' << j << ' ' << d[i][j] << endl;
  }
  ll res = 0;
  for (int i = 0; i < d[0].size(); ++i) res += d[0][i];
  cout << res % mod << endl;
  return 0;
}