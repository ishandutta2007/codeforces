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
//const int mod = ;

int main() {
//  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    ll p,q,b;
    scanf("%lld%lld%lld", &p, &q, &b);
    ll d = __gcd(p, q);
    p /= d; q /= d;
    d = b;
    while (true) {
      d = __gcd(q, d);
      if (d == 1) break;
      while (q % d == 0) q /= d;
    }
    if (q == 1) printf("Finite\n");
    else printf("Infinite\n");
  }
  return 0;
}