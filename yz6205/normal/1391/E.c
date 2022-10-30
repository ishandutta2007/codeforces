#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define N 500005
#define M 2000005

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

void clear_graph(int n)
{
  for (int i=1; i<=n; ++i)
    e[i] = NULL;
  ep_top = e_pool;
}

int n, m;

int dep[N];
int d2id[N], pr_ans[N][2], (*pr_ans_top)[2];
int trace[N], *trace_top;
bool dfs(int u)
{
  eprintf("dfs(%d): dep = %d\n", u, dep[u]);

  *trace_top++ = u;
  if (dep[u] * 2 >= n)
  {
    eprintf("%d\n", dep[u]);
    puts("PATH");
    printf("%ld\n", trace_top - trace);
    for (int *i=trace; i<trace_top; ++i)
      printf("%d ", *i);
    puts("");
    return true;
  }

  if (d2id[dep[u]] == -1) 
    d2id[dep[u]] = u;
  else
  {
    (*pr_ans_top)[0] = d2id[dep[u]];
    (*pr_ans_top)[1] = u;
    pr_ans_top++;
    d2id[dep[u]] = -1;
  }

  bool res = false;

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (dep[v] == -1)
    {
      dep[v] = dep[u] + 1;
      if (dfs(v)) 
      {
        res = true;
        break;
      }
    }
  }
  
  trace_top--;
  return res;
}

void rmain()
{
  n = read(), m = read();
  clear_graph(n);
  for (int i=0; i<m; ++i)
    add_edge(read(), read());
  
  memset(dep, -1, sizeof(*dep) * (n+1)), dep[1] = 1;
  memset(d2id, -1, sizeof(*d2id) * (n+1)), pr_ans_top = &pr_ans[0];
  trace_top = trace; 

  if (!dfs(1))
  {
    puts("PAIRING");
    printf("%ld\n", pr_ans_top - pr_ans);
    for (int (*i)[2] = &pr_ans[0]; i < pr_ans_top; ++i)
      printf("%d %d\n", (*i)[0], (*i)[1]);
  }
}

int main()
{
  int T = read();
  for (int i=0; i<T; ++i)
    rmain();
  return 0;
}