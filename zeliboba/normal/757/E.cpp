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

const int mod = 1000000007;
const int N = 1000000;
const int K = 20;
int d[N+1][K+1];

int dw(int x) {
  if (x < mod) return x;
  return x - mod;
}

int main() {
  d[0][0] = 1;
  for (int k = 1; k <= K; ++k) d[0][k] = 2;
  for (int r = 1; r <= N; ++r) {
    d[r][0] = 1;
    for (int k = 1; k <= K; ++k) {
      d[r][k] = dw(d[r][k-1] + d[r-1][k]);
    }
  }
//  cerr << d[1][0] << ' ' << d[1][1] << ' ' << d[1][2] << endl;
  vi erat(N+1);
  for (int i = 1; i < erat.size(); ++i) erat[i] = i;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = i;
  }
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    int r, n;
    scanf("%d%d", &r, &n);
    ll res = 1;
    while (n > 1) {
      int p = erat[n], c = 0;
      while (n % p == 0) {
        ++c;
        n /= p;
      }
      res = res * d[r][c] % mod;
    }
    printf("%lld\n", res);
  }
  return 0;
}