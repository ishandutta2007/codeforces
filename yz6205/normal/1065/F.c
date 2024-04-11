#include <stdio.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

#define N 1000005

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], ep[N], *ep_top = ep;

void add_edge(int u, int v)
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
}

int n, k;

int dep[N], nleaf[N];
int dp[N][2];

void dfs(int u)
{
  if (e[u]) nleaf[u] = 0x3f3f3f3f, dp[u][0] = 0, dp[u][1] = 0;
  else nleaf[u] = 0, dp[u][0] = 1, dp[u][1] = 1;
  
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    dfs(v);

    nleaf[u] = min(nleaf[u], nleaf[v] + 1);
    int v0 = nleaf[v] + 1 <= k ? dp[v][0] : 0;
    int v1 = dp[v][1];
    dp[u][1] = max(dp[u][1] + v0, dp[u][0] + v1);
    dp[u][0] += v0;
  }
}

int main()
{
  scanf("%d%d", &n, &k);
  for (int i=2; i<=n; ++i)
  {
    int f;
    scanf("%d", &f);
    add_edge(f, i);
  }

  dfs(1);
  printf("%d\n", dp[1][1]);
  return 0;
}