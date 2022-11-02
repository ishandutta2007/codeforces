#include <stdio.h>
#include <stdlib.h>

#define N 1005

struct edge_t 
{
  struct edge_t *next;
  int v, w;
};

struct edge_t *e[N], ep[N * 2], *ep_top = ep;
int deg[N];

void add_edge(int u, int v, int w)
{
  deg[u]++, deg[v]++;
  ep_top->v    = v;
  ep_top->w    = w;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->w    = w;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

struct edge_t *get_rev_edge(struct edge_t *p)
{
  return ep + ((p - ep) ^ 1);
}

int n, root;

int leaf[N], fa[N], fa_w[N];
void get_leaf(int u, int f)
{
  leaf[u] = u, fa[u] = f;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    fa_w[v] = i->w;
    get_leaf(v, u);
    leaf[u] = leaf[v];
  }
}

struct op_t
{
  int u, v, del;
};

struct op_t make_op(int u, int v, int del)
{
  struct op_t res = { u, v, del };
  return res;
}

struct op_t op[N * 10], *op_top = op;

void modify_fa(int u, int stop, int delta)
{
  if (u == stop) return;
  fa_w[u] += delta;
  modify_fa(fa[u], stop, delta);
}

void dfs(int u, int f)
{
  static int sons[N];
  int *sons_top = sons;
  for (struct edge_t *i = e[u]; i; i = i->next) if (i->v != f)
    *sons_top++ = i->v;

  if (sons_top - sons == 1 && fa_w[*sons] != 0)
  {
    puts("NO");
    exit(0);
  }
  for (int *i = sons; i + 1 < sons_top; ++i)
  {
    int a = *i, b = *(i + 1);
    int tot = (fa_w[a] + fa_w[b]) / 2;
    /* printf("a = %d, b = %d, fa_w[a] = %d, fa_w[b] = %d, tot = %d\n", a, b, fa_w[a], fa_w[b], tot); */
    *op_top++ = make_op(leaf[a], leaf[b], tot);
    modify_fa(leaf[a], u, -tot), modify_fa(leaf[b], u, -tot);
    /* printf("a = %d, b = %d, fa_w[a] = %d, fa_w[b] = %d, tot = %d\n", a, b, fa_w[a], fa_w[b], tot); */
    *op_top++ = make_op(leaf[a], root, fa_w[a]), modify_fa(leaf[a], root, -fa_w[a]);
    *op_top++ = make_op(leaf[b], root, fa_w[b]), modify_fa(leaf[b], root, -fa_w[b]);
  }

  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != f) dfs(i->v, u);
}

int main()
{
  scanf("%d", &n);
  for (int i=1; i<n; ++i)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, w);
  }

  for (int i=1; i<=n; ++i)
    if (deg[i] == 1)
      root = i;
  get_leaf(root, -1);
  *op_top++ = make_op(root, leaf[root], fa_w[e[root]->v]);
  modify_fa(leaf[root], root, -fa_w[e[root]->v]);
  dfs(root, -1);

  puts("YES");
  printf("%ld\n", op_top - op);
  for (struct op_t *i = op; i < op_top; ++i)
    printf("%d %d %d\n", i->u, i->v, i->del);

  return 0;
}