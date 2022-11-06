#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  llint A, B; int nq; scanf("%lld %lld %d", &A, &B, &nq);
  REP(iq, nq) {
    llint L, t, m; scanf("%lld %lld %lld", &L, &t, &m); --L;
    if (A+L*B > t) { printf("-1\n"); continue; }

    llint lo = L, hi = 2e6 + 123;
    while (lo < hi) {
      llint mid = (lo+hi+1) / 2;
      llint suma = (A+L*B + A+mid*B) * (mid-L+1) / 2;
      if (suma <= m*t && A+mid*B <= t)
        lo = mid;
      else
        hi = mid - 1;
    }

    printf("%lld\n", lo+1);
  }
  return 0;
}