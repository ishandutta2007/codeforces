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
  int n, s;
  cin >> n >> s;
  vi a(n), l, r;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] < s) l.push_back(s - a[i]);
    if (a[i] > s) r.push_back(a[i] - s);
  }
  if (r.size() > n / 2) l.swap(r);
  sort(l.rbegin(), l.rend());
  ll res = 0;
  while (l.size() > n / 2) {
    res += l.back();
    l.pop_back();
  }
  cout << res << endl;
  return 0;
}