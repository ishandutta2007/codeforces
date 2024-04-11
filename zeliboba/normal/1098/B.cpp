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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

map<char, int> ind;
char alp[4] = {'A', 'C', 'G', 'T'};

pair<int, vs> solve(const vvi& v, bool trans) {
  int n = v.size(), m = v[0].size();
  vi ord(4);
  for (int i = 0; i < 4; ++i) ord[i] = i;
  pair<int, vs> mi(n * m, vs(0));
  do {
    if (ord[0] > ord[1] || ord[2] > ord[3]) continue;
    int s = 0;
    vs res(n, string(m, 'A'));
    for (int i = 0; i < n; ++i) {
      vi cand = {ord[i % 2 * 2], ord[i % 2 * 2 + 1]};
      vi c(2, 0);
      for (int j = 0; j < m; ++j) {
        for (int t = 0; t < 2; ++t) {
          if (v[i][j] != cand[(j + t) % 2]) ++c[t];
        }
      }
      s += min(c[0], c[1]);
      if (c[0] > c[1]) {
        swap(cand[0], cand[1]);
      }
      for (int j = 0; j < m; ++j) {
        res[i][j] = alp[cand[j%2]];
      }
    }
    mi = min(make_pair(s, res), mi);
  } while (next_permutation(ord.begin(), ord.end()));
  if (trans) {
    vs res(m, string(n, 'A'));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      res[j][i] = mi.second[i][j];
    }
    mi.second = res;
  }
  return mi;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vs s(n);
  vvi v(n, vi(m)), v1(m, vi(n));
  for (int i = 0; i < 4; ++i) {
    ind[alp[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; ++j) {
      v1[j][i] = v[i][j] = ind[s[i][j]];
    }
  }
  auto res = min(solve(v, 0), solve(v1, 1));
  cerr << res.first << endl;
  for (const auto& it : res.second) {
    cout << it << '\n';
  }
  return 0;
}