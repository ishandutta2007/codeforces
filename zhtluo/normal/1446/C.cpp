#include <bits/stdc++.h>

const int MAX = 210000 * 32;

int N;
long long A[210000];
int ch[MAX][2], size = 1;
int nsize[MAX];
int dp[MAX];

int main() {
#ifdef LOCAL_JUDGE
  freopen(".in", "r", stdin);
#endif
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
  for (int i = 0; i < N; ++i) {
    int r = 0;
    for (int j = 31; j >= 0; --j) {
      ++nsize[r];
      if (ch[r][A[i] >> j & 1]) r = ch[r][A[i] >> j & 1];
      else r = (ch[r][A[i] >> j & 1] = size++);
    }
    ++nsize[r]; 
  }
  for (int r = size - 1; r >= 0; --r) {
    if (nsize[r] <= 2) dp[r] = nsize[r];
    else if (!ch[r][0]) dp[r] = dp[ch[r][1]];
    else if (!ch[r][1]) dp[r] = dp[ch[r][0]];
    else {
      dp[r] = std::max(dp[ch[r][0]] + 1, dp[ch[r][1]] + 1);
    }
  }
  printf("%d\n", N - dp[0]);
}