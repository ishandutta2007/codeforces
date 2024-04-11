#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define int long long

#define N 200005

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

int w[N], h[N], n;

int dp[N][2];

int32_t cmp_int(const void *const a, const void *const b)
{
  int pa = *(const int*)a, pb = *(const int*)b;
  if (pa == pb) return 0;
  return pa < pb ? -1 : 1;
}

int min(int a, int b) 
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

void dfs(int u, int f)
{
  static int st[N];
  int *st_top = st;
  int sum = 0, a = 0, b = 0;

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u);
  }

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    if (h[v] <= h[u])
      sum += dp[v][0], a++;
    else 
      sum += dp[v][1], b++;

    if (h[v] == h[u])
      *st_top++ = dp[v][1] - dp[v][0];
  }

  qsort(st, st_top-st, 8, cmp_int);
  *st_top++ = 0;
  for (int *i = st; i < st_top; ++i) 
  {
    dp[u][0] = min(dp[u][0], sum + max(a, b + (u != 1)) * w[u]);
    dp[u][1] = min(dp[u][1], sum + max(a + (u != 1), b) * w[u]);
    a--, b++;
    sum += *i;
  }
}

int32_t main() 
{
  scanf("%lld", &n);
  for (int i=1; i<=n; ++i) scanf("%lld", &w[i]);
  for (int i=1; i<=n; ++i) scanf("%lld", &h[i]);
  for (int i=1; i<n; ++i) 
  {
    int u, v;
    scanf("%lld%lld", &u, &v);
    add_edge(u, v);
  }

  memset(dp, 63, sizeof(dp));
  dfs(1, 0);
  printf("%lld\n", min(dp[1][0], dp[1][1]));

  return 0;
}