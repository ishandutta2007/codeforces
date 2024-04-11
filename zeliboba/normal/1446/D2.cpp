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

const int N = 1 << 19;
int ma[2 * N];

int getma(int l, int r) {
  l += N;
  r += N;
  int res = 0;
  while (l <= r) {
    if (l & 1) {
      res = max(res, ma[l]);
      ++l;
    }
    if (!(r & 1)) {
      res = max(res, ma[r]);
      --r;
    }
    l /= 2;
    r /= 2;
  }
  return res;
}

void put(int i, int val) {
  i += N;
  ma[i] = val;
  while (i) {
    i /= 2;
    ma[i] = max(ma[2 *i], ma[2 *i + 1]);
  }
}

void out(vii v) {
  for (auto p : v) cerr << p.first << ',' << p.second << ' ';
  cerr << endl;
}

int solve(vi a) {
  int n = a.size();
  vii ts(n);
  vvi was(n);
  for (int i = 0; i < n; ++i) {
    ts[a[i]].first++;
    ts[i].second = i;
    was[a[i]].push_back(i);
  }
  sort(ts.rbegin(), ts.rend());
  if (ts[0].first == n) {
    return 0;
  }
  if (ts[0].first == ts[1].first) {
    return n;
  }
  int x = ts[0].second;
  vi s(n + 1);
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + (a[i] == x ? 1 : 0);
  }
  vector<vii> best(n + 1);
  for (int i = 1; i < ts.size(); ++i) if (ts[i].first) {
    int y = ts[i].second;
    assert(was[y].size() == ts[i].first);
    vector<array<int, 3>> v;
    for (int j = was[y].size() - 1; j >= 0; --j) {
      int pos = was[y][j] + 1;
      int val = j + 1;
      int d = j + 1 - s[pos] + n;
      assert(d >= 0 && d < N);
      if (ma[N + d] < val) put(d, val);
      int r = getma(d - 1, N - 1);
      assert(r > 0 && r <= was[y].size());
      v.push_back({j, r - 1, r - j});
      assert(s[was[y][r - 1] + 1] - s[was[y][j]] <= r - j);
//      best[r - j].emplace_back(was[y][j], was[y][r - 1] + 1);
//      if (r - j == 2) cerr << y << ' ' << was[y][j] << ' ' << was[y][r - 1] << endl;
    }
    for (int j = was[y].size() - 1; j >= 0; --j) {
      int pos = was[y][j] + 1;
      int d = j + 1 - s[pos] + n;
      put(d, 0);
    }
    assert(!v.empty());
    sort(v.begin(), v.end());
    vector<array<int, 3>> nv(1, v[0]);
    for (auto u : v) {
      if (nv.back()[1] >= u[1]) continue;
      if (nv.back()[0] == u[0]) nv.pop_back();
      nv.push_back(u);
    }
    for (auto u : nv) {
      best[u[2]].emplace_back(was[y][u[0]], was[y][u[1]] + 1);
      if (u[0] < u[1] && u[2] - 1 >= s[was[y][u[1]] + 1] - s[was[y][u[0] + 1]]) best[u[2]-1].emplace_back(was[y][u[0] + 1], was[y][u[1]] + 1);
      if (u[0] < u[1] && u[2] - 1 >= s[was[y][u[1] - 1] + 1] - s[was[y][u[0]]]) best[u[2]-1].emplace_back(was[y][u[0]], was[y][u[1] - 1] + 1);
    }
  }
  int res = 2;
  for (int d = 1; d < best.size(); ++d) if (!best[d].empty()) {
    assert(d < s[n] && d > 0);
    sort(best[d].begin(), best[d].end());
    vii v(1, best[d][0]);
    for (auto u : best[d]) {
      if (u.first == v.back().first) continue;
      while (!v.empty() && v.back().second >= u.second) v.pop_back();
      v.push_back(u);
    }
    if (0 && d == 2) {
      out(best[d]);
      out(v);
    }
    for (int i = 0; i + 1 < v.size(); ++i) assert(v[i].first < v[i + 1].first && v[i].second < v[i + 1].second);
    int it = 0, r = 0;
    for (int l = 0; l < n; ++l) {
      while (it < v.size() && v[it].first < l) ++it;
      if (it == v.size()) break;
      while (r <= n && s[r] - s[l] <= d) ++r;
      --r;
      if (s[r] - s[l] != d) continue;
      if (r < v[it].second) continue;
      res = max(res, r - l);
    }
  }
  return res;
}

int stupid(vi a) {
  int n = a.size(), res = 0;
  for (int l = 0; l < a.size(); ++l) {
    int ma = 0, cnt = 0;
    vi c(n);
    for (int r = l; r < n; ++r) {
      ++c[a[r]];
      if (ma < c[a[r]]) {
        ma = c[a[r]];
        cnt = 0;
      }
      if (ma == c[a[r]]) ++cnt;
      if (cnt >= 2) res = max(res, r - l + 1);
    }
  }
  return res;
}

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0) for (int n = 1; n < 100; ++n) for (int t = 0; t < 919321; ++t) {
    vi a(n);
    int A = n;
    for (int i = 0; i < n; ++i) a[i] = rand() % A;
    int s1 = solve(a), s2 = stupid(a);
    if (s1 != s2) {
      cerr << s1 << ' ' << s2 << endl;
      for (int x : a) cerr << x << ' ';
      cerr << endl;
      assert(s1 == s2);
    }
  }
  int n = 200000;
  if (!DEBUG) cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) {
      cin >> a[i];
      --a[i];
    } else {
      a[i] = rand() % 10;
    }
  }
  cout << solve(a) << endl;
  return 0;
}