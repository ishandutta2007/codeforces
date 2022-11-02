#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) 
#endif

#define N 2500005
#define M 3500005

struct edge_t
{
  struct edge_t *next;
  int v;
  bool vis;
};

struct edge_t *e[N], e_pool[M], *ep_top;
int ind[N];

void clear_graph()
{
  memset(e, 0, sizeof(e));
  memset(ind, 0, sizeof(ind));
  ep_top = e_pool;
}

void add_edge(int u, int v)
{
  eprintf("add_edge: %d %d\n", u, v);
  ind[u]++, ind[v]++;
  ep_top->v    = v;
  ep_top->vis  = false;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->vis  = false;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

struct edge_t *get_rev_edge(struct edge_t *p)
{
  return e_pool + ((long)(p - e_pool) ^ 1);
}

int a[N], b[N], n;

int stack[M], *stack_top;
void dfs(int u)
{
  for (struct edge_t **i = &e[u]; *i;)
  {
    if ((*i)->vis) 
      *i = (*i)->next;
    else
    {
      int v = (*i)->v;
      (*i)->vis = true;
      get_rev_edge(*i)->vis = true;
      (*i) = (*i)->next;
      dfs(v);
    }
  }
  *stack_top++ = u;
}

bool valid(int thr)
{
  eprintf("valid(%d)\n", thr);
  clear_graph();
  const int kp_offset = n * 2;
  const int thr_and = (1 << thr) - 1;
  for (int i=0; i<n; ++i)
  {
    add_edge(i*2,   i*2+1);
    add_edge(i*2,   kp_offset + (a[i] & thr_and));
    add_edge(i*2+1, kp_offset + (b[i] & thr_and));
  }
  for (int i=0; i <= n*2 + thr_and; ++i)
    if (ind[i] % 2 == 1)
    {
      eprintf("valid: %d(%d) %% 2 == 1\n", i, ind[i]);
      return  false;
    }
  stack_top = stack;
  dfs(0);
  if (stack_top - stack != n * 3 + 1)
    return false;
  return true;
}

void print(int u)
{
  if (u == 0) 
  {
    putchar('0');
    return;
  }
  static char buf[11], *const buf_end = buf + 10;
  char *buf_pos = buf_end;
  while (u)
  {
    *--buf_pos = '0' + u % 10;
    u /= 10;
  }
  fputs(buf_pos, stdout);
}

void output()
{
  static int stp[N];
  int *stp_back = stp;
  for (int *i = stack+1; i<stack_top; ++i)
    if (*i < 2 * n)
      *stp_back++ = *i;
  int *stp_front = stp;
  while ((*stp_front ^ 1) != *(stp_front+1))
    *stp_back++ = *stp_front++;
  for (int *i = stp_front; i<stp_back; ++i)
    print(*i+1), putchar(' ');
}

int main()
{
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
    scanf("%d%d", &a[i], &b[i]);

  int l=0, r=20;
  while (l < r)
  {
    int mid = (l + r + 1) / 2;
    if (valid(mid)) l = mid;
    else r = mid - 1;
  }

  assert(valid(l));
  print(l), puts("");
  output();

  return 0;
}