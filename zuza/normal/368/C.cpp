#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  const int MAXN = 1e5 + 123;
  static char buff[MAXN];
  static int occ[MAXN][3];

  scanf("%s", buff);
  memset(occ[0], 0, sizeof occ[0]);
  for (int i = 0; buff[i]; ++i) {
    REP(j, 3) occ[i+1][j] = occ[i][j];
    occ[i+1][buff[i] - 'x']++;
  }

  int n_q; scanf("%d", &n_q);
  REP(q, n_q) {
    int l, r; scanf("%d %d", &l, &r); --l;
    int kol[3];
    REP(j, 3) kol[j] = occ[r][j] - occ[l][j];
    //    REP(j, 3) printf("%d ", kol[j]); putchar('\n');
    int mini = min(kol[0], min(kol[1], kol[2]));
    REP(j, 3) kol[j] -= mini;
    bool ok = true;
    REP(j, 3) if (kol[j] > 1) ok = false;
    int rupa = (kol[0] != kol[1]) + (kol[1] != kol[2]) + (kol[2] != kol[0]);
    if (rupa > 2) ok = false;
    if (r-l < 3) ok = true;
    puts(ok ? "YES" : "NO");
  }

  return 0;
}