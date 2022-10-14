#include <bits/stdc++.h>

long long MAX = 1E18;

int N, P, K;
char pat[110000];
long long dp[110000];
int X, Y;

int main() {
#ifdef LOCAL_JUDGE
  freopen(".in", "r", stdin);
#endif
  int T; scanf("%d", &T); while (T--) {
    scanf("%d%d%d", &N, &P, &K);
    scanf(" %s", pat);
    scanf("%d%d", &X, &Y);
    for (int i = N - 1; i >= 0; --i) {
      if (i + K < N) dp[i] = dp[i + K];
      else dp[i] = 0;
      if (pat[i] == '0') dp[i] += X;
    }
    long long cost = MAX;
    for (int i = P - 1; i < N; ++i)
      cost = std::min(cost, dp[i] + 1ll * (i - (P - 1)) * Y);
    printf("%lld\n", cost);
  } 
}