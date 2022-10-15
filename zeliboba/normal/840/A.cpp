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
  int n;
  cin >> n;
  vii a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());
  vi res(n);
  for (int i = 0; i < n; ++i) {
    res[b[i].second] = a[i].first;
  }
  for (int i = 0; i < n; ++i) cout << res[i] << ' ';
  cout << endl;
  return 0;
}