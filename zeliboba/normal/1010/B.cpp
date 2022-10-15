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

int ask(int y) {
  cout << y << endl;
  fflush(stdout);
  int ans;
  cin >> ans;
  if (ans == 0) exit(0);
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int m, n;
  cin >> m >> n;
  vi v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = ask(1);
  }
  int l = 1, r = m + 1;
  for (int i = 0; i < 60 - n; ++i) {
    int x = (l + r) / 2;
    int ans = ask(x) * v[i % n];
    if (ans > 0) {
      l = x;
    } else {
      r = x;
    }
  }
  return 0;
}