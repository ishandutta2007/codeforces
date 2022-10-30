#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define N 200005

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t *e[N], e_pool[N * 2], *ep_top = e_pool;

void add_edge(int u, int v) 
{
  ep_top->v    = v;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

int dist[N], ans[N];
int n, m;

void bfs()
{
  static int que[N];
  int *que_front=que, *que_back=que_front;
  for (int i=1; i<=n; ++i) 
    if (dist[i] == 0)
      *que_back++ = i;
  while (que_front != que_back)
  {
    int u = *que_front++;
    for (struct edge_t *i = e[u]; i; i = i->next)
    {
      int v = i->v;
      if (dist[v] > dist[u] + 1)
      {
        dist[v] = dist[u] + 1;
        *que_back++ = v;
      }
    }
  }
}

int size[N];
bool vis[N];
void get_size(int u, int f)
{
  size[u] = 1;
  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != f && !vis[i->v])
      get_size(i->v, u), size[u] += size[i->v]; 
}

int tot_size, best_val, best_pos;
void get_root(int u, int f)
{
  int cur_val = tot_size - size[u];
  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != f && !vis[i->v])
    {
      get_root(i->v, u);
      if (size[i->v] > cur_val)
        cur_val = size[i->v];
    }
  if (cur_val < best_val)
    best_val = cur_val, best_pos = u;
}

int get(int u)
{
  get_size(u, 0);
  tot_size = size[u], best_val = 0x3f3f3f3f;
  get_root(u, 0);
  return best_pos;
}

struct update_t
{
  int dep, val;
};

struct update_t ups[N], *ups_top;
int ups_val[N];

int max_dep;
void get_updates(int u, int f, int dep)
{
  if (dep < dist[u])
  {
    ups_top->dep = dist[u] - dep - 1;
    ups_top->val = dist[u];
    ups_top++;
  }
  if (dep > max_dep)
    max_dep = dep;
  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != f && !vis[i->v])
      get_updates(i->v, u, dep + 1);
}

void set_updates(int u, int f, int dep)
{
  if (ans[u] < ups_val[dep])
    ans[u] = ups_val[dep];
  for (struct edge_t *i = e[u]; i; i = i->next)
    if (i->v != f && !vis[i->v])
      set_updates(i->v, u, dep + 1);
}

void dac(int u)
{
  eprintf("dac(%d)\n", u);

  u = get(u); 
  vis[u] = true;

  eprintf("dac: root = %d\n", u);

  ups_top = ups, max_dep = 0;
  get_updates(u, 0, 0);
  memset(ups_val, 0, sizeof(*ups_val) * (max_dep+1));
  for (struct update_t *i = ups; i < ups_top; ++i)
  {
    if (i->dep > max_dep)
      i->dep = max_dep;
    if (i->val > ups_val[i->dep])
      ups_val[i->dep] = i->val;
  }
  for (int i = max_dep; i>0; i--)
    if (ups_val[i-1] < ups_val[i])
      ups_val[i-1] = ups_val[i];

  set_updates(u, 0, 0);

  for (struct edge_t *i = e[u]; i; i = i->next)
    if (!vis[i->v])
      dac(i->v);
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

  memset(dist, 0x3f, sizeof(dist));
  scanf("%d", &m);
  for (int i=0; i<m; ++i) 
  {
    int u;
    scanf("%d", &u);
    dist[u] = 0;
  }

  bfs();
  dac(1);

  for (int i=1; i<=n; ++i)
    printf("%d%c", ans[i], " \n"[i==n]);

  return 0;
}