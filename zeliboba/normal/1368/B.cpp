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

bool f(vi v, ll k) {
  ll prod = 1;
  for (ll x : v) {
    if (prod <= k / x) prod *= x;
    else prod = k + 1;
  }
  return prod < k;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll k;
  cin >> k;
  string s = "codeforces";
  vi v(s.size(), 1);
  while (f(v, k)) {
    sort(v.begin(), v.end());
    ++v[0];
  }
  string res = "";
  for (int i = 0; i < v.size(); ++i) for (int x = 0; x < v[i]; ++x) res += s[i];
  cout << res << endl;
  return 0;
}