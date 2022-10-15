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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int Q, k;
  cin >> k;
  vl f(6);
  for (int i = 0; i < f.size(); ++i) cin >> f[i];
  cin >> Q;
  vl d(1e6, -1e18);
  d[0] = 0;
  for (int j = 0, pw = 3; j < f.size(); ++j, pw *= 10) {
    vl nd = d;
    ll x = 3 * (k - 1) * pw;
    for (int s = 0; s < pw; ++s) {
      vi q;
      int it = 0;
      for (int i = s; i < d.size(); i += pw) {
        while (it < (int)q.size() && i - q[it] > x) ++it;
        while ((int)q.size() > it && d[q.back()] + f[j] * (i - q.back()) / pw <= d[i]) q.pop_back();
        q.push_back(i);
        nd[i] = max(nd[i], d[q[it]] + f[j] * (i - q[it]) / pw);
      }
    }
    d = nd;
    for (int dig = 1; dig <= 9; ++dig) {
      int x = pw / 3 * dig;
      ll cost = dig % 3 ? 0 : dig / 3 * f[j];
      for (int i = d.size() - 1; i >= x; --i) {
        d[i] = max(d[i], nd[i - x] + cost);
      }
    }
  }
  for (int q = 0; q < Q; ++q) {
    int n;
    cin >> n;
    cout << d[n] << endl;
  }
  return 0;
}