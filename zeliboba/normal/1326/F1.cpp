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
typedef pair<int, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int a[14][14];
ll tmp[1 << 14][14][2];
const int DEBUG = 0;
vi rem[1 << 14];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 14;
  if (!DEBUG) cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    if (!DEBUG) {
      cin >> s;
      for (int j = 0; j < n; ++j) a[i][j] = s[j] - '0';
    } else {
      for (int j = 0; j < n; ++j) a[i][j] = rand() % 2;
    }
  }
  vector<vector<vii>> d(1);
  for (int i = 0; i < n; ++i) {
    d[0].push_back(vii(1, pii(1 << i, 1)));
  }
  for (int m = 0; m < (1 << n); ++m) for (int i = 0; i < n; ++i) if (!(m & (1 << i))) {
    rem[m].push_back(i);
  }
  vector<array<int, 3>> need;
  for (int t = 1; t < n; ++t) {
    vector<vector<vii>> nd(1 << t, vector<vii>(n));
    for (int m1 = 0; m1 < (int)d.size(); ++m1) {
      for (int e = 0; e < n; ++e) {
        for (auto p : d[m1][e]) {
          for (int x : rem[p.first]) {
            //int m2 = m1 * 2 + a[e][x];
            int m3 = p.first | (1 << x);
            tmp[m3][x][a[e][x]] += p.second;
            need.push_back({m3, x, a[e][x]});
            //          nd[m2][x].emplace_back(p.first | (1 << x), p.second);
          }
        }
      }
      for (auto p : need) {
        if (tmp[p[0]][p[1]][p[2]]) {
          nd[m1 * 2 + p[2]][p[1]].emplace_back(p[0], tmp[p[0]][p[1]][p[2]]);
          tmp[p[0]][p[1]][p[2]] = 0;
        }
      }
      need.clear();
    }
    d.swap(nd);
/*    for (int m1 = 0; m1 < (int)d.size(); ++m1) for (int e = 0; e < n; ++e) if (!d[m1][e].empty()) {
      for (pii p : d[m1][e]) {
        tmp[p.first] += p.second;
        need.push_back(p.first);
      }
      d[m1][e].clear();
      for (int x : need) {
        if (tmp[x]) {
          d[m1][e].emplace_back(x, tmp[x]);
          tmp[x] = 0;
        }
      }
      need.clear();
//      cerr << t << ' ' << m1 << ' ' << e << endl;
//      for (pii p : d[m1][e]) cerr << p.first << ' ' << p.second << endl;
    }*/
  }
  for (int m = 0; m < (int)d.size(); ++m) {
    ll s = 0;
    for (int i = 0; i < (int)d[m].size(); ++i) if (!d[m][i].empty()) {
      assert(d[m][i].size() == 1 && d[m][i][0].first == (1 << n) - 1);
      s += d[m][i][0].second;
    }
    cout << s << ' ';
  }
  return 0;
}