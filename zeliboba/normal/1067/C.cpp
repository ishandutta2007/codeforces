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

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, -2, 2, -1, 1};

int calc(int i, int j, const vvi& v) {
  int c = 0;
  for (int d = 0; d < 8; ++d) {
    int x = i + dx[d], y = j + dy[d];
    if (x >= 0 && y >= 0 && x < v.size() && y < v[0].size() && v[x][y]) {
      ++c;
    }
  }
  return c;
}

void solve(int n) {
  vvi v(2 * n + 3, vi(2 * n + 3));
  vii res;
  if (0) for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2 && res.size() < n; ++j) {
      res.emplace_back(n + i, n + j);
    }
  }
  if (0) {
    for (int j = 2; j < n + 2; ++j) {
      for (int i = 1; i >= 0; --i) {
        if (res.size() < n) res.emplace_back(n + i, n + j);
        if (res.size() < n) res.emplace_back(n + j, n + i);
        if (res.size() < n) res.emplace_back(n + i, n + 1 - j);
        if (res.size() < n) res.emplace_back(n + 1 - j, n + i);
      }
    }
  }
  if (0) {
    for (int j = 2; j < n + 2; ++j) {
      for (int i = 1; i >= 0; --i) {
        if (res.size() < n) res.emplace_back(n + i, n + j);
        if (res.size() < n) res.emplace_back(n + j, n + i);
      }
    }
  }
/*  int s = 1;
  if (n >= 23) s = n / 2 - 1;
  if (n == 59) s = n / 2 - 2;
  if (n >= 24) s = 9;
  if (n >= 28) s = 13;
  if (n >= 36) s = 17;
  if (n >= 43) s = 21;*/
/*  for (int l = s; l <= n + 4; l += 2) {
    for (int i1 = 0; i1 <= l; ++i1) {
      int i = (i1 + 1) % (l + 1);
      int j = l - i;
      if (res.size() < n) res.emplace_back(n + i, n + j);
    }
  }*/
  for (int l = 0; l < n; ++l) {
    for (int i = 0; i < 3; ++i) if ((i + l) % 2) {
      if (res.size() < n) res.emplace_back(n + i, n + l); 
    }
  }
/*  for (int d = 0; d < n; ++d) {
    vi x(1, d);
    if (d != 0) x.push_back(-d);
    for (int j : x) for (int i = d; i <= d + 2; i += 2) {
      if (res.size() < n) res.emplace_back(n + i, n + j);
    }
  }*/
//  cerr << n << ' ' << res.size() << endl;
  assert(res.size() == n);
  sort(res.begin(), res.end());
  for (int i = 0; i + 1 < n; ++i) assert(res[i] != res[i+1]);
  for (pii p : res) {
    v[p.first][p.second] = 1;
  }
  if (0) for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) cerr << v[i][j]; cerr << endl;
  }
  vii q = res;
/*  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (calc(i, j, v) >= 4 && !v[i][j]) {
    q.emplace_back(i, j);
  }*/
  int it = 0;
  while (it < q.size()) {
    pii p = q[it++];
    for (int d = 0; d < 8; ++d) {
      int x = p.first + dx[d], y = p.second + dy[d];
      if (x >= 0 && y >= 0 && x < v.size() && y < v[0].size() && !v[x][y] && calc(x, y, v) >= 4) {
        v[x][y] = 1;
        q.emplace_back(x, y);
      }
    }
  }
  if (0) for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) cerr << v[i][j]; cerr << endl;
  }
  cerr << n << ' ' << n * n / 10 << ' ' << q.size() << endl;
  assert(q.size() >= n * n / 10);
  for (pii p : res) {
    cout << p.first << ' ' << p.second << endl;
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
//  for (int n = 1; n <= 1000; ++n) solve(n);
  int n;
  cin >> n;
  solve(n);
  return 0;
}