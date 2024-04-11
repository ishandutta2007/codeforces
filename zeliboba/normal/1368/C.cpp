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
  int n;
  cin >> n;
  vii v;
  v.emplace_back(0, 0);
  v.emplace_back(0, 1);
  v.emplace_back(1, 0);
  v.emplace_back(1, 1);
  for (int i = 1; i <= n; ++i) {
    v.emplace_back(i, i + 1);
    v.emplace_back(i + 1, i);
    v.emplace_back(i + 1, i + 1);
  }
  cout << v.size() << endl;
  for (pii p : v) cout << p.first << ' ' << p.second << '\n';
  return 0;
}