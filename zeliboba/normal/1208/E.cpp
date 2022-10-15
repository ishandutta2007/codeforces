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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

struct Tree {
  Tree() {}
  Tree(const vi& a) {
    int n = a.size();
    N = 1;
    while (N < n) N *= 2;
    v.assign(2 * N, -2e9);
    for (int i = 0; i < n; ++i) v[i + N] = a[i];
    for (int i = N - 1; i > 0; --i) v[i] = max(v[2*i], v[2*i+1]);
  }
  int getma(int l, int r) {
    l += N;
    r += N;
    int ma = -2e9;
    while (l <= r) {
      if (l & 1) {
        ma = max(ma, v[l]);
        ++l;
      }
      if (!(r & 1)) {
        ma = max(ma, v[r]);
        --r;
      }
      l /= 2;
      r /= 2;
    }
    return ma;
  }
  int N;
  vi v;
};

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi a(n), lma(n), rma(n);
  vector<Tree> tr(n);
  vii ts(n);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    a[i].resize(l);
    for (int j = 0; j < l; ++j) cin >> a[i][j];
    tr[i] = Tree(a[i]);
    ts[i] = pii(l, i);
  }
  sort(ts.begin(), ts.end());
  //vl sum(n + 1);
  vl val(n);
  vl res(m);
  for (int i = 0; i < m; ++i) {
    if (i) res[i] = res[i - 1];
    for (int it = n - 1; it >= 0; --it) {
      int j = ts[it].second;
      int len = a[j].size();
      if (i >= len && m - i - 1 >= len) break;
      int nval = -2e9;
      if (i >= len || m - i - 1 >= len) nval = 0;
      int l = max(0, len - m + i), r = min(len - 1, i);
      nval = max(nval, tr[j].getma(l, r));
//      cerr << i << ' ' << j << ' ' << l << ' ' << r << ' ' << nval << endl; 
      res[i] += nval - val[j];
      val[j] = nval;
    }
  }
  for (ll x : res) cout << x << ' ';
  cout << endl;
  return 0;
}