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

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const llint mod = 1e9 + 7;

llint dp[512][512];

int main(void)
{
  const int MAXPOT = 512*512 + 123; // !?
  static llint pot2[MAXPOT]; pot2[0] = 1;
  REP(i, MAXPOT-1) pot2[i+1] = pot2[i] * 2 % mod;

  int n, K; scanf("%d %d", &n, &K);
  memset(dp, 0, sizeof dp);

  dp[0][0] = 1;
  REP(x, n+1) REP(k, K) {
    for (int nx = x+1; nx <= n; ++nx) {
      dp[nx][k+1] += dp[x][k] * ((pot2[nx-x] - 1 + mod)%mod) % mod * pot2[(nx-x)*(n-nx)] % mod;
      if (dp[nx][k+1] >= mod) dp[nx][k+1] -= mod;
    }
  }

  llint ans = 0;
  REP(i, n+1) ans += dp[i][K];
  cout << ans % mod << endl;

  return 0;
}