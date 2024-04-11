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

typedef long long llint;

const int inf = 1e9;

int main(void)
{
  static int popcnt[1024];
  popcnt[0] = 0; for (int i = 1; i < 1024; ++i) popcnt[i] = popcnt[i - (i&-i)] + 1;

  const int MAXN = 123;

  static int A[MAXN];
  int n; scanf("%d", &n);
  REP(i, n) scanf("%d", A+i);
  sort(A, A+n, greater<int>());
  int m; scanf("%d", &m);

  char cmd[21];
  int team[21];

  REP(i, m) {
    scanf(" %c %d", cmd+i, team+i);
  }

  static int dp[1 << 20]; REP(i, 1<<m) dp[i] = inf;
  dp[(1<<m)-1] = 0;

  for (int state = (1<<m) - 2; state >= 0; --state) {
    int ptr = popcnt[state&1023] + popcnt[state >> 10];
    int sgn = team[ptr] == 1 ? +1 : -1;

    auto upd = [state, sgn](int ns, int val) {
      if (dp[ns] == inf) return;

      if (sgn == 1) { // maks
        if (dp[state] == inf || val > dp[state]) dp[state] = val;
      } else {
        if (dp[state] == inf || val < dp[state]) dp[state] = val;
      }
    };

    if (cmd[ptr] == 'p') {
      REP(i, m) if (~state&(1<<i)) {
        upd(state | (1<<i), dp[state | (1<<i)] + sgn*A[i]);
        break;
      }
    } else if (cmd[ptr] == 'b') {
      REP(i, m) if (~state & (1<<i)) {
        upd(state | (1<<i), dp[state | (1<<i)]);
      }
    } else assert(false);
  }

  printf("%d\n", dp[0]);
  return 0;
}