#include <stdio.h>

#define N 100005

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[N * 2], *ep_top = e_pool;
int deg[N];

void add_edge(int u, int v)
{
  deg[u]++, deg[v]++;
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

int n, ans;

void check_max(int *a, int b)
{
  if (b > *a) *a = b;
}

int dp[N][2];
void dfs(int u, int f)
{
  int sons = deg[u] - 1;
  dp[u][0] = sons, dp[u][1] = 1;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u);
    
    check_max(&ans, dp[u][0] + dp[v][0]);
    check_max(&ans, dp[u][0] + dp[v][1]);
    check_max(&ans, dp[u][1] + dp[v][0]);

    check_max(&dp[u][0], dp[v][0] + sons - 1);
    check_max(&dp[u][0], dp[v][1] + sons - 1);
    check_max(&dp[u][1], dp[v][0] + 1);
  }

  check_max(&ans, dp[u][0]);
  check_max(&ans, dp[u][1]);
  // printf("dp[%d] = { %d, %d }\n", u, dp[u][0], dp[u][1]);
}

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
  printf("%d\n", ans);
  return 0;
}