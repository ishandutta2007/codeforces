#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Inter {
  int lo, hi;
  int up, left;
  friend bool operator < (const Inter& a, const Inter& b) {
    return a.lo < b.lo;
  }
};

int main(void) {
  int n, q; scanf("%d %d", &n, &q);

  set<Inter> S; S.insert({0, n, 0, 0});
  REP(i, q) {
    int x, y; char c; scanf("%d %d %c", &x, &y, &c); --x, --y;
    int v = x;

    Inter I = *prev(S.upper_bound({v, -1, -1, -1}));
    int ans = -1;

    if (I.lo <= v && v < I.hi) {
      S.erase(I);
      int du = -1, ul = -1;
      if (c == 'U') {
        ans = I.up + I.hi - v;
        du = ans;
        ul = 0;
      } else {
        ans = I.left + v - I.lo + 1;
        du = 0;
        ul = ans;
      }
      S.insert({I.lo, v, du, I.left}); // down
      S.insert({v+1, I.hi, I.up, ul});   // up
    } else {
      ans = 0;
    }
    printf("%d\n", ans);
  }

  

  return 0;
}