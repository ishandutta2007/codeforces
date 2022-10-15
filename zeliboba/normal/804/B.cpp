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
const int mod = 1000000007;

int main() {
  std::ios::sync_with_stdio(false);
  string s;
  cin >> s;
  ll res = 0, c = 0;
  for (int i = s.size()-1; i >= 0; --i) {
    if (s[i] == 'b') {
      ++c;
    } else {
      res += c;
      c = c * 2 % mod;
    }
  }
  cout << res % mod << endl;
  return 0;
}