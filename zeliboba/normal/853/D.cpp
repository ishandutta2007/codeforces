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

int f(int p1, int r1, int p, int S) {
  int a = min(p1 / 10, r1);
  int res = p1 + r1 - a;
  int rem = p1 / 10 - a;
  return res + p - p1 + max(0, S - p - r1 - (p - p1) / 10 - rem);
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  scanf("%d", &n);
  vi a(n);
  vi s(n+1);
  vi v;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s[i+1] = s[i] + a[i];
    if (a[i] == 1000) v.push_back(i);
  }
  int S = s.back();
  int res = S;
  for (int i = 0; i < n; ++i) {
    int p = s[i+1];
    res = min(res, p + max(0, S - p - p / 10));
  }
  if (!v.empty()) {
    int s1 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1000) s1 = s[i];
      res = min(res, f(s1, 1000, s[i+1] - 1000, S));
    }
    for (int i = 0; i < n; ++i) {
      int nx = lower_bound(v.begin(), v.end(), i + 1) - v.begin();
      if (nx < (int)v.size() && s[i + 1] / 10 >= s[v[nx]] - s[i + 1]) {
        res = min(res, f(s[i+1], s[v[nx]] - s[i + 1], s[i+1] + 1000, S));
      }
    }
  }
  printf("%d\n", res);
  return 0;
}