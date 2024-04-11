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
const int mod = 998244353;

unordered_map<ll, int> saved;
//int saved0[500][500];
const int N = 1 << 20;
int mi[2 * N];

int getmi(int l, int r) {
  l += N;
  r += N;
  int res = 1e9;
  while (l < r) {
    if (l & 1) {
      res = min(res, mi[l]);
      ++l;
    }
    if (r & 1) {
      res = min(res, mi[r - 1]);
      --r;
    }
    l /= 2;
    r /= 2;
  }
  return res;
}

ll solve(int l, int r, const vi& c, const vvi& v, const vvi& posl, const vvi& posr) {
  if (l >= r) return 1;
  ll hash = r * (ll)(1e6) + l;
  if (saved.count(hash)) return saved[hash];
//  if (saved0[l][r] != -1) return saved0[l][r];
  int i = getmi(l, r);
  if (i >= v.size()) return 1;
/*  if (v[i][0] >= r || v[i].back() < l) {
    ll res = solve(l, r, c, v, posl, posr);
    saved[hash] = res;
    return res;
  }*/
//  cerr << l << ' ' << r << ' ' << i << endl;
  assert(v[i][0] >= l && v[i].back() < r);
  ll res = 1;
  for (int it = 0; it + 1 < (int)v[i].size(); ++it) {
    res = res * solve(v[i][it] + 1, v[i][it + 1], c, v, posl, posr) % mod;
  }
  ll resl = 0, resr = 0;
/*  int it = lower_bound(posl[i].begin(), posl[i].end(), l - 1) - posl[i].begin();
//  assert(it == posl[i].size() - 1);
//  assert(posl[i].size() - it == v[i][0] - l + 1);
  while (it < posl[i].size()) {
    resl = (resl + solve(posl[i][it] + 1, v[i][0], c, v, posl, posr) * solve(l, posl[i][it] + 1, c, v, posl, posr)) % mod;
    ++it;
  }
  it = lower_bound(posr[i].begin(), posr[i].end(), r - 1) - posr[i].begin();
  while (it >= 0) {
    resr = (resr + solve(v[i].back() + 1, posr[i][it] + 1, c, v, posl, posr) * solve(posr[i][it] + 1, r, c, v, posl, posr)) % mod;
    --it;
  }*/
  for (int it = l; it <= v[i][0]; ++it) {
    resl = (resl + solve(it, v[i][0], c, v, posl, posr) * solve(l, it, c, v, posl, posr)) % mod;
  }
  for (int it = v[i].back() + 1; it <= r; ++it) {
    resr = (resr + solve(v[i].back() + 1, it, c, v, posl, posr) * solve(it, r, c, v, posl, posr)) % mod;
  }
//  cerr << i << ' ' << l << ' ' << r << ' ' << resl << ' ' << res << ' ' << resr << endl;
  res = res * resl % mod * resr % mod;
  saved[hash] = res;
//  saved0[l][r] = res;
  return res;
}

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
//  for (int i = 0; i < 500; ++i) for (int j = 0; j < 500; ++j) saved0[i][j] = -1;
  int n = 500, m = 500;//1000000;
  if (!DEBUG) cin >> n >> m;
  vi c(m);
  for (int i = 0; i < n; ++i) c[i] = i + 1;
  for (int j = n; j < m; ++j) c[j] = rand() % n + 1;
//  random_shuffle(c.begin(), c.end());
  vvi v(n);
  for (int i = 0; i < 2 * N; ++i) mi[i] = n;
  for (int i = 0; i < m; ++i) {
    if (!DEBUG) cin >> c[i];
    --c[i];
    mi[i + N] = c[i];
    v[c[i]].push_back(i);
  }
  for (int i = N - 1; i > 0; --i) mi[i] = min(mi[2 * i], mi[2 * i + 1]);
/*  vi pr(m), nx(m);
  for (int i = 0; i < m; ++i) {
    pr[i] = i - 1;
    nx[i] = i + 1;
  }
  ll res = 1;
  for (int j = n - 1; j >= 0; --j) {
    int bad = 0;
    int l = n, r = 0;
    assert(!v[j].empty());
    for (int i : v[j]) {
      assert(c[i] == j);
      if ((pr[i] < 0 || c[pr[i]] < j) && (nx[i] >= m || c[nx[i]] < j)) ++bad;
      l = min(l, pr[i]);
      r = max(r, nx[i]);
      if (pr[i] >= 0) nx[pr[i]] = nx[i];
      if (nx[i] < n) pr[nx[i]] = pr[i];
    } 
    if (bad > 1) {
      res = 1;
      break;
    } else {
      res = res * (v[j][0] - l) % mod * (r - v[j].back()) % mod;
    }
  }*/
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
    int it = lower_bound(v[i].begin(), v[i].end(), v[j][0]) - v[i].begin();
    if (it < v[i].size() && v[i][it] < v[j].back()) {
      cout << 0 << endl;
      return 0;
    }
  }
  vvi posl(n), posr(n);
  vi bad(n);
  for (int i = n - 1; i >= 0; --i) {
    int l = -1, r = n - 1;
    for (int j = 0; j < i; ++j) {
      int it = lower_bound(v[j].begin(), v[j].end(), v[i][0]) - v[j].begin();
      if (it < v[j].size()) {
        r = min(r, v[j][0] - 1);
      } else {
        l = max(l, v[j].back());
      }
    }
    posl[i].push_back(l);
    posr[i].push_back(r);
    posl[i].push_back(v[i][0] - 1);
    posr[i].push_back(v[i].back());
    for (int j = i + 1; j < n; ++j) if (!bad[j]) {
      if (v[j][0] < v[i][0]) {
        posl[i].push_back(v[j][0] - 1);
      } else if (v[j].back() > v[i].back()) {
        posr[i].push_back(v[j].back());
      } else bad[j] = 1;
    }
    sort(posl[i].begin(), posl[i].end());
    posl[i].erase(unique(posl[i].begin(), posl[i].end()), posl[i].end());
    sort(posr[i].begin(), posr[i].end());
    posr[i].erase(unique(posr[i].begin(), posr[i].end()), posr[i].end());
  }
  cout << solve(0, n, c, v, posl, posr) << endl;
//  cerr << saved.size() << endl;
  return 0;
}