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

int sign(vs s) {
  string t;
  reverse(s[1].begin(), s[1].end());
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) if (s[i][j] != 'X')
    t += s[i][j];
  t += t[0];
  for (int i = 0; i+1 < t.size(); ++i) if (t[i] == 'A') {
    if (t[i+1] == 'B') return 1;
    else return 0;
  }
}

int main() {
  vs s1(2);
  vs s2(2);
  for (int i = 0; i < 2; ++i) cin >> s1[i];
  for (int i = 0; i < 2; ++i) cin >> s2[i];
  if (sign(s1) == sign(s2)) {
    cout << "YES\n";
  } else cout << "NO\n";
  return 0;
}