#include <stdio.h>
#include <stdbool.h>

#define N 150005

int n, tot_size;

struct edge_t
{
  struct edge_t *next;
  int v;
};

int deg[N];
struct edge_t *e[N], ep[N * 2], *ep_top = ep;

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

int size[N];
void get_size(int u, int f)
{
  size[u] = 1;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    get_size(v, u);
    size[u] += size[v];
  }
}

int root0, root1;
void get_root(int u, int f)
{
  int val = tot_size - size[u];
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    get_root(v, u);
    if (size[v] > val) val = size[v];
  }
  if (val * 2 <= tot_size)
    root0 ? (root1 = u) : (root0 = u);
}

bool is_binary(int u, int f)
{
  if (size[u] == 1) return true;
  if (deg[u] != 3) return false;
  int s1 = 0, s2 = 0;
  for (struct edge_t *i=e[u]; i; i=i->next)
    if (i->v != f) s1 ? (s2=i->v) : (s1=i->v);
  return size[s1] == size[s2] && is_binary(s1, u) && is_binary(s2, u);
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b, *b = tmp;
}

int spl_id;
bool is_del(int u, int f)
{
  if (size[u] == 1) return false;
  if (size[u] == 2) 
  {
    spl_id = u;
    return true;
  }

  int sons = deg[u] - (f != -1);
  if (sons < 2 || sons > 3) return false;

  int son[3], *son_top = son;
  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != f) *son_top++ = i->v;
  /* printf("is_del(%d): sons = %d\n", u, sons); */

  if (sons == 3)
  {
    spl_id = u;
    /* printf("is_del(%d): spl_id = %d\n", u, spl_id); */
    return is_binary(son[0], u) && is_binary(son[1], u) && is_binary(son[2], u);
  }

  if (size[son[0]] < size[son[1]]) swap(&son[0], &son[1]);
  return size[son[0]] - size[son[1]] == 1 && is_binary(son[0], u) && is_del(son[1], u);

  return true;
}

int ans[2], *ans_top = ans;

bool check(int u)
{
  get_size(u, -1);
  return is_del(u, -1);
}

int main()
{
  scanf("%d", &n);
  tot_size = (1 << n) - 2;
  for (int i=1; i<tot_size; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  get_size(1, -1);
  get_root(1, -1);
  if (root0 && check(root0)) *ans_top++ = spl_id;
  if (root1 && check(root1)) *ans_top++ = spl_id;

  printf("%ld\n", ans_top - ans);
  if (ans_top - ans == 2 && ans[0] > ans[1]) swap(&ans[0], &ans[1]);
  for (int *i = ans; i < ans_top; ++i)
    printf("%d ", *i);
  
  return 0;
}