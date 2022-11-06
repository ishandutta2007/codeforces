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
  int r, s; scanf("%d %d", &r, &s);
  char grid[52][52];
  REP(i, r) scanf("%s", grid[i]);

  int ans = 0;
  REP(i, r-1) REP(j, s-1) {
    int a[4] = {0};
    for (char c : {grid[i][j], grid[i][j+1], grid[i+1][j], grid[i+1][j+1]}) {
      if (c == 'f') a[0] = true;
      if (c == 'a') a[1] = true;
      if (c == 'c') a[2] = true;
      if (c == 'e') a[3] = true;
    }
    if (a[0] && a[1] && a[2] && a[3]) ++ans;
  }
  printf("%d\n", ans);

  return 0;
}