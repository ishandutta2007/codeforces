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

const int N = 2100000;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vi erat(N, 1);
  erat[0] = erat[1] = 0;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = 0;
  }
  vi p;
  for (int i = 2; i < erat.size(); ++i) if (erat[i])
    p.push_back(i);
  int n;
  ll x, y;
  cin >> n >> x >> y;
  vi a(n), c(N);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c[a[i]]++;
  }
  vi s(N+1);
  vl s1(N+1);
  for (int i = 0; i < N; ++i) {
    s[i+1] = s[i] + c[i];
    s1[i+1] = s1[i] + c[i] * (ll)i;
  }
  ll res = x * n;
  for (int d : p) {
    ll cur = 0;
    for (int i = d; i < N; i += d) {
      int l = max(i-x/y, (ll)i-d+1);
      cur += x * (s[l] - s[i-d+1]);
      cur += y * (i*(ll)(s[i]-s[l]) - (s1[i] - s1[l]));
    }
    res = min(res, cur);
  }
  cout << res << endl;
  return 0;
}