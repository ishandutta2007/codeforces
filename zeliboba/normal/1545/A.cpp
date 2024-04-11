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
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int n;
    cin >> n;
    vii ts(n);
    for (int i = 0; i < n; ++i) {
      cin >> ts[i].first;
      ts[i].second = i;
    }
    sort(ts.begin(), ts.end());
    bool fail = 0;
    for (int i = 0; i < n; ++i) {
      int r = i + 1;
      while (r < n && ts[r].first == ts[i].first) ++r;
      vi v;
      for (int j = i; j < r; ++j) if (abs(j - ts[j].second) % 2) {
        if (!v.empty() && v.back() % 2 != j % 2) v.pop_back();
        else v.push_back(j);
      }
      if (!v.empty()) fail = 1;
      i = r - 1;
    }
    if (fail) cout << "NO\n";
    else cout << "YES\n";
  }
  return 0;
}