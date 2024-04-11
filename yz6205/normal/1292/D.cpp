#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define long long long
#define N 5005

bool isp[N];

void init_prime()
{
  isp[1] = false;
  memset(isp, 1, sizeof(isp));
  for (int i=2; i<N; ++i)
  {
    if (!isp[i]) continue;
    for (int j=i*i; j<N; j+=i)
      isp[j] = false;
  }
}

int series_pool[38110288];
int *series[N];

int get_pow_cnt(int n, int k)
{
  int res = 0;
  while (n >= k)
  {
    res += n / k;
    n /= k;
  }
  return res;
}

void init_series() 
{
  int *series_top = series_pool;
  series[0] = series[1] = series_top;
  for (int i=2; i<N; ++i)
  {
    series[i] = series_top;
    for (int j=i; j>=2; --j) if (isp[j])
    {
      int cnt = get_pow_cnt(i, j);
      for (int k=0; k<cnt; ++k)
        *series_top++ = j;
    }
  }
  // printf("%ld\n", series_top - series_pool);
}

int common[N][N];

int get_common(int *a, int *b, size_t len)
{
  for (size_t i=0; i<len; ++i)
    if (a[i] != b[i])
      return i;
  return len;
}

void init_common()
{
  for (int i=0; i<N-2; ++i)
    for (int j=i; j<N-2; ++j)
      common[i][j] = common[j][i] = 
        get_common(series[i], series[j], series[i+1] - series[i]);
}

struct edge_t
{
  struct edge_t *next;
  int v, w;
};

struct edge_t *e[N * 2], e_pool[N * 2], *ep_top = e_pool;

struct node_t
{
  int pos, len;
  int node_id;
};

struct node_t make_node(int pos, int len, int node_id)
{
  struct node_t res = 
  {
    .pos     = pos,
    .len     = len,
    .node_id = node_id
  };
  return res;
};

void add_edge(struct node_t *v, struct node_t *u)
{
  eprintf("add edge: %d -> %d : %d\n", u->node_id, v->node_id, v->len - u->len);
  ep_top->v    = v->node_id;
  ep_top->w    = v->len - u->len;
  ep_top->next = e[u->node_id];
  e[u->node_id] = ep_top++;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int lca_len(struct node_t a, struct node_t b)
{
  return min( min(a.len, b.len), common[a.pos][b.pos] );
}

struct node_t stack[N], *stack_top = stack;
int node_id_top = 0;
int n, cnt[N];
long wcnt[N * 2], wtot[N * 2], ans[N * 2];

void dfs0(int u)
{
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    dfs0(v);
    wcnt[u] += wcnt[v];
    wtot[u] += wtot[v] + wcnt[v] * i->w;
  }
}

void dfs1(int u, long fcnt, long ftot)
{
  ans[u] = wtot[u] + ftot;
  /* eprintf("dfs1: ans[%d] = %lld, fcnt=%lld, ftot=%lld\n", u, ans[u], fcnt, ftot); */
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    long vcnt = fcnt + wcnt[u] - wcnt[v];
    long vtot = ans[u] - wtot[v] - i->w * wcnt[v] + vcnt * i->w;
    dfs1(v, vcnt, vtot);
  }
}

int main()
{
  init_prime();
  init_series();
  init_common();
  
  scanf("%d", &n);
  for (int i=0; i<n; ++i) 
  {
    int a;
    scanf("%d", &a);
    if (a == 0) a = 1;
    cnt[a]++;
  }

  const int root = 0;

  for (int i=1; i<=5000; ++i)
  {
    struct node_t pos = make_node(i, series[i+1] - series[i], node_id_top++);
    wcnt[pos.node_id] = cnt[i];
    /* eprintf("adding pos = {%d, %d}\n", pos.pos, pos.len); */

    while (stack_top - stack >= 2l)
    {
      int lf = lca_len(*(stack_top - 1), pos);
      int la = lca_len(*(stack_top - 2), pos);

      if (lf == (stack_top - 1)->len) 
        break;
      else if (lf == la) 
      {
        add_edge(stack_top - 1, stack_top - 2);
        stack_top--;
      }
      else
      {
        struct node_t lf_node = make_node(i, lf, node_id_top++);
        add_edge(stack_top - 1, &lf_node);
        stack_top--, *stack_top++ = lf_node;
        break;
      }
    }
    *stack_top++ = pos;
  }
  while (stack_top - stack >= 2l)
  {
    add_edge(stack_top - 1, stack_top - 2);
    stack_top--;
  }

  dfs0(root);
  dfs1(root, 0, 0);

  long res = ans[root];
  for (int i = root + 1; i < node_id_top; ++i)
    if (ans[i] < res) res = ans[i];

  printf("%lld\n", res);

  return 0;
}