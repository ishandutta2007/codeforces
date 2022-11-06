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

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int mod = 1e9 + 7;
const int MAXN = 330;
const int MAXM = 50; // pazi dalje

int dp[2][MAXN][MAXN];
int binom[MAXN][MAXN];

int main(void)
{
  int n, m, L; scanf("%d %d %d", &n, &m, &L); --L;

  if (n > m) printf("0\n"), exit(0);
  REP(i, MAXN) binom[0][i] = 0;
  REP(i, MAXN) binom[i][0] = 1;

  for (int i = 1; i < MAXN; ++i)
    for (int j = 1; j < MAXN; ++j) {
      binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
      if (binom[i][j] >= mod) binom[i][j] -= mod;
    }

  memset(dp, 0, sizeof dp);
  dp[0][0][0] = 1;

  for (int x = 0; x < m; ++x) {
    REP(b, n+1) REP(c, n+1) dp[1][b][c] = 0;

    for (int open = 0; open <= n; ++open)
      for (int kol = 0; kol <= n; ++kol) {
        int bef = dp[0][open][kol];
        if (bef == 0) continue;

        auto upd = [bef, &dp](int x2, int open2, int kol2) {
          dp[1][open2][kol2] += bef;
          if (dp[1][open2][kol2] >= mod) dp[1][open2][kol2] -= mod;
        };
        
        // nista ne stavi
        if (x != L) {
          upd(x+1, open, kol);
        }

        // stavi otvorenu
        if (kol+1 <= n) {
          upd(x+1, open+1, kol+1);
        }

        // stavi zatvorenu
        if (x != L && open > 0) {
          upd(x+1, open-1, kol);
        }

        // stavi otvorenu i zatvorenu
        if (kol+1 <= n) {
          upd(x+1, open, kol+1);
        }
      }

    REP(b, n+1) REP(c, n+1) dp[0][b][c] = dp[1][b][c];
  }

  llint sol = dp[0][0][n];
  for (int i = 1; i <= n; ++i) {
    sol = sol * i % mod;
  }

  printf("%d\n", (int)sol);
  return 0;
}