#include <cassert>
#include <cstring>

#include <cstdio>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 312;

int L[MAXN];
int C[MAXN];

const int inf = 1e9;

int main(void) {
  int n; scanf("%d", &n);
  
  REP(i, n) scanf("%d", L+i);
  REP(i, n) scanf("%d", C+i);

  int ans = inf;

  REP(take, n) {
    int tmp = L[take];
    static vector<int> fs; fs.clear();

    for (int i = 2; tmp > 1; ++i) {
      if (i*i > tmp) i = tmp;
      if (tmp%i == 0) {
        while (tmp%i == 0) tmp /= i;
        fs.push_back(i);
      }
    }

    const int MAXLOG = 15;
    static int dp[312][1 << MAXLOG];

    int sz = fs.size();
    REP(a, 312) REP(b, 1<<sz) dp[a][b] = inf;
    dp[0][0] = 0;

    REP(a, n) {
      REP(b, 1<<sz) {
        if (dp[a][b] >= inf) continue;
        if (a == take) dp[a+1][b] = min(dp[a+1][b], dp[a][b]);
        
        int nm = b;
        REP(i, sz) if (L[a] % fs[i] != 0) nm |= 1<<i;

        dp[a+1][b] = min(dp[a+1][b], dp[a][b]);
        dp[a+1][nm] = min(dp[a+1][nm], dp[a][b] + C[a]);
      }
    }

    ans = min(ans, C[take] + dp[n][(1<<sz)-1]);
  }

  printf("%d\n", ans >= inf ? -1 : ans);
  return 0;
}