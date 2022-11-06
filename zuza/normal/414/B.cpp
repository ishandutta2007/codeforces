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
#define TRACE(x) cout << #x << " = " << (x) << endl

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int main(void)
{
  const int MAXN = 2012;
  static int dp[MAXN][MAXN];
  static vector<int> E[MAXN];
  const int mod = 1e9 + 7;
  
  auto rem = [](int& x) { if (x >= mod) x -= mod; };

  int maks, n; scanf("%d %d", &maks, &n);
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;

  int par = 0;
  for (int a = 0; a <= maks; ++a)
    for (int b = 1; b <= maks; ++b) {
      if (a == 0 || b%a == 0) { ++par; E[a].push_back(b); }
    }

  for (int i = 0; i < n; ++i)
    for (int last = 0; last <= maks; ++last) {
      for (int b : E[last]) {
        rem(dp[i+1][b] += dp[i][last]);
      }
    }

  int suma = 0;
  for (int last = 1; last <= maks; ++last) rem(suma += dp[n][last]);
  printf("%d\n", suma);
  return 0;
}