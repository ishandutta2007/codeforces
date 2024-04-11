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

const int mod = 1e9 + 7;

void sredi(llint& x) { x %= mod; }

int main(void)
{
  static llint dp[123][123][2]; memset(dp, 0, sizeof dp);
  int n, k, d; scanf("%d %d %d", &n, &k, &d);

  dp[0][0][0] = true;

  llint ans = 0;
  REP(l, n+1) REP(s, n+1) REP(t, 2) {
    llint bef = dp[l][s][t];
    if (bef == 0) continue;
    if (s == n && t) ans = (ans + bef) % mod;

    FOR(p, 1, k+1) {
      if (s+p <= n) sredi(dp[l+1][s+p][t || (p >= d)] += bef);
    }
  }

  cout << ans << endl;
  return 0;
}