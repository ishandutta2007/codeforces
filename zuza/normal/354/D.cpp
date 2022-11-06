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

const int MAXDIM = 1e5 + 10;
const int MAXH = 805;

const int inf = 1e9;

int main(void)
{
  static vector<int> E[MAXDIM];

  int dim, k; scanf("%d %d", &dim, &k);
  int add = 0;
  REP(i, k) {
    int x, y; scanf("%d %d", &x, &y); --y;
    x = dim - x + 1;
    if (x >= MAXH) add += 3;
    else E[y].push_back(x);
  }
  REP(i, dim) sort(E[i].begin(), E[i].end(), greater<int>());

  static int dp[2][MAXH];
  REP(i, MAXH) dp[1][i] = inf;
  dp[1][0] = add;

  auto get_cost = [](int h) {
    if (h <= 0) return 0;
    return 2 + h*(h+1) / 2;
  };

  for (int y = dim-1; y >= 0; --y) {
    REP(i, MAXH) dp[0][i] = inf;
    int add = 0;
    int y_ptr = 0;
    int min_higher = inf;

    for (int h = MAXH-1; h >= 0; --h) {
      if (h <= dim-(y+1)) min_higher = min(min_higher, dp[1][h]);
      while (y_ptr < (int)E[y].size() && E[y][y_ptr] > h) { add += 3; ++y_ptr; }

      dp[0][h] = min(dp[0][h], dp[1][max(0, h-1)] + add + get_cost(h) - get_cost(h-1));
      dp[0][h] = min(dp[0][h], min_higher + add + get_cost(h));
    }
    REP(i, MAXH) dp[1][i] = dp[0][i];
  }

  int mini = inf;
  REP(i, MAXH) mini = min(mini, dp[1][i]);
  printf("%d\n", mini);
  return 0;
}