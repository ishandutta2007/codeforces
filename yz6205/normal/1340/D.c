#include <stdio.h>

#define N 100005

struct edge_t 
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[N * 2], *ep_top = e_pool;
int deg[N];

void add_edge(int u, int v)
{
  deg[u]++, deg[v]++;
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

int n;

struct ans_t
{
  int u, k;
};

struct ans_t make_ans(int u, int k)
{
  struct ans_t res = 
  {
    .u = u,
    .k = k
  };
  return res;
}

struct ans_t ans[N * 10], *ans_top = ans;

/**
 * starting on subtree u
 * begin with time p
 * end with time p-1
 */
void dfs(int u, int f, int p)
{
  const int goal = p - 1;
  *ans_top++ = make_ans(u, p);
  int sons = deg[u] - (f != -1);
  int rollback_cnt = p - 1;

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;

    if (sons <= rollback_cnt)
    {
      *ans_top++ = make_ans(u, rollback_cnt - sons);
      p = rollback_cnt - sons;
      rollback_cnt = -1;
    }
    sons--, p++;

    dfs(v, u, p);
    *ans_top++ = make_ans(u, p);
  }

  if (u != 1 && p != goal)
    *ans_top++ = make_ans(u, goal);
}
  
int main() 
{
  scanf("%d", &n);
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  dfs(1, -1, 0);

  printf("%ld\n", ans_top - ans);
  for (struct ans_t *i = ans; i < ans_top; ++i)
    printf("%d %d\n", i->u, i->k); 

  return 0;
}