#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
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

int main(void)
{
  static int A[123][123];
  const int inf = 1e9;

  int R, S, k; scanf("%d %d %d", &R, &S, &k);
  REP(i, R) REP(j, S) scanf("%d", A[i]+j);

  int ans = inf;
  REP(m, S) {
    int val = 0;
    REP(j, S) {
      int diff = 0;
      REP(i, R) diff += (A[i][j] != A[i][m]);
      val += min(diff, R-diff);
    }
    if (val < ans) ans = val;
  }

  if (S <= k) {
    REP(state, 1<<S) {
      int val = 0;
      REP(i, R) {
        int diff = 0;
        REP(j, S) diff += (A[i][j] != ((state>>j)&1));
        val += min(diff, S-diff);
      }
      if (val < ans) ans = val;
    }
  }

  if (ans > k) puts("-1");
  else printf("%d\n", ans);
  return 0;
}