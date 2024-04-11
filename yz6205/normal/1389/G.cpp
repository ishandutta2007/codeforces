#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define N 300005
#define M 600005
#define long long long
#define this t

struct edge_t
{
  struct edge_t *next;
  int v, w;
};

struct graph_t
{
  struct edge_t *e[N];
  struct edge_t e_pool[M], *ep_top;
};

void graph_init(struct graph_t *this)
{
  this->ep_top = this->e_pool;
}

void add_edge(struct graph_t *this, int u, int v, int w)
{
  this->ep_top->v    = v;
  this->ep_top->w    = w;
  this->ep_top->next = this->e[u];
  this->e[u] = this->ep_top++;
  this->ep_top->v    = u;
  this->ep_top->w    = w;
  this->ep_top->next = this->e[v];
  this->e[v] = this->ep_top++;
}

struct graph_t G, SG;
int special[N], g_eu[N], g_ev[N], g_ew[N], c[N];
long sc[N], ssc[N];
bool is_special[N], is_cspecial[N];
int n, m, k, root;

int dfn[N], low[N], bel[N], dfn_top, bel_top;
void dfs0(int u, int f)
{
  static int stack[N], *stack_top = stack;
  low[u] = dfn[u] = dfn_top++; 
  *stack_top++ = u;
  for (struct edge_t *i = G.e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    if (dfn[v] == -1)
      dfs0(v, u);
    if (low[v] < low[u])
      low[u] = low[v];
  }
  if (low[u] == dfn[u])
  {
    int pos_bel = bel_top++;
    do {
      stack_top--;
      bel[*stack_top] = pos_bel;
    } while (*stack_top != u);
  }
}

int c_special_sum[N];
int cleaf_bel[N];
int get_cleaf_final(int u)
{
  return u==cleaf_bel[u] ? u : (cleaf_bel[u] = get_cleaf_final(cleaf_bel[u]));
}
void dfs1(int u, int f)
{
  c_special_sum[u] = 0;
  for (struct edge_t *i = SG.e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs1(v, u);
    c_special_sum[u] += c_special_sum[v];
  }
  if (c_special_sum[u] == 0)
    SG.e[u] = NULL;
  c_special_sum[u] += is_cspecial[u];
  if (c_special_sum[u] == 0)
    cleaf_bel[u] = f;
}

long dp[N];
void dfs2(int u, int f)
{
  dp[u] = ssc[u];
  for (struct edge_t *i = SG.e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    eprintf("dfs2: %d -> %d \n", u, v);
    dfs2(v, u);
    if (dp[v] - i->w > 0)
      dp[u] += dp[v] - i->w;
  }
  eprintf("dfs2(%d): dp = %lld\n", u, dp[u]);
}

long ans[N];
void dfs3(int u, int f, long pre)
{
  eprintf("dfs3(%d) pre = %lld\n", u, pre);
  if (pre < 0) pre = 0;
  ans[u] = dp[u] + pre;
  for (struct edge_t *i = SG.e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    long cur_sub = dp[v] - i->w;
    if (cur_sub < 0) cur_sub = 0;
    dfs3(v, u, dp[u] - cur_sub + pre - i->w);
  }
}

int main()
{
  graph_init(&G);
  graph_init(&SG);

  scanf("%d%d%d", &n, &m, &k);
  for (int i=0; i<k; ++i)
  {
    scanf("%d", &special[i]);
    is_special[special[i]] = true;
  }
  for (int i=1; i<=n; ++i) scanf("%d", &c[i]);
  for (int i=0; i<m; ++i) scanf("%d", &g_ew[i]);
  for (int i=0; i<m; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    g_eu[i] = u, g_ev[i] = v;
    add_edge(&G, u, v, g_ew[i]);
  }

  memset(dfn, -1, sizeof(dfn));
  dfs0(1,0);
  for (int i=1; i<=n; ++i)
    sc[bel[i]] += c[i];
  for (int i=0; i<k; ++i)
    is_cspecial[bel[special[i]]] = true;
  for (int i=0; i<m; ++i)
  {
    const int u = g_eu[i], v = g_ev[i];
    if (bel[u] != bel[v])
      add_edge(&SG, bel[u], bel[v], g_ew[i]);
  }
  
  root = bel[special[0]];
  for (int i=0; i<n; ++i) cleaf_bel[i] = i;
  dfs1(root, root);
  for (int i=0; i<bel_top; ++i)
    ssc[get_cleaf_final(i)] += sc[i];
  dfs2(root, root);
  dfs3(root, root, 0);

  for (int i=1; i<=n; ++i)
    printf("%lld%c", ans[get_cleaf_final(bel[i])], " \n"[i==n]);

  return 0;
}