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
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int res = 0;
  vii v(1, pii(a[0], 0));
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == v.back().first) ++v.back().second;
    else v.emplace_back(a[i], 1);
  }
  int s = 0;
  for (int i = v.size() - 1; i >= 0; --i) {
//    cerr << v[i].first << ' ' << v[i].second << endl;
    int x = min(v[i].second, s);
    res += x;
    s -= x;
    s += v[i].second;
  }
  cout << res << endl;
  return 0;
}