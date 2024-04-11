#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void)
{
  int orig, k, perc; scanf("%d %d %d", &orig, &k, &perc);
  double p = perc / 100.;

  const int MAXN = 213;
  static double dp[MAXN][MAXN];

  REP(x, k+1) REP(a, k+1) {
    if (x == 0) {
      int s = 0; for (int tmp = orig+a; tmp%2 == 0; tmp /= 2) ++s;
      dp[x][a] = s;
    } else {
      dp[x][a] += (1-p)*dp[x-1][a+1];
      if (a%2 == 0) dp[x][a] += p*(1 + dp[x-1][a/2]);
    }
  }

  printf("%.9lf\n", dp[k][0]);
  return 0;
}