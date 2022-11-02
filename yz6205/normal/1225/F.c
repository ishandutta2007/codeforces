#include <stdio.h>

#define N 100005

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], ep[N], *ep_top = ep;

void add_edge(int u, int v) 
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
}

int fa[N], dep[N], len[N], son[N], n;
int dfn[N], dfn_top;

void dfs(int u)
{
  dfn[dfn_top++] = u;
  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != son[u]) dfs(i->v);
  if (son[u]) dfs(son[u]);
}

int main()
{
  scanf("%d", &n);
  for (int i=1; i<n; ++i)
    scanf("%d", &fa[i]), add_edge(fa[i], i);

  for (int i=1; i<n; ++i)
    dep[i] = dep[fa[i]] + 1;

  for (int i=n-1; i>=1; i--)
    if (len[fa[i]] < len[i] + 1)
      len[fa[i]] = len[i] + 1, son[fa[i]] = i;

  dfs(0);

  for (int i=0; i<n; ++i)
    printf("%d%c", dfn[i], " \n"[i==n-1]);

  int ans_len = 0;
  for (int i=1; i<n; ++i)
    ans_len += dep[dfn[i-1]] - dep[fa[dfn[i]]];
  printf("%d\n", ans_len);
  for (int i=1; i<n; ++i)
    for (int j=0; j<dep[dfn[i-1]] - dep[fa[dfn[i]]]; ++j)
      printf("%d ", dfn[i]);

  return 0;
}