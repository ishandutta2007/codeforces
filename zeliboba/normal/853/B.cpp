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

const int D = 1000005;
vii qin[D];
vii qout[D];
/*vii in[100005];
vii out[100005];
vl sin[100005];
vl sout[100005];*/

//set<pii> in[100005];
set<pii> out[100005];

const ll MAX = 1e18;

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int d,f,t,c;
    scanf("%d%d%d%d", &d, &f, &t, &c);
    if (f == 0) {
      qout[d].emplace_back(t, c);
//      out[t].emplace_back(d, c);
    } else {
      qin[d].emplace_back(f, c);
//      in[f].emplace_back(d, c);
    }
  }
/*  for (int i = 0; i <= n; ++i) {
    sort(in[i].begin(), in[i].end());
    sort(out[i].begin(), out[i].end());

  }*/
  int ct = 0, cn = 0;
  for (int i = k + 1; i < D; ++i) {
    for (pii p : qout[i]) {
      if (out[p.first].empty()) ++ct;
      out[p.first].insert(pii(p.second, i)); 
    }
  }
  ll res = MAX;
  ll cur = 0;
  for (int i = 1; i <= n; ++i) if (out[i].size()) {
    cur += out[i].begin()->first;
  }
  const int MM = 1e9;
  vi mi(n + 1, MM);
  for (int i = 0; i < D - k - 1; ++i) {
    for (pii p : qin[i]) {
      if (mi[p.first] == MM) {
        ++cn;
      } else {
        cur -= mi[p.first];
      }
      mi[p.first] = min(mi[p.first], p.second);
      cur += mi[p.first];
    }
    if (cn == n && ct == n) res = min(res, cur);
    for (pii p : qout[i + k + 1]) {
      cur -= out[p.first].begin()->first;
      out[p.first].erase(pii(p.second, i + k + 1));
      if (out[p.first].empty()) --ct;
      else {
        cur += out[p.first].begin()->first;
      }
    }
  }
  if (res >= MAX) res = -1;
  printf("%lld\n", res);
  return 0;
}