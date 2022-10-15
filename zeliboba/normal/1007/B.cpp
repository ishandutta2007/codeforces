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

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  vvi d(100001);
  for (int i = 1; i < (int)d.size(); ++i) for (int j = i; j < (int)d.size(); j += i) d[j].push_back(i);
  int T = 100000;
  scanf("%d", &T);
  //cin >> T;
  vector<vii> good(8);
  vector<vii> bad(8);
  for (int i = 1; i < 8; ++i) {
    for (int a = 1; a < 8; ++a) for (int b = 1; b < 8; ++b) {
      bool ok = 0;
      vi v = {a, i, b};
      vi ord(3);
      for (int i = 0; i < 3; ++i) ord[i] = i;
      do {
        bool cur = 1;
        for (int i = 0; i < 3; ++i) if (!(v[ord[i]] & (1 << i))) cur = 0;
        if (cur) {
          ok = 1; break;
        }
      } while (next_permutation(ord.begin(), ord.end()));
      if (ok) good[i].emplace_back(a, b);
      else bad[i].emplace_back(a, b);
    }
  }
//  map<ll, ll> was;
  vi x;
  x.reserve(390);
  for (int test = 1; test <= T; ++test) {
    vi v(3, 60060);
    for (int i = 0; i < (int)v.size(); ++i) {
      scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
/*    ll VVV = v[0] * (ll)d.size() * d.size() + v[1] * (ll)d.size() + v[2];
    if (was.count(VVV)) {
      cout << was[VVV] << endl;
      continue;
    }*/
    int ans = 0;
    x.clear();
    array<int, 3> it = {0, 0, 0};
    int p = -1;
    while (1) {
      int i = -1, ma = d.size();
      for (int j = 0; j < 3; ++j) {
        if (it[j] < d[v[j]].size()) {
          if (d[v[j]][it[j]] == p) {
            ++it[j];
            if (it[j] < d[v[j]].size() && d[v[j]][it[j]] < ma) {
              ma = d[v[j]][it[j]];
              i = j;
            }
          } else if (d[v[j]][it[j]] < ma) {
            ma = d[v[j]][it[j]];
            i = j;
          }
        }
      }
      if (i == -1) break;
      x.push_back(d[v[i]][it[i]]);
      p = x.back();
      ++it[i];
    }
    vi mx(x.size());
    for (int i = 0; i < (int)x.size(); ++i) for (int j = 0; j < 3; ++j) if (v[j] % x[i] == 0) mx[i] |= (1 << j);
    vector<array<int, 8>> s(x.size() + 1);
    s[0].fill(0);
    for (int i = 0; i < (int)x.size(); ++i) {
      s[i+1] = s[i];
      s[i+1][mx[i]]++;
    }
    for (int i = 0; i < (int)x.size(); ++i) {
      if (good[mx[i]].size() > bad[mx[i]].size()) {
        ans += (i + 1) * (x.size() - i);
        for (pii p : bad[mx[i]]) {
          ans -= s[i + 1][p.first] * (s.back()[p.second] - s[i][p.second]);
        }
      } else for (pii p : good[mx[i]]) {
        ans += s[i + 1][p.first] * (s.back()[p.second] - s[i][p.second]);
      }
    }
    //was[VVV] = ans;
    printf("%d\n", ans);
  }
  return 0;
}