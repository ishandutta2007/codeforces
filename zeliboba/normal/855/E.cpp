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

const int L = 70;
ll d[11][L][1 << 10];
ll d1[11][L];

ll f(int b, ll n) {
  ll n0 = n;
  vi x;
  while (n) {
    x.push_back(n % b);
    n /= b;
  }
  ll res = 0;
  int mask = 0;
  for (int i = x.size() - 1; i >= 0; --i) {
    for (int j = 1; j < x[i]; ++j) {
      res += d[b][i][mask ^ (1 << j)];
    }
    if (i != x.size() - 1) {
      if (x[i]) res += d[b][i][mask ^ 1];
    } else {
      res += d1[b][i];
    }
    mask ^= (1 << x[i]);
  }
//  cerr << b << ' ' << n0 << ' ' << res << endl;
  return res;
}

const int MS = 100000;
ll s[11][MS];

ll stupid(int b, int n) {
  return s[b][n];
}

bool mtest(int b, int n) {
  vi c(b);
  while (n) {
    c[n % b]++;
    n /= b;
  }
  for (int x : c) if (x % 2) return 0;
  return 1;
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int b = 2; b <= 10; ++b) {
    d[b][0][0] = 1;
    for (int i = 0; i + 1 < L; ++i) {
      for (int mask = 0; mask < (1 << b); ++mask) if (d[b][i][mask]) {
//        if (b == 10 && i < 2) cerr << b << ' ' << i << ' ' << mask << ' ' << d[b][i][mask] << endl;
        for (int x = 0; x < b; ++x) {
          d[b][i+1][mask ^ (1 << x)] += d[b][i][mask];
        }
      }
    }
    for (int l = 1; l < L; ++l) {
      d1[b][l] = d1[b][l-1];
      for (int x = 1; x < b; ++x) d1[b][l] += d[b][l-1][1 << x];
    }
/*    for (int i = 1; i < MS; ++i) {
      s[b][i] = s[b][i-1] + mtest(b, i);
      assert(s[b][i] == f(b, i+1));
    }*/
  }
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    ll l, r;
    int b;
    scanf("%d%lld%lld", &b, &l, &r);
    printf("%lld\n", f(b, r+1) - f(b, l));
  }
  return 0;
}