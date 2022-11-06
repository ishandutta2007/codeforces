#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int r, s;
char mat[123][123];

int count_box(int x1, int x2, int y1, int y2, char c) {
  int cnt = 0; FOR(x, x1, x2) FOR(y, y1, y2) cnt += (mat[x][y] == c);
  return cnt;
}

bool check_box(int x1, int x2, int y1, int y2, char c) {
  if (count_box(x1, x2, y1, y2, '.') != (x2-x1)*(y2-y1)) return false;

  if (count_box(x1-1, x1, y1, y2, c) != 0) return false;
  if (count_box(x2, x2+1, y1, y2, c) != 0) return false;
  if (count_box(x1, x2, y1-1, y1, c) != 0) return false;
  if (count_box(x1, x2, y2, y2+1, c) != 0) return false;

  return true;
}

int main(void)
{
  scanf("%d %d", &r, &s);
  REP(i, r) REP(j, s) mat[i][j] = '.';

  REP(i, r) REP(j, s) {
    if (mat[i][j] != '.') continue;
    for (char c = 'A'; c <= 'Z'; ++c) {
      if (!check_box(i, i+1, j, j+1, c)) continue;

      int maks_d = -1;
      for (int d = 1, ub = min(r-i, s-j); d <= ub; ++d) {
        bool can_bef = false;
        for (char bef = 'A'; bef < c; ++bef)
          if (check_box(i, i+1, j+d-1, j+d, bef))
            can_bef = true;
        if (can_bef) break;
        if (check_box(i, i+d, j, j+d, c))
          maks_d = d;
        else break;
      }
      assert(maks_d >= 1);

      FOR(x, i, i+maks_d) FOR(y, j, j+maks_d) mat[x][y] = c;
      break;
    }
  }

  REP(i, r) { REP(j, s) putchar(mat[i][j]); putchar('\n'); }
  return 0;
}