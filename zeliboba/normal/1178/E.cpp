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
  string l = "", r = "";
  int i = 0, j = n;
  while (j - i > 0) {
    if (j - i <= 3) {
      l += s[i];
      break;
    }
    bool ok = 0;
    for (int i1 : {i, i + 1}) for (int j1 : {j - 1, j - 2}) {
      if (s[i1] == s[j1] && !ok) {
        l += s[i1];
        r += s[j1];
        i = i1 + 1;
        j = j1;
        ok = 1;
        break;
      }
    }
    assert(ok);
  }
  reverse(r.begin(), r.end());
  l += r;
  assert(l.size() >= n / 2);
  cout << l << endl;
  return 0;
}