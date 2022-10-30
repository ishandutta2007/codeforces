#include <stdio.h>
#include <string.h>

#define N 3005
#define long long long

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[N * 2], *ep_top;
int n, t, w[N];

void clear_tree()
{
  ep_top = e_pool;
  for (int i=1; i<=n; ++i) e[i] = NULL;
}

void add_edge(int u, int v)
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

void rinit()
{
  scanf("%d%d", &n, &t);
  clear_tree();
  memset(w, 0, sizeof(int) * (n + 1));
  for (int i=1; i<=n; ++i) 
  {
    int a;
    scanf("%d", &a);
    w[i] -= a;
  }
  for (int i=1; i<=n; ++i)
  {
    int a;
    scanf("%d", &a);
    w[i] += a;
  }
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
}

struct dp_t
{
  int cnt;
  long val;
};

struct dp_t dp_join(struct dp_t a, struct dp_t b)
{
  /* printf("join: {%d, %lld}, {%d, %lld}\n", a.cnt, a.val, b.cnt, b.val); */
  struct dp_t res = 
  {
    .cnt = a.cnt + b.cnt,
    .val = a.val + b.val
  };
  return res;
}

struct dp_t dp_add(struct dp_t a, struct dp_t b)
{
  struct dp_t res = 
  {
    .cnt = a.cnt + b.cnt + (b.val > 0),
    .val = a.val
  };
  return res;
}

struct dp_t dp_max(struct dp_t a, struct dp_t b)
{
  if (a.cnt > b.cnt || (a.cnt == b.cnt && a.val > b.val))
    return a;
  return b;
}

struct dp_t dp[N][N];
int size[N];

void dfs(int u, int f)
{
  static struct dp_t pre[N];
  dp[u][1].cnt = 0, dp[u][1].val = w[u];
  size[u] = 1;

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u);

    memcpy(pre + 1, dp[u] + 1, sizeof(*pre) * size[u]);
    for (int i=1; i<=size[u] + size[v]; ++i)
      dp[u][i].cnt = -1;

    for (int i=size[u]; i>=1; --i)
      for (int j=size[v]; j>=1; --j)
        dp[u][i + j] = dp_max(dp[u][i + j], dp_add(pre[i], dp[v][j])),
        dp[u][i + j - 1] = dp_max(dp[u][i + j - 1], dp_join(pre[i], dp[v][j]));
    size[u] += size[v];
  }
}

void rmain()
{
  dfs(1, 0);
  /* printf("dp[1][%d] = {%d, %lld}\n", t, dp[1][t].cnt, dp[1][t].val); */
  printf("%d\n", dp[1][t].cnt + (dp[1][t].val > 0));
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) 
  {
    rinit();
    rmain();
  }
  return 0;
}