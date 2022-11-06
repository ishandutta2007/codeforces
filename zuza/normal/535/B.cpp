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
  int ans = 0;
  int n; scanf("%d", &n);
  FOR(L, 1, 10) {
    REP(state, 1<<L) {
      int x = 0;
      REP(i, L) if (state&(1<<i)) x = x*10 + 4; else x = x*10 + 7;
      ans += (x < n);
    }
  }
  printf("%d\n", ans+1);
  return 0;
}