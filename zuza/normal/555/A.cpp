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
  int nn, nc; scanf("%d %d", &nn, &nc);
  int maks = 1;
  int ans = 0;

  REP(ic, nc) {
    int nx = 1; int cnt = 0;
    int k; scanf("%d", &k);
    ans += k-1;
    REP(j, k) {
      int x; scanf("%d", &x);
      if (x == nx) { ++nx; ++cnt; }
    }
    maks = max(maks, cnt);
  }

  ans -= maks - 1;
  ans += nn - maks;
  printf("%d\n", ans);

  return 0;
}