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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  string t = "";
  int bal = 0;
  for (int i = 0; i < s.size() && t.size() < k; ++i) {
    if (s[i] == ')') {
      if (bal > 0) {
        --bal;
        t += ')';
      }
    } else {
      if (bal + 1 <= k - t.size() - 1) {
        ++bal;
        t += '(';
      }
    }
  }
  cout << t << endl;
  return 0;
}