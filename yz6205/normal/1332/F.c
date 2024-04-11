#include <stdio.h>

#define MOD 998244353
#define N 300005

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[N * 2], *ep_top = e_pool;

void add_edge(int u, int v) 
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

long long dp[N][3];
void dfs(int u, int f)
{
  dp[u][0] = 1, dp[u][1] = 1, dp[u][2] = 1;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u);
    dp[u][2] = dp[u][2] * (dp[v][0] + dp[v][1]) % MOD;
    dp[u][1] = dp[u][1] * (dp[v][0] + dp[v][1] + dp[v][2]) % MOD;
    dp[u][0] = dp[u][0] * (dp[v][0]) % MOD;
  }
  dp[u][0] = (dp[u][1] + dp[u][2] - dp[u][0] + MOD) % MOD;
}

int n;

int main() 
{
  scanf("%d", &n);
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  dfs(1, 0);
  printf("%lld\n", (dp[1][0] + MOD - 1) % MOD);

  return 0;
}