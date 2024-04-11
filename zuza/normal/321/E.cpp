#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 4012;
const int MAXK = 812;

int cost[MAXN][MAXN];

const int inf = 1e9;
int dp[MAXK][MAXN];
int opt[MAXK][MAXN];

inline int get_cost(int a, int b) {
  return cost[b][b] - cost[a][b] - cost[b][a] + cost[a][a];
}

int main(void)
{
  cin.sync_with_stdio(false);
  int n, k; cin >> n >> k;
  string buff; getline(cin, buff); assert(buff.size() == 0);  
  REP(i, n+1) REP(j, n+1) if (i == 0 || j == 0) cost[i][j] = 0;
  REP(i, n) {
    getline(cin, buff);
    REP(j, n) cost[i+1][j+1] = buff[2*j] - '0' + cost[i][j+1] + cost[i+1][j] - cost[i][j];
  }

  REP(i, n+1) dp[0][i] = inf; dp[0][n] = 0;

  for (int c = 1; c <= k; ++c) {
    for (int x = 0; x <= n; ++x) {
      int lo = (x-1 >= 0) ? opt[c][x-1] : 0;
      int hi = (c-1 != 0) ? opt[c-1][x] : n;
      dp[c][x] = inf;
      for (int y = lo; y <= hi; ++y) {
        int val = get_cost(x, y) + dp[c-1][y];
        if (val < dp[c][x]) { 
          dp[c][x] = val;
          opt[c][x] = y;
        }
      }
    }
  }

  printf("%d\n", dp[k][0]/2);

  return 0;
}