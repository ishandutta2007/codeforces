#include <stdio.h>

#define N 200005
#define M 500005

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[M], *ep_top;
int n, m;

void clear_graph()
{
  for (int i=1; i<=n; ++i) 
    e[i] = NULL;
  ep_top = e_pool;
}

void add_edge(int u, int v)
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
}

enum color_t
{
  color_a, 
  color_b,  
  color_c
};

enum color_t col[N];

void rmain()
{
  scanf("%d%d", &n, &m);
  clear_graph();
  for (int i=0; i<m; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(v, u);
  }

  col[1] = color_a;
  for (int u=2; u<=n; ++u)
  {
    col[u] = color_a;
    for (struct edge_t *i = e[u]; i; i = i->next)
    {
      if (col[i->v] == color_b)
        col[u] = color_c;
      if (col[u] != color_c && col[i->v] == color_a)
        col[u] = color_b;
    }
  }
  int cnt = 0;
  for (int i=1; i<=n; ++i)
    if (col[i] == color_c)
      cnt++;
  printf("%d\n", cnt);
  for (int i=1; i<=n; ++i)
    if (col[i] == color_c)
      printf("%d ", i);
  puts("");
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
    rmain();
  return 0;
}