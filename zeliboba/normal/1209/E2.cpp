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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vii ts(m);
    for (int i = 0; i < m; ++i) ts[i] = pii(0, i);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        ts[j].first = max(ts[j].first, a[i][j]);
      }
    }
    sort(ts.rbegin(), ts.rend());
    vvi v(min(n, m), vi(n));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < n; ++j) {
        v[i][j] = a[j][ts[i].second];
      }
    }
    vi d(1 << n);
    int MASK = (1 << n) - 1;
    for (int i = 0; i < v.size(); ++i) {
      vi sum(d.size());
      for (int r = 0; r < n; ++r) {
        vi x(n);
        for (int j = 0; j < n; ++j) x[j] = v[i][(j + r) % n];
        for (int mask = 0; mask < d.size(); ++mask) {
          int s = 0;
          for (int j = 0; j < n; ++j) if (mask & (1 << j)) s += x[j];
          sum[mask] = max(sum[mask], s);
        }
      }
      vi nd = d;
      for (int mask = 0; mask < d.size(); ++mask) {
        for (int nmask = mask; nmask <= MASK; nmask = ((nmask + 1) | mask)) {
          nd[nmask] = max(nd[nmask], d[mask] + sum[nmask ^ mask]);
        }
      }
      d.swap(nd);
    }
    cout << d.back() << '\n';
  }
  return 0;
}