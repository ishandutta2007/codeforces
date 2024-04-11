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

const int MAXN = 1e4 + 123;

struct TransVector {
  vector<int> data;
  int lo, hi;

  TransVector(int lo = -MAXN, int hi = MAXN) : lo(lo), hi(hi) {
    clear();
  }

  int& operator[] (int pos) {
    assert(pos >= lo);
    assert(pos <= hi);
    return data[pos - lo];
  }

  void clear() {
    data.clear();
    data.resize(hi - lo + 1, 0);
  }
};

int main(void)
{
  const int mod = 1e9 + 7;
  static TransVector dp[2];

  int n; scanf("%d", &n);
  auto sredi = [](int& x) {
    assert(x >= 0);
    if (x >= mod) x -= mod;
  };
  int sol = 0;

  REP(i_n, n) {
    int x; scanf("%d", &x);

    dp[1].clear();
    sredi(dp[1][x] += 1);
    sredi(dp[1][-x] += 1);

    for (int sum = -MAXN; sum <= MAXN; ++sum) {
      const int bef = dp[0][sum];
      if (bef == 0) continue;
      sredi(dp[1][sum + x] += bef);
      sredi(dp[1][sum - x] += bef);
    }
    for (int sum = -MAXN; sum <= MAXN; ++sum) dp[0][sum] = dp[1][sum];
    sredi(sol += dp[0][0]);
  }

  printf("%d\n", sol);
  return 0;
}