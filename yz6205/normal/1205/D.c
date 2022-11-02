#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#ifdef __LOCALE__
#define eprintf(...) do { printf(__VA_ARGS__); fflush(stdout); } while (false)
#else
#define eprintf(...)
#endif

#define N 10005

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

int u[N], v[N];
int n;

int size[N], root;
void get_root(int u, int f)
{
  int val = 0;
  size[u] = 1;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    get_root(v, u);
    size[u] += size[v];
    if (size[v] > val) val = size[v];
  }
  if (n - size[u] > val) val = n - size[u];
  eprintf("get_root(%d), val = %d\n", u, val);
  if (val * 2 <= n && !root) root = u;
}

struct ss_t
{
  int val, id;
  bool choose;
};

struct ss_t ss[N], *ss_top = ss;

int ss_cmp(const void *a, const void *b)
{
  return ((const struct ss_t*)b)->val - ((const struct ss_t*)a)->val;
}

int val[N];
void assign(int u, int f, int cur, int step)
{
  val[u] = cur, cur += step;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    assign(v, u, cur, step);
    cur += step * size[v];
  }
}

int main()
{
  scanf("%d", &n);
  for (int i=1; i<n; ++i)
  {
    scanf("%d%d", &u[i], &v[i]);
    add_edge(u[i], v[i]);
  }

  if (n == 1) return 0;
  if (n == 2)
  {
    puts("1 2 1");
    return 0;
  }

  get_root(1, 0);
  get_root(root, 0);
  eprintf("root = %d\n", root);

  for (struct edge_t *i = e[root]; i; i = i->next)
  {
    ss_top->val = size[i->v];
    ss_top->id  = i->v;
    ss_top++;
  }

  qsort(ss, (size_t)(ss_top - ss), sizeof(*ss), ss_cmp);

  int cur_size = 1, thr = (n + 1) / 2;
  for (struct ss_t *i = ss; i < ss_top; ++i)
  {
    eprintf("size[%d] = %d\n", i->id, i->val);
    if (cur_size + i->val <= thr)
      cur_size += i->val, i->choose = true;
  }

  int oth_size = n - cur_size;
  eprintf("cur_size = %d, oth_size = %d\n", cur_size, oth_size);
  /* assert(oth_size * cur_size >= n * n * 2 / 9); */

  val[root] = 0;
  int a_cur = oth_size + 1, a_step = oth_size + 1;
  int b_cur = 1, b_step = 1;
  for (struct ss_t *i = ss; i < ss_top; ++i)
  {
    if (i->choose)
      assign(i->id, root, a_cur, a_step), a_cur += size[i->id] * a_step;
    else
      assign(i->id, root, b_cur, b_step), b_cur += size[i->id] * b_step;
  }

  for (int i=1; i<n; ++i) 
  {
    int ans = val[u[i]] - val[v[i]];
    if (ans < 0) ans = -ans;
    printf("%d %d %d\n", u[i], v[i], ans);
  }

  return 0;
}