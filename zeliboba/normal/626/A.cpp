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
  int c = 0;
  for (int i = 0; i < s.size(); ++i) {
    int x = 0, y = 0;
    for (int j = i; j < s.size(); ++j) {
      if (s[j] == 'D') --x;
      if (s[j] == 'U') ++x;
      if (s[j] == 'L') --y;
      if (s[j] == 'R') ++y;
      if (x == 0 && y == 0) ++c;
    }
  }

  cout << c << endl;
  return 0;
}