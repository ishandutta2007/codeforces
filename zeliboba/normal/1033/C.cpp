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
#include <chrono>
#include <random>
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
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  vii ts(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ts[i] = pii(a[i], i);
  }
  sort(ts.rbegin(), ts.rend());
  vi res(n);
  for (int i = 0; i < n; ++i) {
    int pos = ts[i].second;
    int d = ts[i].first;
    for (int j = pos % d; j < n; j += d) if (a[j] > a[pos] && !res[j]) {
      res[pos] = 1;
      break;
    }
  }
  string ans(n, 'B');
  for (int i = 0; i < n; ++i) if (res[i]) ans[i] = 'A';
  cout << ans << endl;
  return 0;
}