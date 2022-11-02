#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define GN 205
#define N 80020
#define M N * 2

struct edge_t
{
  struct edge_t *next;
  int v, w;
};

struct edge_t *e[N], *ef[N];
struct edge_t e_pool[M * 4], *ep_top = e_pool;

struct edge_t *get_rev_edge(const struct edge_t *const p)
{
  return e_pool + ((long)(p - e_pool) ^ 1);
}

void add_edge(int u, int v, int w)
{
  eprintf("add_edge: %d %d\n", u, v);
  ep_top->v    = v;
  ep_top->w    = w;
  ep_top->next = e[u];
  e[u] = ep_top++;
  ep_top->v    = u;
  ep_top->w    = 0;
  ep_top->next = e[v];
  e[v] = ep_top++;
}

int dep[N], s, t, un;

bool bfs()
{
  memset(dep, -1, sizeof(*dep) * un);
  dep[s] = 0;
  static int que[N];
  int *que_front = que, *que_back = que_front;
  *que_back++ = s;
  while (que_front != que_back)
  {
    int u = *que_front++;
    for (struct edge_t *i = e[u]; i; i = i->next) if (i->w)
    {
      int v = i->v;
      if (dep[v] == -1)
      {
        dep[v] = dep[u] + 1;
        *que_back++ = v;
      }
    }
  }
  eprintf("dep[t] = %d\n", dep[t]);
  return dep[t] != -1;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int dfs(int u, int limit)
{
  if (u == t) return limit;
  if (limit == 0) return 0;
  int remain = limit;
  for (struct edge_t **i = &ef[u]; *i; *i = (*i)->next)
  {
    int v = (*i)->v, w = (*i)->w;
    if (w == 0 || dep[v] != dep[u] + 1) continue;
    int v_limit = min(remain, w);
    int cur = dfs(v, v_limit);
    remain -= cur;
    (*i)->w -= cur;
    get_rev_edge(*i)->w += cur;
  }
  return limit - remain;
}

int dinic()
{
  int ans = 0;
  while (bfs())
  {
    memcpy(ef, e, sizeof(*ef) * un);
    int cur = 0;
    while ((cur = dfs(s, 0x3f3f3f3f)))
      ans += cur;
  }
  eprintf("ans = %d\n", ans);
  return ans;
}

int n, m;
char map[GN][GN];
int idj[GN][GN], idl[GN][GN];

int main()
{
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; ++i)
    scanf("%s", map[i]);

  s = un++, t = un++;
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
    {
      idl[i][j] = un++;
      add_edge(s, idl[i][j], 1);
      idj[i][j] = un++;
      add_edge(idj[i][j], t, 1);
    }

  int ans = 0;
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      if (map[i][j] == '#')
      {
        ans++;
        if (map[i][j+1] == '#') ans--;
        if (map[i+1][j] == '#') ans--;
        if (i > 0 && j > 0 && map[i-1][j] == '#' && map[i][j-1] == '#')
          add_edge(idl[i][j-1], idj[i-1][j], 1);
        if (i > 0 && j+1 < m && map[i-1][j] == '#' && map[i][j+1] == '#')
          add_edge(idl[i][j], idj[i-1][j], 1);
        if (i+1 < n && j > 0 && map[i+1][j] == '#' && map[i][j-1] == '#')
          add_edge(idl[i][j-1], idj[i][j], 1);
        if (i+1 < n && j+1 < m && map[i+1][j] == '#' && map[i][j+1] == '#')
          add_edge(idl[i][j], idj[i][j], 1);
      }

  ans += dinic();
  printf("%d\n", ans);

  return 0;
}