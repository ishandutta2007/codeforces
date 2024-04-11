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

int prod[120][120];
const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 200000, k = 5;
  if (!DEBUG) cin >> n >> k;
  vvi p(n, vi(k));
  vi v(k);
  vvi allperm;
  for (int j = 0; j < k; ++j) v[j] = j;
  do {
    allperm.push_back(v);
  } while (next_permutation(v.begin(), v.end()));
  assert(allperm.size() <= 120);
  map<vi, int> idx;
  for (int i = 0; i < (int)allperm.size(); ++i) {
    idx[allperm[i]] = i;
  }
  for (int i = 0; i < (int)allperm.size(); ++i) for (int j = 0; j < (int)allperm.size(); ++j) {
    auto a = allperm[i], b = allperm[j];
    vi c(k);
    for (int i = 0; i < k; ++i) {
      c[i] = a[b[i]];
    }
    prod[i][j] = idx[c];
  }
  vi a(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (!DEBUG) cin >> p[i][j];
      else p[i][j] = j + 1;
      --p[i][j];
    }
    if (DEBUG) {
      random_shuffle(p[i].begin(), p[i].end());
    }
    a[i] = idx[p[i]];
    if (DEBUG) {
//      a[i] = prod[a[i]][a[i]];
    }
  }
  int m = allperm.size();
  vi zn(allperm.size());
  for (int i = 0; i < m; ++i) {
    auto v = allperm[i];
    for (int j = 0; j < k; ++j) for (int j1 = j + 1; j1 < k; ++j1) if (v[j] > v[j1]) ++zn[i];
    zn[i] %= 2;
  }
  vvi was(m);
  for (int i = 0; i < n; ++i) {
    was[a[i]].push_back(i);
  }
  set<pii> best;
  for (int i = 0; i < m; ++i) if (!was[i].empty()) best.insert(pii(was[i][0], i));
  vi it(m);
  ll res = 0;//n * (ll)(n + 1) / 2;
  vi used(m);
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      int p = a[i - 1];
      best.erase(pii(i - 1, p));
      ++it[p];
      if (it[p] < (int)was[p].size()) {
        best.insert(pii(was[p][it[p]], p));
      }
    }
    used.assign(m, 0);
    used[0] = 1;
    vi q(1, 0), nq;
    int c1 = 0;
    int pr = i;
    for (const pii& p : best) {
      if (used[p.second]) continue;
      res += (p.first - pr) * (ll)q.size();
      pr = p.first;
      used[p.second] = 1;
      q.push_back(p.second);
      c1 += zn[p.second];
      nq.resize(1, p.second);
      int nj = 0;
      while (nj < (int)nq.size() && (int)q.size() < m / 2 + 1 && !(q.size() == (m + 1) / 2 && c1 == 0)) {
        int added = nq[nj++];
        int j = 0;
        while (j < (int)q.size()) {
          int x = q[j++];
          for (int nx : {prod[x][added], prod[added][x]}) {
            if (!used[nx]) {
              used[nx] = 1;
              q.push_back(nx);
              c1 += zn[nx];
              if ((int)q.size() >= m / 2 + 1 || (q.size() == (m + 1) / 2 && c1 == 0)) break;
              nq.push_back(nx);
            }
          }
        }
      }
      if ((int)q.size() >= m / 2 + 1) {
        q.resize(m);
        used.assign(m, 1);
      }
//      cerr << q.size() << endl;
    }
    res += (n - pr) * (ll)q.size();
  }
  cout << res << endl;
  return 0;
}