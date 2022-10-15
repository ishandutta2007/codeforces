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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  vs v(2);
  cin >> v[0] >> v[1];
  cout << v[0] << ' ' << v[1] << endl;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    vs s(2);
    cin >> s[0] >> s[1];
    for (int j = 0; j < 2; ++j) {
      if (v[j] == s[0]) {
        v[j] = s[1];
        break;
      }
    }
    cout << v[0] << ' ' << v[1] << endl;
  }
  return 0;
}