#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define N 200005
#define B 20

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

struct wei_t
{
  int w, id;
};

int wei_cmp(const void *const _a, const void *const _b)
{
  return ((const struct wei_t*)_a)->w - ((const struct wei_t*)_b)->w;
}

struct wei_t ww[N];
int w[N], wcnt[N];
int n;

void disassociate_w()
{
  for (int i=1; i<=n; ++i)
    ww[i].w = w[i], ww[i].id = i;
  qsort(ww+1, n, sizeof(*ww), wei_cmp);
  ww[0].w = -1;
  int pos = -1;
  for (int i=1; i<=n; ++i)
  {
    pos += ww[i].w != ww[i-1].w;
    w[ww[i].id] = pos;
  }
}

int sub_sum[N], cnt[N];
int assign[N], assign_add[N];
void dfs0(int u, int f)
{
  sub_sum[u] -= cnt[w[u]];
  cnt[w[u]]++;
  int have_cnt = 0;
  for (struct edge_t *i = e[u]; i; i=i->next)
  {
    int v = i->v;
    if (v == f) continue;
    int pre_cnt = cnt[w[u]];
    dfs0(v, u); 
    int suf_cnt = cnt[w[u]];
    if (pre_cnt != suf_cnt)
      assign_add[v]--, have_cnt++;
  }
  if (have_cnt >= 2)
  {
    puts("0");
    exit(0);
  }
  sub_sum[u] += cnt[w[u]];

  if (sub_sum[u] != wcnt[w[u]])
    assign_add[u]++;
  if (sub_sum[u] != 1)
    assign_add[1]++;
}

void dfs1(int u, int f)
{
  assign[u] += assign_add[u];
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    assign_add[v] += assign_add[u];
    dfs1(v, u);
  }
}

int main() 
{
  scanf("%d", &n);
  for (int i=1; i<=n; ++i)
    scanf("%d", &w[i]);
  disassociate_w();
  for (int i=1; i<=n; ++i)
    wcnt[w[i]]++;

  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  dfs0(1, 0);
  dfs1(1, 0);

  int ans = 0;
  for (int i=1; i<=n; ++i) 
  {
    eprintf("assign[%d] = %d\n", i, assign[i]);
    ans += assign[i] == 0;
  }
  printf("%d\n", ans);
  return 0;
}