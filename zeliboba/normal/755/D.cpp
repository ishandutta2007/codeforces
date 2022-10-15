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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vi fen;

void add(int i) {
  for (; i < fen.size(); i |= i+1)
    ++fen[i];
}

int sum(int i) {
  int s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    s += fen[i];
  return s;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  k = min(k, n - k);
  fen.assign(n, 0);
  int x = 0;
  ll res = 1;
  for (int i = 0; i < n; ++i) {
    int nx = (x + k) % n;
    int a = 1;
    if (nx > x) {
      a += sum(nx - 1) - sum(x);
    } else {
      a += sum(nx - 1) + sum(n-1) - sum(x);
    }
    res += a;
    add(x);
    add(nx);
//    cerr << x << ' ' << nx << endl;
    x = nx;
    printf("%lld ", res);
    //printf("%lld\n", res);
  }
  return 0;
}