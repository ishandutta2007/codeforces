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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i][1] >> a[i][0];
    a[i][2] = i+1;
  }
  sort(a.begin(), a.end());
  int l = 0, r = n+1;
  while (r - l > 1) {
    int s = (l + r) / 2;
    ll rem = t, cnt = 0;
    for (int i = 0; i < n; ++i) if (a[i][1] >= s) {
      if (a[i][0] > rem) break;
      rem -= a[i][0];
      ++cnt;
    }
    if (cnt >= s) l = s;
    else r = s;
  }
  cout << l << endl;
  cout << l << endl;
  int cnt = 0;
  for (int i = 0; i < n && cnt < l; ++i) if (a[i][1] >= l) {
    cout << a[i][2] << ' ';
    ++cnt;
  }
  cout << endl;
  return 0;
}