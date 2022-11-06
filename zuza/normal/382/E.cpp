#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  const int MAXN = 51;
  const llint mod = 1e9 + 7;
  
  static llint binom[MAXN][MAXN];
  REP(i, MAXN) { binom[0][i] = 0; binom[i][0] = 1; }
  FOR(i, 1, MAXN) FOR(j, 1, MAXN) binom[i][j] = (binom[i-1][j] + binom[i-1][j-1]) % mod;

  static llint inv[MAXN];
  inv[1] = 1;
  FOR(x, 2, MAXN) inv[x] = (mod - mod/x) * inv[mod%x] % mod;
  FOR(x, 1, MAXN) assert(x * inv[x] % mod == 1);

  int N, K; scanf("%d %d", &N, &K);
  static llint dp[MAXN][MAXN][2];

  REP(n, N+1) REP(k, K+1) REP(r, 2) dp[n][k][r] = 0;
  dp[1][0][0] = 1;

  REP(n, N+1) REP(k, K+1) REP(r, 2) {
    if (n <= 1) continue;
    llint& ref = dp[n][k][r]; ref = 0;

    llint single = 0;
    llint dbl = 0;

    for (int n1 = 1; n1 < n; ++n1) REP(k1, k+1) REP(a, 2) {
      if (n1+1 != n) continue;
      if (1+k1-a != k) continue;
      if (k1 != k-r) continue;

      single += n * dp[n1][k1][a];
      single %= mod;
    }

    for (int n1 = 1; n1 < n; ++n1) {
      int n2 = n - 1 - n1;

      for (int k1 = 0; k1 <= k; ++k1)
        for (int k2 = 0; k2 <= k; ++k2)
          REP(a, 2) REP(b, 2) {
            if (dp[n1][k1][a] == 0) continue;
            if (dp[n2][k2][b] == 0) continue;

            assert(n1+n2+1 == n);
            if (max(1+k1-a+k2, 1+k1+k2-b) != k) continue;
            if (k1+k2 != k-r) continue;

            dbl += n * binom[n-1][n1] % mod * dp[n1][k1][a] % mod * dp[n2][k2][b];
            dbl %= mod;
            //            printf("n = %d k = %d n1 = %d k1 = %d a = %d n2 = %d k2 = %d b = %d -> ref = %lld\n", n, k, n1, k1, a, n2, k2, b, ref);
          }
    }

    ref = single + dbl * inv[2] % mod;
    //    if (ref != 0) {
    //      printf("n = %d k = %d r = %d -> single = %lld dbl = %lld ref = %lld\n", n, k, r, single, dbl, ref);
    //    }
  }

  //  TRACE(dp[N][K][0]);
  //  TRACE(dp[N][K][1]);

  llint sol = (dp[N][K][0] + dp[N][K][1]) % mod * inv[N] % mod;
  cout << sol << endl;

  return 0;
}