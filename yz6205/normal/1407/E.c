#include <stdio.h>

#define N 500005

struct edge_t
{
  struct edge_t *next;
  int v, w;
};

struct edge_t *e[N], e_pool[N], *ep_top = e_pool;

void add_edge(int u, int v, int w)
{
  ep_top->v    = v;
  ep_top->w    = w;
  ep_top->next = e[u];
  e[u] = ep_top++;
}

int n, m;

int col[N], dep[N];

void bfs()
{
  static int que[N];
  int *que_front=que, *que_back=que;
  *que_back++ = n;

  for (int i=1; i<=n; ++i)
    col[i] = dep[i] = -1;
  col[n] = dep[n] = 0;

  while (que_front != que_back)
  {
    int u = *que_front++; 
    for (struct edge_t *i = e[u]; i; i = i->next)
    {
      int v = i->v;
      if (col[v] == -1)
        col[v] = !i->w;
      else if (col[v] == i->w)
        if (dep[v] == -1)
        {
          dep[v] = dep[u] + 1;
          *que_back++ = v;
        }
    }
  }
}

int read()
{
  char pos = getchar();
  while (pos < '0' || pos > '9') pos = getchar();
  int res = pos - '0';
  pos = getchar();
  while (pos >= '0' && pos <= '9')
  {
    res = res * 10 + (pos - '0');
    pos = getchar();
  }
  return res;
}

int main() 
{
  n = read(), m = read();
  for (int i=0; i<m; ++i)
  {
    int u = read(), v = read(), w = read();
    add_edge(v, u, w);
  }

  bfs();
  for (int i=1 ;i<=n; ++i)
    if (col[i] == -1)
      col[i] = 0;

  printf("%d\n", dep[1]);
  for (int i=1; i<=n; ++i) 
    putchar(col[i] ? '1' : '0');
  puts("");

  return 0;
}