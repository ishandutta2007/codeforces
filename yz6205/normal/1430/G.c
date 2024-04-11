#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define int long long
#define N 400
#define M (N * N)
#define inf ((int)1e14)

struct edge_t
{
  struct edge_t *next;
  int v, c;
};

struct edge_t e_pool[M], *ep_top = e_pool;
int dep[N], s, t, n, m, un;

struct edge_t *find_rev_edge(struct edge_t *p)
{
  return e_pool + ((long)(p - e_pool) ^ 1l);
}

struct edge_t *e[N], *e_first[N];

void add_edge(int u, int v, int w)
{
  // printf("add_edge %lld -> %lld : %lld\n", u,v,w);
  ep_top->next = e[u];
  ep_top->v    = v;
  ep_top->c    = w;
  e[u]         = ep_top++;
  ep_top->next = e[v];
  ep_top->v    = u;
  ep_top->c    = 0;
  e[v]         = ep_top++;
}

bool bfs()
{
  memset(dep, -1, sizeof(*dep) * un); dep[s] = 0;
  static int que[N];
  int *que_front = que, *que_back = que;
  *que_back++ = s;
  while (que_front != que_back)
  {
    assert(que_back - que < N);
    int u = *que_front++;
    for (struct edge_t *i = e[u]; i; i = i->next)
      if (i->c && dep[i->v] == -1)
      {
        dep[i->v] = dep[u] + 1;
        *que_back++ = i->v;
      }
  }
  return dep[t] != -1;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int dfs(int u, int limit)
{
  if (u == t) return limit; 
  if (limit == 0) return 0;
  int remain = limit;
  for (struct edge_t **i = &e_first[u]; *i; *i = (*i)->next)
    if ((*i)->c && dep[(*i)->v] == dep[u] + 1)
    {
      int v_limit = min(remain, (*i)->c);
      int cur = dfs((*i)->v, v_limit);
      remain -= cur;
      (*i)->c -= cur;
      find_rev_edge(*i)->c += cur;
    }
  return limit - remain;
}

void dinic()
{
  while (bfs())
  {
    memcpy(e_first, e, sizeof(*e) * un);
    while (dfs(s, inf));
  }
}

int u[N], v[N], w[N], uw[N], ans[N];

signed main()
{
  scanf("%lld%lld", &n, &m);
  s = n * (n+1), t = s + 1, un = t + 1;
  for (int i=0; i<m; ++i)
  {
    scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
    u[i]--, v[i]--;
    uw[u[i]] += w[i];
    uw[v[i]] -= w[i];
  }
  
  for (int i=0; i<n; ++i)
  {
    int ul = (n+1) * i, ur = (n+1) * (i+1);
    add_edge(s, ul, inf);
    for (int j=ul; j+1<ur; ++j)
      add_edge(j, j+1, uw[i] * (j%(n+1)) + (int)1e11);
    add_edge(ur-1, t, inf);
  }

  for (int i=0; i<m; ++i)
    for (int ui = (n+1) * v[i], vi = (n+1) * u[i] + 1; 
        vi < (n+1) * (u[i]+1); ui++, vi++)
      add_edge(ui, vi, inf);

  dinic();
  for (int i=0; i<un-2; ++i)
    if (dep[i] != -1)
      ans[i / (n+1)] = i % (n+1);
  for (int i=0; i<n; ++i)
    printf("%lld%c", ans[i], " \n"[i==n-1]);

  return 0;
}