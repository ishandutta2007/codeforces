#include <stdio.h>
#include <stdint.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) 
#endif

#define int long long
#define N 300005
#define B 20

int min(int a, int b)
{
  return a < b ? a : b;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b, *b = tmp;
}

int ewl[N], n;

struct edge_t
{
  struct edge_t *next;
  int v, w0, w1;
};

struct edge_t *e[N], ep[N * 2], *ep_top = ep;

void add_edge(int u, int v, int w0, int w1)
{
  ep_top->v    = v;
  ep_top->w0   = w0;
  ep_top->w1   = w1;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->w0   = w0;
  ep_top->w1   = w1;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

void init_ewl_0(int u, int f)
{
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    init_ewl_0(v, u);
    int v_ewl = i->w0 + i->w1 + ewl[v];
    if (ewl[u] > v_ewl)
      ewl[u] = v_ewl;
  }
}

void init_ewl_1(int u, int f)
{
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    int u_ewl = i->w0 + i->w1 + ewl[u];
    eprintf("%lld -> %lld u_ewl = %lld, ewl[v] = %lld\n", u, v, u_ewl, ewl[v]);
    if (ewl[v] > u_ewl)
      ewl[v] = u_ewl;
    init_ewl_1(v, u);
  }
}

struct dis_t
{
  int w[2][2];
};

struct dis_t pdis[N][B];

struct dis_t make_dis(int w0, int w1, int cu, int cv)
{
  struct dis_t res = 
  {
    .w = 
    {
      {
        min(w0, w1 + cu + cv),
        min(w0 + cv, cu + w1),
      },
      {
        min(cu + w0, w1 + cv),
        min(w1, w0 + cu + cv),
      },
    }
  };
  return res;
}

int fa[N][B];
int dep[N];

void dfs(int u, int f)
{
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  for (int i=0; i+1<B; ++i)
    fa[u][i + 1] = fa[ fa[u][i] ][i];
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u);
    pdis[v][0] = make_dis(i->w0, i->w1, ewl[v], ewl[u]);
  }
}

struct dis_t merge(const struct dis_t *a, const struct dis_t *b)
{
  struct dis_t res = 
  {
    .w = 
    {
      {
        min(a->w[0][0] + b->w[0][0], a->w[0][1] + b->w[1][0]),
        min(a->w[0][0] + b->w[0][1], a->w[0][1] + b->w[1][1]),
      },
      {
        min(a->w[1][0] + b->w[0][0], a->w[1][1] + b->w[1][0]),
        min(a->w[1][0] + b->w[0][1], a->w[1][1] + b->w[1][1]),
      },
    }
  };
  return res;
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

struct dis_t get_pdis(int u, int dep)
{
  struct dis_t res = { { {0, ewl[u]}, {ewl[u], 0} } };
  for (int i = 0; i < B; ++i)
    if (dep & (1 << i))
    {
      res = merge(&res, &pdis[u][i]);
      u = fa[u][i];
    }
  return res;
}

int32_t main()
{
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &ewl[i]);
  for (int i = 1; i < n; ++i)
  {
    int u, v, w0, w1;
    scanf("%lld%lld%lld%lld ", &u, &v, &w0, &w1);
    add_edge(u, v, w0, w1);
  }

  init_ewl_0(1, 0);
  init_ewl_1(1, 0);
  
  dfs(1, 0);
  for (int b = 0; b+1 < B; ++b)
    for (int u = 1; u <= n; ++u)
      if (fa[u][b] && fa[fa[u][b]][b])
        pdis[u][b + 1] = merge(&pdis[u][b], &pdis[fa[u][b]][b]);

  int q;
  scanf("%lld", &q);
  for (int i=0; i<q; ++i)
  {
    int u, v;
    scanf("%lld%lld", &u, &v);
    u++, v++;
    int uu = u % 2, vv = v % 2;
    u /= 2, v /= 2;

    int l = lca(u, v);
    eprintf("query: u,v = %lld,%lld   uu,vv = %lld,%lld   l = %lld\n", u, v, uu, vv, l);
    struct dis_t udis = get_pdis(u, dep[u] - dep[l]);
    struct dis_t vdis = get_pdis(v, dep[v] - dep[l]);
    swap(&vdis.w[0][1], &vdis.w[1][0]);
    /* eprintf("udis = { { %lld, %lld }, { %lld, %lld } } \n", udis.w[0][0], udis.w[0][1], udis.w[1][0], udis.w[1][1]); */
    /* eprintf("vdis = { { %lld, %lld }, { %lld, %lld } } \n", vdis.w[0][0], vdis.w[0][1], vdis.w[1][0], vdis.w[1][1]); */
    struct dis_t res  = merge(&udis, &vdis);
    /* eprintf("res = { { %lld, %lld }, { %lld, %lld } } \n", res.w[0][0], res.w[0][1], res.w[1][0], res.w[1][1]); */
    printf("%lld\n", res.w[uu][vv]);
  }

  return 0;
}