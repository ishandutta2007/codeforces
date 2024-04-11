#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;
const LL inf = 1ll << 60;

set<int> pl;
LL dp[MAXN][3];
int x[MAXN], n, a, b;

void gao(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      pl.insert(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) pl.insert(n);
}

void upd(LL &x, LL y) {
  if (x > y) x = y;
}
LL get(int x, int y) {
  x %= y;
  if (x == 0) return 0;
  else if (x == 1 || x == y - 1) return b;
  else return inf;
}

LL solve(int p) {
  dp[1][0] = get(x[1], p);
  dp[1][1] = dp[1][2] = inf;
  for (int i = 2; i <= n; ++i) {
    dp[i][0] = dp[i][1] = dp[i][2] = inf;
    LL cost = get(x[i], p);
    upd(dp[i][0], dp[i - 1][0] + cost);
    upd(dp[i][2], dp[i - 1][2] + cost);
    upd(dp[i][2], dp[i - 1][1] + cost);
    upd(dp[i][1], dp[i - 1][0] + a);
    upd(dp[i][1], dp[i - 1][1] + a);
  }
  return min(dp[n][0], min(dp[n][1], dp[n][2]));
}

void run() {
  pl.clear();
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%d", x + i);
  gao(x[1]); gao(x[1] + 1); gao(x[1] - 1);
  gao(x[n]); gao(x[n] + 1); gao(x[n] - 1);
  LL ret = inf;
  for (auto &p: pl) upd(ret, solve(p));
  reverse(x + 1, x + 1 + n);
  for (auto &p: pl) upd(ret, solve(p));
  printf("%lld\n", ret);
}

int main() {
  //int T; scanf("%d", &T);
  //for (int cas = 1; cas <= T; ++cas) run();
  run();
  return 0;
}