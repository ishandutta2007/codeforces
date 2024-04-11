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
#include <array>
#include <bitset>
using namespace std;
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
//typedef long long int;

int main() {
  std::ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  int n = s.size();
  s.resize((n + 1) / 2);
  t.resize(n/2);
  string res(n, 'a');
//  cerr << res << endl;
  int is = 0, it = 0, js = s.size() - 1, jt = t.size() - 1;
  for (int i = 0; i < res.size(); ++i) {
    if (i % 2 == 0) {
      if (s[is] >= t[it]) {
        for (int j = n-1; j >= i; --j) {
          if ((n-1-j) % 2 == 0) {
            res[j] = s[js]; --js;
          } else {
            res[j] = t[jt]; --jt;
          }
        }
        break;
      } else {
        res[i] = s[is];
        ++is;
      }
    } else {
      if (t[it] <= s[is]) {
        for (int j = n-1; j >= i; --j) {
          if ((n-1-j) % 2 == 1) {
            res[j] = s[js]; --js;
          } else {
            res[j] = t[jt]; --jt;
          }
        }
        break;
      } else {
        res[i] = t[it];
        ++it;
      }
    }
  }
  cout << res << endl;
  return 0;
}