#include <bits/stdc++.h>

int N, M;
int dp[6000][6000];
char A[6000], B[6000];

int main() {
#ifdef LOCAL_JUDGE
  freopen(".in", "r", stdin);
#endif
  scanf("%d%d %s %s", &N, &M, A, B);
  int res = 0;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      dp[i][j] = std::max(dp[i][j], dp[i - 1][j] - 1);
      dp[i][j] = std::max(dp[i][j], dp[i][j - 1] - 1);
      if (A[i - 1] == B[j - 1]) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 2);
      res = std::max(res, dp[i][j]);
    }
  printf("%d\n", res);
}