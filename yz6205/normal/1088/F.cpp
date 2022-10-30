#include <stdio.h>

#define B 20
#define N 500005
int val[N];

struct edge_t 
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], ep[N * 2], *ep_top = ep;

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

int fa[N][B];
void dfs(int u, int f)
{
  fa[u][0] = f;
  for (int i=0; i+1<B; ++i)
    fa[u][i + 1] = fa[fa[u][i]][i];
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u);
  }
}

int main()
{
  scanf("%d", &n);
  for (int i=1; i<=n; ++i) scanf("%d", &val[i]);
  for (int i=1; i<n; ++i) 
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  int root = 1, root_val = val[1];
  for (int i=1; i<=n; ++i)
    if (val[i] < root_val)
      root_val = val[i], root = i;
  dfs(root, root);

  long long ans = 0;
  for (int i=1; i<=n; ++i) if (i != root)
  {
    long long this_ans = 0x3f3f3f3f3f3f3f3f;
    for (int b = 0; b < B; b++)
    {
      long long cur = 1ll * (b+1) * val[fa[i][b]] + val[i];
      if (this_ans > cur)
        this_ans = cur;
    }
    ans += this_ans;
  }

  printf("%lld\n", ans);

  return 0;
}