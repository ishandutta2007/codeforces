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
typedef long double ld;
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
  string s;
  vector<pii> c(1e6);
  for (int i = 0; i < n; ++i) {
    cin >> s;
    int bal = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') ++bal;
      else --bal;
    }
    if (bal >= 0) {
      int x = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') ++x;
        else --x;
        if (x < 0) break;
      }
      if (x >= 0) c[bal].first++;
    } else {
      int x = 0;
      reverse(s.begin(), s.end());
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ')') ++x;
        else --x;
        if (x < 0) break;
      }
      if (x >= 0) c[-bal].second++;
    }
  }
  int res = (c[0].first + c[0].second) / 2;
  for (int i = 1; i < c.size(); ++i) {
    res += min(c[i].first, c[i].second);
  }
  cout << res << endl;
  return 0;
}