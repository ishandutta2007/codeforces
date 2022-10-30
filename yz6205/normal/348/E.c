#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 100005
#define B 20
#define ninf ((int)(0xcfcfcfcf))

struct edge_t
{
  struct edge_t *next;
  int v, w;
};

struct edge_t *e[N], ep[N * 2], *ep_top = ep;

void add_edge(int u, int v, int w)
{
  ep_top->v    = v;
  ep_top->w    = w;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->w    = w;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

bool is_mon[N];
int n, m;

struct fmon_t
{
  int dep, lca;
};

const struct fmon_t fmon_ninf = {ninf, ninf};

struct fmon_t fmon_join(struct fmon_t a, struct fmon_t b, int u)
{
  if (a.dep != b.dep)
    return a.dep > b.dep ? a : b;
  struct fmon_t res = { a.dep, u };
  return res;
}

struct fmon_t fmon_inc(struct fmon_t x, int y)
{
  x.dep += y;
  return x;
}

int fa[N][B], dep[N];
struct fmon_t val[N], dp[N];
void dfs0(int u, int f)
{
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  for (int i=0; i+1<B; ++i)
    fa[u][i + 1] = fa[fa[u][i]][i];

  dp[u] = val[u];
  for (struct edge_t *i = e[u]; i; i = i->next) if (i->v != f)
  {
    dfs0(i->v, u);
    dp[u] = fmon_join(dp[u], fmon_inc(dp[i->v], i->w), u);
  }
}

int lca(int u, int v)
{
  if (dep[u] < dep[v]) 
    return lca(v, u);
  int delta = dep[u] - dep[v];
  for (int i=0; i<B; ++i) 
    if (delta & (1 << i))
      u = fa[u][i];
  for (int i=B-1; i>=0; i--)
    if (fa[u][i] != fa[v][i])
      u = fa[u][i], v = fa[v][i];
  return u == v ? u : fa[u][0];
}

void dfs1(int u, int f, struct fmon_t fdp)
{
  /* printf("dfs1: u = %d, fdp = { dep = %d, lca = %d }\n", u, fdp.dep, fdp.lca); */
  dp[u] = fmon_join(dp[u], fdp, u);

  static int sons[N], sonw[N];
  int *sons_top = sons, *sonw_top = sonw;
  for (struct edge_t *i = e[u]; i; i = i->next) if (i->v != f)
  {
    *sons_top++ = i->v;
    *sonw_top++ = i->w;
  }

  struct fmon_t *sdp = (struct fmon_t*)malloc((size_t)(sons_top - sons) 
                                              * sizeof(struct fmon_t));
  struct fmon_t pos = fmon_join(fdp, val[u], u);
  for (int i=0; i < sons_top - sons; i++)
  {
    sdp[i] = pos;
    pos = fmon_join(pos, fmon_inc(dp[sons[i]], sonw[i]), u);
  }
  pos = fmon_ninf;
  for (int i = (int)(sons_top - sons) - 1; i >= 0; i--)
  {
    sdp[i] = fmon_join(sdp[i], pos, u);
    pos = fmon_join(pos, fmon_inc(dp[sons[i]], sonw[i]), u);
  }

  struct fmon_t *sdp_i = sdp;
  for (struct edge_t *i = e[u]; i; i = i->next) if (i->v != f)
  {
    dfs1(i->v, u, fmon_inc(*sdp_i++, i->w));
  }

  free(sdp);
}

int tot[N];
void dfs2(int u, int f)
{
  for (struct edge_t *i = e[u]; i; i = i->next) if (i->v != f)
  {
    dfs2(i->v, u);
    tot[u] += tot[i->v];
  }
}

int main()
{
  memset(val, 0xcf, sizeof(val));

  scanf("%d%d", &n, &m);
  for (int i=0; i<m; ++i)
  {
    int u;
    scanf("%d", &u);
    is_mon[u] = true;
    val[u].dep = 0, val[u].lca = u;
  }
  for (int i=1; i<n; ++i)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, w);
  }

  dfs0(1, 0);
  dfs1(1, 0, fmon_ninf);
  for (int i=1; i<=n; ++i) if (is_mon[i])
  {
    int u = i, v = dp[i].lca;
    /* printf("%d, %d\n", u, v); */
    int l = lca(u, v);
    tot[u]++, tot[v]++, tot[l]--, tot[fa[l][0]]--;
  }
  dfs2(1, 0);

  int cut_val = -1, cut_cnt = -1;
  for (int i=1; i<=n; ++i) if (!is_mon[i])
  {
    if (tot[i] > cut_val)
      cut_val = tot[i], cut_cnt = 1;
    else if (tot[i] == cut_val)
      cut_cnt++;
  }

  printf("%d %d\n", cut_val, cut_cnt);

  return 0;
}