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
std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vi a(n);
  int mi = 1e9;
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  for (int i = 1; i < n; ++i) if (a[i] % k != a[i-1] % k) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    s += (a[i] - mi) / k;
  }
  cout << s << endl;
  return 0;
}