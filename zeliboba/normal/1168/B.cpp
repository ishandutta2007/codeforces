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
  string s;
  cin >> s;
  int n = s.size();
/*  vvi v(2);
  for (int i = 0; i < n; ++i) {
    v[s[i]-'0'].push_back(i);
  }*/
  vi mi(n, n);
  for (int i = 0; i < n; ++i) {  
    for (int k = 1; k <= 10 && i + 2 * k < n; ++k) if (s[i] == s[i + k] && s[i] == s[i + 2 * k]) {
      mi[i] = i + 2 * k;
      break;
    }
  }
  ll res = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (i + 1 < n) mi[i] = min(mi[i], mi[i+1]);
//    cerr << i << ' ' << mi[i] << endl;
    res += n - mi[i];
  }
  cout << res << endl;
  return 0;
}