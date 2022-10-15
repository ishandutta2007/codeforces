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

void rec(int l, int r, vector<array<int, 4>>& v) {
  if (l + 1 >= r) return;
  int m = (l + r) / 2;
  rec(l, m, v);
  rec(m, r, v);
  v.push_back({l, m, m, r});
}

vector<array<int, 4>> getcomp(int n) {
  vector<array<int, 4>> res;
  rec(0, n, res);
  return res;
}

vector<array<int, 2>> nx;
vi was[2];
vi inds;
unordered_map<ll, int> saved;

void rec2(const string& s, int r, int& i) {
  if (1 >= r || i >= (int)s.size()) return;
  ll hash = r * (ll)s.size() + i;
  if (saved.count(hash)) {
    i = saved[hash];
    return;
  }
  int m = r / 2;
  rec2(s, m, i);
  rec2(s, r - m, i);
  if (i <= (int)s.size()) {
    array<int, 2> L = {m, r - m};
    int ni = s.size();
    for (int t = 0; t < 2; ++t) {
      int j = nx[i][t];
      if (j < (int)s.size() && inds[j] + L[t] <= (int)was[t].size()) {
        ni = min(ni, was[t][inds[j] + L[t] - 1]);
      }
    }
    i = ni + 1;
  }
  saved[hash] = i;
  return;
}

bool ok(int n, const string& s) {
  int i = 0;
  rec2(s, n, i);
/*  auto v = getcomp(n);
  int i = 0;
  for (auto x : v) {
    array<int, 2> l = {x[1] - x[0], x[3] - x[2]};
    int ni = s.size();
    for (int t = 0; t < 2; ++t) {
      int j = nx[i][t];
      if (j < s.size() && inds[j] + l[t] <= was[t].size()) {
        ni = min(ni, was[t][inds[j] + l[t] - 1]);
      }
    }
    if (ni >= s.size()) return false;
    i = ni + 1;
  }*/
  return i == (int)s.size();
} 

const int DEBUG = 0;
vi hidden;

string gen(vi a) {
  auto v = getcomp(a.size());
  string s;
  for (auto x : v) {
    int j1 = x[0], j2 = x[2];
    while (j1 < x[1] && j2 < x[3]) {
      if (a[j1] < a[j2]) {
        s += '0';
        ++j1;
      } else {
        s += '1';
        ++j2;
      }
    }
    sort(a.begin() + x[0], a.begin() + x[3]);
  }
  return s;
}

void solve(string s) {
  saved.clear();
  inds.resize(s.size());
  nx.assign(s.size() + 1, {(int)s.size() + 1, (int)s.size() + 1});
  for (int i = 0; i < (int)s.size(); ++i) {
    int x = s[i] - '0';
    inds[i] = was[x].size();
    was[x].push_back(i);
  }
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    nx[i] = nx[i + 1];
    nx[i][s[i] - '0'] = i;
  }
  for (int n = 1; n < (int)s.size() + 10; ++n) {
    if (ok(n, s)) {
      auto v = getcomp(n);
      vvi res(n);
      for (int i = 0; i < n; ++i) res[i] = vi(1, i);
      int i = 0;
      for (auto x : v) {
        vi tmp;
        int j1 = 0, j2 = 0;
        while (j1 < x[1] - x[0] || j2 < x[3] - x[2]) {
          if (j1 < x[1] - x[0] && j2 < x[3] - x[2]) {
            assert(i < (int)s.size());
            ++i;
          }
          if (j2 == x[3] - x[2] || (j1 < x[1] - x[0] && s[i - 1] == '0')) {
            tmp.push_back(res[x[0]][j1++]);
          } else {
            tmp.push_back(res[x[2]][j2++]);
          }
        }
        res[x[0]] = tmp;
      }
      assert(i == (int)s.size());
      vi ans(n);
      for (int i = 0; i < (int)res[0].size(); ++i) ans[res[0][i]] = i + 1;
      cout << n << endl;
      for (int x : ans) cout << x << ' ';
      cout << endl;
      if (DEBUG && gen(ans) != s) {
        cerr << s << endl;
        cerr << gen(ans) << endl;
        assert(0);
      }
      assert(gen(ans) == s);
      return;
    }
  }
  assert(0);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) {
    for (int n = 1; n <= 7; ++n) {
      hidden.resize(n);
      for (int i = 0; i < n; ++i) hidden[i] = i + 1;
      do {
        solve(gen(hidden));
      } while (next_permutation(hidden.begin(), hidden.end()));
    }
    hidden.resize(1e5);
    for (int i = 0; i < (int)hidden.size(); ++i) hidden[i] = i + 1;
    random_shuffle(hidden.begin(), hidden.end());
    solve(gen(hidden));
    cerr << saved.size() << endl;
  }
  string s;
  cin >> s;
  solve(s);
  return 0;
}