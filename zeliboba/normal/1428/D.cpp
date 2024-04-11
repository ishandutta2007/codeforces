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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  vi c(4);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++c[a[i]];
  }
  vii t;
  vi q3;
  vector<pair<int, vi>> q2;
  int it = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 3) {
      q3.push_back(i + 1);
    }
    if (a[i] == 2) {
      q2.emplace_back(i + 1, q3);
      q3.clear();
    }
    if (a[i] == 1) {
      if (!q2.empty()) {
        vi v = q2.back().second;
        v.push_back(q2.back().first);
        q2.pop_back();
        v.push_back(i + 1);
        for (int i = 0; i + 1 < v.size(); ++i) {
          t.emplace_back(it + i, v[i]);
          t.emplace_back(it + i, v[i + 1]);
        }
        it += v.size() - 1;
      } else if (!q3.empty()) {
        q3.push_back(i + 1);
        for (int i = 0; i < q3.size(); ++i) {
          t.emplace_back(it + i, q3[i]);
          if (i + 1 < q3.size()) {
            t.emplace_back(it + i, q3[i + 1]);
          }
        }
        it += q3.size();
        q3.clear();
      } else {
        t.emplace_back(it, i + 1);
        ++it;
      }
    }
  }
  if (!q3.empty() || !q2.empty()) {
    cout << -1 << endl;
    return 0;
  }
  cout << t.size() << endl;
  for (pii p : t) cout << p.first << ' ' << p.second << '\n';
  return 0;
}