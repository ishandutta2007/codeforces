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
  vi a(n), t(n);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vii w(1, pii(2e9, 0));
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    w.emplace_back(a[i], t[i]);
  }
  sort(w.begin(), w.end());
  int val = -1;
  ll sumt = 0;
  multiset<int> q;
  for (int i = 0; i < w.size(); ++i) {
    while (val < w[i].first && !q.empty()) {
      auto it = q.end(); --it;
      sumt -= *it;
      q.erase(it);
      res += sumt;
      ++val;
    }
    val = max(val, w[i].first);
    sumt += w[i].second;
    q.insert(w[i].second);
  }
  cout << res << endl;
  return 0;
}