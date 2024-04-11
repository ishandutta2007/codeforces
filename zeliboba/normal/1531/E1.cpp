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

string s;
bool ok(int n) {
  auto v = getcomp(n);
  int i = 0;
  for (auto x : v) {
    int l1 = x[1] - x[0], l2 = x[3] - x[2];
    while (l1 && l2) {
      if (i >= s.size()) return false;
      if (s[i] == '0') --l1;
      else --l2;
      ++i;
    }
  }
  return i == s.size();
} 

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> s;
  for (int n = 1; n < s.size(); ++n) {
    if (ok(n)) {
      auto v = getcomp(n);
      vvi res(n);
      for (int i = 0; i < n; ++i) res[i] = vi(1, i);
      int i = 0;
      for (auto x : v) {
        vi tmp;
        int j1 = 0, j2 = 0;
        while (j1 < x[1] - x[0] || j2 < x[3] - x[2]) {
          if (j1 < x[1] - x[0] && j2 < x[3] - x[2]) {
            assert(i < s.size());
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
      assert(i == s.size());
      vi ans(n);
      for (int i = 0; i < res[0].size(); ++i) ans[res[0][i]] = i + 1;
      cout << n << endl;
      for (int x : ans) cout << x << ' ';
      cout << endl;
      return 0;
    }
  }
  return 0;
}