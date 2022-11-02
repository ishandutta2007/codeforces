#include <stdio.h>
#include <string.h>

#ifdef  __LOCALE__
#define eprintf(...) do { printf(__VA_ARGS__); fflush(stdout); } while(0)
#else
#define eprintf(...)
#endif

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b, *b = tmp;
}

#define MOD 998244353
#define N 300005
#define B 20

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], ep[N * 4], *ep_top = ep;
int eu[N], ev[N];

void add_edge(int u, int v)
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

int fa[N][B], dep[N];
void dfs0(int u, int f)
{
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  for (int i=0; i+1<B; ++i)
    fa[u][i + 1] = fa[fa[u][i]][i];
  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != f) dfs0(i->v, u);
}

int lca(int u, int v)
{
  if (dep[u] < dep[v])
    swap(&u, &v);
  int delta = dep[u] - dep[v];
  for (int i=0; i<B; ++i)
    if (delta & (1 << i))
      u = fa[u][i];
  for (int i=B-1; i>=0; --i) 
    if (fa[u][i] != fa[v][i])
      u = fa[u][i], v = fa[v][i];
  return u == v ? u : fa[u][0];
}

int col[N], col2lca[N], bel[N], ucol[N];
int n, k;

/* void dfs1(int u, int f) */
/* { */
/*   lca_cnt[u] += lca_cnt[f]; */
/*   for (struct edge_t *i = e[u]; i; i = i->next) */
/*     if (i->v != f) dfs1(i->v, u); */
/* } */

struct edge_t *e2[N];

void add_edge2(int u, int v)
{
  eprintf("add_edge_2 %d %d\n", u, v);
  ep_top->v    = v;
  ep_top->next = e2[u];
  e2[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e2[v];
  e2[v] = ep_top++;
}

int dp[N][2];
void dfs2(int u, int f)
{
  dp[u][0] = !ucol[u];
  dp[u][1] = !!ucol[u];
  for (struct edge_t *i = e2[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs2(v, u);

    int ori[] = { dp[u][0], dp[u][1] };
    if (ucol[u])
      dp[u][1] = 1ll * ori[1] * (dp[v][0] + dp[v][1]) % MOD;
    else
    {
      dp[u][0] = 1ll * ori[0] * (dp[v][0] + dp[v][1]) % MOD;
      dp[u][1] = (1ll * ori[1] * (dp[v][0] + dp[v][1]) + 1ll * ori[0] * dp[v][1]) % MOD;
    }
  }

  eprintf("dp[%d] = { %d, %d }\n", u, dp[u][0], dp[u][1]);
}

int main()
{
  scanf("%d%d", &n, &k);
  for (int i=1; i<=n; ++i)
    scanf("%d", &col[i]);
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    eu[i] = u, ev[i] = v;
    add_edge(u, v);
  }
  dfs0(1, 0);

  memset(col2lca + 1, -1, sizeof(*col2lca) * (unsigned)n);
  for (int i=1; i<=n; ++i) if (col[i])
  {
    if (col2lca[col[i]] == -1) col2lca[col[i]] = i;
    else col2lca[col[i]] = lca(col2lca[col[i]], i);
  }

  for (int i=1; i<=n; ++i) if (col[i])
  {
    int u = i, c = col[i], b = col2lca[col[i]];
    eprintf("coloring: u = %d, b = %d\n", u, b);
    while (dep[u] >= dep[b])
    {
      if (ucol[u])
      {
        if (ucol[u] != c)
        {
          puts("0");
          return  0;
        }
        else break;
      }
      else
      {
        bel[u]  = b;
        ucol[u] = c;
        u = fa[u][0];
      }
    }
  }
  for (int i=1; i<=n; ++i) if (!bel[i])
    bel[i] = i;

  for (int i=1; i<=n; ++i)
    eprintf("bel[%d] = %d\n", i, bel[i]);

  for (int i=1; i<n; ++i)
    if (bel[eu[i]] != bel[ev[i]])
      add_edge2(bel[eu[i]], bel[ev[i]]);

  dfs2(1, 0);
  printf("%d\n", dp[1][1] % MOD);

  return 0;
}