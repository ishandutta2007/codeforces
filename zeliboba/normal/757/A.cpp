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

int main() {
  std::ios::sync_with_stdio(false);
  string s;
  cin >> s;
  vi c(52);
  for (int i = 0; i < s.size(); ++i) {
    if (islower(s[i])) {
      ++c[s[i]-'a'];
    } else {
      ++c[s[i]-'A'+26];
    }
  }
  string t = "Bulbasaur";
  vi v(52);
  for (int i = 0; i < t.size(); ++i) {
    if (islower(t[i])) {
      ++v[t[i]-'a'];
    } else {
      ++v[t[i]-'A'+26];
    }
  }
  int mi = 1e9;
  for (int i = 0; i < 52; ++i) if (v[i]) mi = min(mi, c[i] / v[i]);
  cout << mi << endl;
  return 0;
}