#include <cstdio>
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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vi c(3);
  for (auto x : s) {
    if (x == 'B') ++c[0];
    if (x == 'G') ++c[1];
    if (x == 'R') ++c[2];
  }
  if (c[0] && c[1] && c[2]) {
    cout << "BGR\n";
    return 0;
  }
  if (c[0] + c[1] == 0) {
    cout << "R\n";
    return 0;
  }
  if (c[0] + c[2] == 0) {
    cout << "G\n";
    return 0;
  }
  if (c[2] + c[1] == 0) {
    cout << "B\n";
    return 0;
  }
  string res = "";
  int t = 0;
  if (c[0] == 0) res += "B";
  if (c[1] == 0) {
    res += "G";
    t = 1;
  }
  if (c[2] == 0) {
    res += "R";
    t = 2;
  }
  char x[3] = {'B','G','R'};
//  cerr << t << ' ' << res << endl;
  if (s.size() >= 3) {
    if (c[0] > 1) res += x[(6 - t) % 3];
    if (c[1] > 1) res += x[(5 - t) % 3];
    if (c[2] > 1) res += x[(4 - t) % 3];
  }
  sort(res.begin(), res.end());
  res.resize(unique(res.begin(), res.end()) - res.begin());
  cout << res << endl;
  return 0;
}