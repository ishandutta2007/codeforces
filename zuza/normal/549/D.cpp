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
  const int MAXN = 123;
  static int grid[MAXN][MAXN];

  int r, c; scanf("%d %d", &r, &c);
  REP(i, r) {
    REP(j, c) {
      char c; scanf(" %c", &c);
      grid[i][j] = (c == 'W') ? +1 : -1;
    }
  }
  
  int ans = 0;
  for (int x = r-1; x >= 0; --x) 
    for (int y = c-1; y >= 0; --y) {
      if (grid[x][y] != 0) {
        int val = grid[x][y];
        ++ans;
        REP(i, x+1) REP(j, y+1) grid[i][j] -= val;
      }
    }

  printf("%d\n", ans);
  return 0;
}