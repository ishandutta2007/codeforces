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

llint m; int k;

char prefix[64];

char lo[64];
char hi[64];

llint dp[70][70];
llint pot2[70];

llint solve(int x, int jed, llint clo, llint chi, llint tlo, llint thi) {
  if (chi <= tlo) return 0;
  if (thi <= clo) return 0;
  if (x == 0) {
    return jed == k;
  }
  if (tlo <= clo && chi <= thi) if (dp[x][jed] != -1) return dp[x][jed];


  llint ans = 0;
  ans += solve(x-1, jed    , clo, clo+pot2[x-1], tlo, thi);
  ans += solve(x-1, jed + 1, clo+pot2[x-1], chi, tlo, thi);

  if (tlo <= clo && chi <= thi) dp[x][jed] = ans;
  return ans;
}

int main(void)
{
  cin >> m >> k;
  pot2[0] = 1; FOR(i, 1, 70) pot2[i] = pot2[i-1] * 2ll;

  llint lo = 1, hi = 1e18;
  while (lo < hi) {
    llint mid = (lo + hi) / 2; // !?

    memset(dp, -1, sizeof dp);
    llint val = solve(61, 0, 0, pot2[61], mid, 2*mid);

    if (val < m)
      lo = mid + 1;
    else
      hi = mid;
  }
  cout << lo << endl;

  return 0;
}