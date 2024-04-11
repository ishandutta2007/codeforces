#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define N 500005

struct cedge_t
{
  int u, v, ca, cb;
};

struct cedge_t make_cedge(int u, int v);

struct edge_t
{
  struct edge_t *next;
  int v;
};

void edge_init(struct edge_t *t)
{
  t->next = NULL;
}

struct graph_t
{
  int used[N * 6], *used_top;
  struct edge_t *e[N * 2], ep[N * 6], *ep_top;
  int uid[N * 2], uid_cnt;
};

void graph_init(struct graph_t *t)
{
  t->used_top = t->used, t->ep_top = t->ep;
  for (int i=0; i<N; ++i) 
  {
    t->e[i] = NULL;
    t->uid[i] = 0;
  }
  t->uid_cnt = 2;
}

void graph_addedge(struct graph_t *t, int u, int v)
{
  eprintf("graph_addedge: %d -> %d\n", u, v);
  *t->used_top++  = u, *t->used_top++ = v;
  edge_init(t->ep_top);
  t->ep_top->v    = v;
  t->ep_top->next = t->e[u];
  t->e[u]         = t->ep_top++;
  edge_init(t->ep_top);
  t->ep_top->v    = u;
  t->ep_top->next = t->e[v];
  t->e[v]         = t->ep_top++;
}

void graph_clear(struct graph_t *t)
{
  while (t->used_top != t->used)
  {
    t->used_top--;
    t->e[*t->used_top] = NULL;
    t->uid[*t->used_top] = 0;
  }
  t->ep_top = t->ep;
}

struct graph_t g, t;
struct cedge_t ce[N];
int color[N], n, m, k;
int ans[N];

struct cedge_t make_cedge(int u, int v)
{
  struct cedge_t res = {
    .u  = u,
    .v  = v,
    .ca = color[u],
    .cb = color[v]
  };
  if (res.ca > res.cb)
  {
    int t = res.ca;
    res.ca = res.cb;
    res.cb = t;
  }
  return res;
}

void dfs_sc(struct graph_t *g, int u)
{
  eprintf("dfs_sc(%d)\n", u);
  for (struct edge_t *i = g->e[u]; i; i = i->next)
  {
    int v = i->v;
    if (color[v] != color[u]) continue;
    if (g->uid[u] == g->uid[v]) 
    {
      ans[color[u]] = 0;
      return;
    } 
    else if (g->uid[v] == 0)
    {
      g->uid[v] = g->uid[u] ^ 1;
      dfs_sc(g, v);
    }
  }
}

bool valid_state;
void dfs_valid(struct graph_t *g, int u)
{
  for (struct edge_t *i = g->e[u]; i; i = i->next)
  {
    int v = i->v;
    if (g->uid[u] == g->uid[v])
    {
      valid_state = false;
      return;
    }
    else if (g->uid[v] == 0)
    {
      g->uid[v] = g->uid[u] ^ 1;
      dfs_valid(g, v);
    }
  }
}

void graph_dfs(struct graph_t *g, void (*dfs)(struct graph_t*, int))
{
  for (int *i = g->used; i < g->used_top; ++i) if (g->uid[*i] == 0)
  {
    g->uid[*i] = g->uid_cnt;
    g->uid_cnt += 2;
    dfs(g, *i);
  }
}

int same_edge_cmp(const void *_a, const void *_b)
{
  const struct cedge_t *a = (const struct cedge_t*)_a;
  const struct cedge_t *b = (const struct cedge_t*)_b;
  if (a->ca == b->ca)
    return a->cb - b->cb;
  return a->ca - b->ca;
}

int main(void)
{
  graph_init(&g), graph_init(&t);

  scanf("%d%d%d", &n, &m, &k);
  for (int i=1; i<=n; ++i) 
    scanf("%d", &color[i]);
  for (int i=0; i<m; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    graph_addedge(&g, u, v);
    ce[i] = make_cedge(u,v);
  }

  for (int i=1; i<=k; ++i) ans[i] = k - 1;
  graph_dfs(&g, &dfs_sc);  
  int ok_color_cnt = 0;
  for (int i=1; i<=k; ++i) ok_color_cnt += ans[i] != 0;
  for (int i=1; i<=k; ++i) if (ans[i]) ans[i] = ok_color_cnt-1;

  for (int i=1; i<=n; ++i)
    eprintf("uid[%d] = %d\n", i, g.uid[i]);

  qsort(ce, m, sizeof(*ce), same_edge_cmp);

  int r;
  for (int i=0; i<m; i=r)
  {
    r = i;
    while (r < m && ce[i].ca == ce[r].ca && ce[i].cb == ce[r].cb) r++;

    if (ans[ce[i].ca] == 0 || ans[ce[i].cb] == 0)
      continue;
    if (ce[i].ca == ce[i].cb) 
      continue;

    graph_clear(&t);
    eprintf("starting color %d %d\n", ce[i].ca, ce[i].cb);
    for (int j=i; j<r; ++j)
    {
      eprintf("adding %d -> %d\n", ce[j].u, ce[j].v);
      int uid_u = g.uid[ce[j].u];
      int uid_v = g.uid[ce[j].v];
      graph_addedge(&t, uid_u, uid_u ^ 1);
      graph_addedge(&t, uid_v, uid_v ^ 1);
      graph_addedge(&t, uid_u, uid_v);
    }

    valid_state = true;
    graph_dfs(&t, &dfs_valid);
    if (!valid_state)
      ans[ce[i].ca]--, ans[ce[i].cb]--;
  }

  for (int i=1; i<=k; ++i)
    eprintf("ans[%d] = %d\n", i, ans[i]);

  long long tot_ans = 0;
  for (int i=1; i<=k; ++i)
    tot_ans += ans[i];
  tot_ans /= 2;
  printf("%lld\n", tot_ans);

  return 0;
}