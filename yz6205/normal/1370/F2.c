#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define N 1005
#define M 2005

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[M], *ep_top=e_pool;

void clear_graph()
{
  memset(e, 0, sizeof(e));
  ep_top = e_pool;
}

void add_edge(int u, int v)
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

int dep[N];
int n, root, len, deeper;

void get_root()
{
  printf("? %d", n);
  for (int i=1; i<=n; ++i) 
    printf(" %d", i);
  puts("");
  fflush(stdout);
  int x, d;
  scanf("%d%d", &x, &d);
  root = x, len = d;
}

void dfs(int u, int f)
{
  dep[u] = dep[f] + 1;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs(v, u);
  }
}

bool query_depth(int depth)
{
  static int pos_set[N];
  int *pos_set_top = pos_set;
  for (int i=1; i<=n; ++i)
    if (dep[i] == depth)
      *pos_set_top++ = i;
  if (pos_set_top == pos_set)
    return false;
  printf("? %ld", pos_set_top - pos_set);
  for (int *i = pos_set; i < pos_set_top; ++i)
    printf(" %d", *i);
  puts("");
  fflush(stdout);

  int x, d;
  scanf("%d%d", &x, &d);
  return d == len ? deeper=x, true : false;
}

void get_deeper()
{
  int l = len / 2, r = len;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    eprintf("(%d, %d) -> %d\n", l, r, mid);
    if (query_depth(mid)) l = mid + 1;
    else r = mid - 1;
  }
}

int final_q[N], *final_q_top;

void dfs2(int u, int f, int dep)
{
  if (dep == len)
  {
    *final_q_top++ = u; 
    return;
  }
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs2(v, u, dep + 1);
  }
}

int get_final()
{
  final_q_top = final_q;
  dfs2(deeper, 0, 0);
  printf("? %ld", final_q_top - final_q);
  for (int *i = final_q; i < final_q_top; ++i)
    printf(" %d", *i);
  puts("");
  fflush(stdout);
  int x, d;
  scanf("%d%d", &x, &d);
  return x;
}

char trash[20];

void rmain()
{
  clear_graph();
  scanf("%d", &n);
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  get_root();
  dep[0] = -1;
  dfs(root, 0);
  get_deeper();
  int other = get_final();
  printf("! %d %d\n", deeper, other);
  fflush(stdout);
  scanf("%s", trash); 
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) rmain();
  return 0;
}