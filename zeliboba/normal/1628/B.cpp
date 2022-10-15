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
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vs s(n);
    set<string> w;
    bool ok = 0;
    string t;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      int l = s[i].size();
      if (s[i][0] == s[i][l - 1]) ok = 1;
      w.insert(s[i]);
      if (l >= 2) {
        t.resize(2);
        t[0] = s[i][l-1];
        t[1] = s[i][l-2];
        if (w.count(t)) ok = 1;
      }
      if (l == 3) {
        t = s[i];
        t[0] = s[i][l-1];
        t[2] = s[i][0];
        if (w.count(t)) ok = 1;
      }
    }
    w.clear();
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i) {
//      cerr << s[i] << endl;
      int l = s[i].size();
      w.insert(s[i]);
      if (l >= 2) {
        t.resize(2);
        t[0] = s[i][1];
        t[1] = s[i][0];
        if (w.count(t)) ok = 1;
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}