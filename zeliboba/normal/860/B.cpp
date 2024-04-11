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

int c[6][1000000];
map<int, int> w[10];
set<int> my[10];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vs s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int l = 0; l < 10; ++l) my[l].clear();
    for (int b = 0; b < s[i].size(); ++b) {
      int sum = 0;
      for (int e = b; e < s[i].size(); ++e) {
        sum = 10 * sum + s[i][e] - '0';
        if (my[e-b].count(sum)) continue;
//        cerr << i << ' ' << b << ' ' << e << ' ' << sum << endl;
        if (e - b < 6) c[e-b][sum]++;
        else w[e-b][sum]++;
        my[e-b].insert(sum);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    string res = "";
    for (int l = 0, pw = 1; l < s[i].size() && res == ""; ++l, pw *= 10) {
      int sum = 0;
      for (int j = 0; j <= l; ++j) {
        sum = 10 * sum + s[i][j] - '0';
      }
      for (int e = l; e < s[i].size(); ++e) {
//        cerr << i << ' ' << e-l << ' ' << e << ' ' << sum << endl;
        if ((l < 6 && c[l][sum] == 1) || (l >= 6 && w[l][sum] == 1)) {
          res = s[i].substr(e - l, l + 1);
          break;
        }
        if (e + 1 < s[i].size()) {
          sum = 10 * (sum - pw * (s[i][e-l] - '0')) + s[i][e+1] - '0';
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}