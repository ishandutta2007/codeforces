#include <stdio.h>
#include <stdlib.h>

#ifdef  __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) 
#endif

#define N 1505
#define MOD 998244353

int d[N][N], n, m;

struct edge_t
{
  int u, v, w;
};

struct edge_t make_edge(const int u, const int v, const int w) 
{
  struct edge_t res = 
  {
    .u = u,
    .v = v,
    .w = w
  };
  return res;
} 

struct edge_t es[N * N], *es_top = es;

int edge_cmp(const void *const a, const void *const b)
{
  return ((const struct edge_t*)a)->w  - ((const struct edge_t*)b)->w;
}

int sons[N * 2][2];

int p[N * 2], ecnt[N * 2];
int get(int u)
{
  return u==p[u] ? u : (p[u] = get(p[u]));
}

void build_tree() 
{
  for (int i=1; i<=n*2; ++i) p[i] = i;

  int par_id = n;
  for (int i=0; i<m; ++i)
  {
    int u = es[i].u, v = es[i].v;
    int pu = get(u), pv = get(v); 
    if (pu != pv)
    {
      eprintf("%d -> %d, %d -> %d\n", par_id, pu, par_id, pv);
      sons[par_id][0] = pu;
      sons[par_id][1] = pv;
      p[pu] = par_id;
      p[pv] = par_id;
      ecnt[par_id] = ecnt[pu] + ecnt[pv] + 1;
      par_id++;
    }
    else
    {
      ecnt[pu]++;
    }
  }
}

int dfn_top;
int dp[N][N];
void dfs(int u)
{
  eprintf("dfs(%d)\n", u);

  int dl = dfn_top;
  if (u < n) dfn_top++;
  else dfs(sons[u][0]), dfs(sons[u][1]);
  int dr = dfn_top;
  int size = dr - dl;

  if (ecnt[u] == size * (size-1) / 2)
  {
    eprintf("dfs(%d): add interval [%d, %d)\n", u, dl, dr);
    for (int i=0; i<n; ++i)
    {
      dp[dr][i+1] += dp[dl][i];
      if (dp[dr][i+1] >= MOD) dp[dr][i+1] -= MOD;
    }
  }
}

int main() 
{
  scanf("%d", &n);
  for (int i=0; i<n; ++i) 
    for (int j=0; j<n; ++j) 
      scanf("%d", &d[i][j]);
  
  for (int i=0; i<n; ++i)
    for (int j=i+1; j<n; ++j) 
      *es_top++ = make_edge(i, j, d[i][j]);
  m = es_top - es;
  qsort(es, m, sizeof(*es), edge_cmp);

  build_tree();
  dp[0][0] = 1;
  dfs(2 * n - 2);
  for (int i=1; i<=n; ++i)
    printf("%d%c", dp[n][i], " \n"[i==n]);

  return 0;
}