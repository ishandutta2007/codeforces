#include <stdio.h>

#define N 200005
#define M 500005

struct edge_t 
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[M], *ep_top=e_pool;

void add_edge(int u, int v)
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

int n;
int cnt[2];

void dfs(int u, int f, int col)
{
  cnt[col]++;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u, !col);
  }
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  scanf("%d", &n);
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  dfs(1,0,0);
  printf("%d\n", min(cnt[0], cnt[1]) - 1);
  return 0;
}