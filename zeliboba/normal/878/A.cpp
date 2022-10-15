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
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, x;
  cin >> n;
  string s;
  vi z(10);
  vi o(10);
  vi r(10);
  for (int i = 0; i < n; ++i) {
    cin >> s >> x;
    for (int b = 0; b < 10; ++b) {
      bool t = x & (1 << b);
      if (s[0] == '|' && t) {
        o[b] = 1;
        z[b] = 0;
      }
      if (s[0] == '&' && !t) {
        z[b] = 1;
        o[b] = 0;
      }
      if (s[0] == '^' && t) {
        if (z[b]) {
          z[b] = 0; o[b] = 1;
        } else if (o[b]) {
          o[b] = 0; z[b] = 1;
        }
        r[b] ^= 1;
      }
    }
  }
  cout << 3 << endl;
  x = 0;
  for (int i = 0; i < 10; ++i) if (o[i] + z[i] == 0 && r[i]) x ^= 1 << i;
  cout << "^ " << x << endl;
  x = 0;
  for (int i = 0; i < 10; ++i) if (o[i]) x ^= 1 << i;
  cout << "| " << x << endl;
  x = 1023;
  for (int i = 0; i < 10; ++i) if (z[i]) x ^= 1 << i;
  cout << "& " << x << endl;
  return 0;
}