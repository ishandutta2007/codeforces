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

const int M = 1 << 23;
char prec[M];

int f(int mask);

const int L = 32;
int calc(int mask) {
  char tmp[L];
  memset(tmp, 0, sizeof(tmp));
  for (int b = 0; mask >> b; ++b) {
    int nmask = (mask >> (b+1)) | ((mask & (1 << b) - 1));
    assert(nmask < mask);
    tmp[f(nmask)] = 1;
//    if (mask == 3) cerr << b << ' ' << nmask << ' ' << f(nmask) << endl;
  }
  for (int i = 0; i < L; ++i) if (!tmp[i]) return i;
  assert(0);
}

int f(int mask) {
  if (mask < M) return prec[mask];
  return calc(mask);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vi erat(40000, 1);
  erat[0] = erat[1] = 0;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = 0;
  }
  vi p;
  for (int i = 2; i < erat.size(); ++i) if (erat[i])
    p.push_back(i);
  for (int i = 1; i < M; ++i) {
    prec[i] = calc(i);
//    if (i < 10) cerr << i << ' ' << prec[i] << endl;
  }
  int n;
  cin >> n;
  vi a(n);
  map<int, vi> w;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int x = a[i];
    for (int d : p) {
      int c = 0;
      while (x % d == 0) {
        x /= d;
        ++c;
      }
      if (c >= 1) w[d].push_back(c);
    }
    if (x > 1) w[x].push_back(1);
  }
  int xr = 0;
  for (const auto& p : w) {
    int mask = 0;
    for (int i : p.second) {
      mask |= 1 << (i - 1);
    }
//    cerr << p.first << ' ' << mask << ' ' << f(mask) << endl;
    xr ^= f(mask);
  }
  if (xr) {
    cout << "Mojtaba\n";
  } else {
    cout << "Arpa\n";
  }
//  for (int i = 0; i < 100000; ++i) cerr << calc(rand() % (1 << 29)) << endl;
  return 0;
}