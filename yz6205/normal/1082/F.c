#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

#define N 505
#define K 12
#define C 10

int val[N], cnt[N], sons[N][C], uid = 1;
int n, k;
char s[N];

int dp[N][N][K];

void dfs(int u)
{
  memset(dp[u], 0x3f, sizeof(dp[u]));
  for (int i=0; i<=uid; ++i)
    dp[u][i][1] = val[u] * i;

  static int pre[N][K];
  for (int _i = 0; _i < C; ++_i)
  {
    int v = sons[u][_i];
    if (!v) continue;

    dfs(v);
    memcpy(pre, dp[u], sizeof(pre));
    memset(dp[u], 0x3f, sizeof(dp[u]));
    for (int d=0; d<uid; ++d)
      for (int i=1; i<=k; ++i)
        for (int j=1; j<=k; ++j)
          if (i + j - 1<= k)
          {
            /* printf("d=%d, i=%d, j=%d: pre[d][i] = %d, dp[v][d+1][j] = %d\n", d,i,j, pre[d][i], dp[v][d + 1][j]); */
            dp[u][d][i + j - 1] = min(dp[u][d][i + j - 1], pre[d][i] + dp[v][d + 1][j]);
            dp[u][d][i + j]     = min(dp[u][d][i + j],     pre[d][i] + dp[v][0][j]);
          }
  }

  /* printf("dfs(%d)\n", u); */
}

int main() 
{
  scanf("%d%d", &n, &k);
  k++;

  for (int i=0; i<n; ++i) 
  {
    int w;
    scanf("%s%d", s, &w);

    int pos = 0;
    char *sp = s;
    while (*sp)
    {
      int c = *sp - '0';
      if (sons[pos][c] == 0)
        sons[pos][c] = uid++;
      pos = sons[pos][c];
      sp++;
    }
    val[pos] += w;
  }

  dfs(0);
  int ans = 0x3f3f3f3f;
  for (int i=1; i<=k; ++i)
    ans = min(ans, dp[0][0][i]);
  printf("%d\n", ans);

  return 0;
}