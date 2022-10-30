#include <stdio.h>
#include <stdbool.h>

#define N 200005

int n, k;

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

int color[N];

void dye_2(int u, int f)
{
  color[u] = !color[f];
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dye_2(v, u);
  }
}

struct far_t
{
  int dis, id;
};

struct far_t get_far(int u, int f)
{
  struct far_t res = { .dis = 0, .id = u };
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    const int v = i->v;
    if (v == f) continue;
    struct far_t v_far = get_far(v, u);
    if (v_far.dis + 1 > res.dis)
      res = v_far, res.dis ++;
  }
  return res;
}

int d_u, d_v, dlen;
int dis_u[N], dis_v[N];
bool on_chain[N], bel_u[N];

void init_dis(int *dest, int u, int f, int cur_dis)
{
  dest[u] = cur_dis;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    init_dis(dest, v, u, cur_dis + 1); 
  }
}

void dye_chain(int u, int f)
{
  color[u] = dis_u[u] % k;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (!on_chain[v] || v == f) continue;
    dye_chain(v, u);
  }
}

void calc_bel(int u, int f)
{
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    calc_bel(v, u);
    bel_u[u] |= bel_u[v];
  }
}

int main()
{
  scanf("%d%d", &n, &k);
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  if (k == 2)
  {
    puts("Yes");
    dye_2(1, 0);
    for (int i=1; i<=n; ++i)
      printf("%d%c", color[i] + 1, " \n"[i == n]);
    return 0;
  }
    
  d_u = get_far(1, 0).id;
  d_v = get_far(d_u, 0).id;
  init_dis(dis_u, d_u, 0, 0);
  init_dis(dis_v, d_v, 0, 0);
  dlen = dis_u[d_v];

  for (int i=1; i<=n; ++i)
  {
    if (dis_u[i] + dis_v[i] == dlen)
      on_chain[i] = true;
    else if (dis_u[i] >= k-1 && dis_v[i] >= k-1)
    {
      puts("No");
      return 0;
    }
    if (dis_u[i] >= k - 1)
      bel_u[i] = true; 
  }

  dye_chain(d_u, 0);
  calc_bel(d_u, 0);
  for (int u=1; u<=n; ++u) if (!on_chain[u])
  {
    if (bel_u[u]) color[u] = dis_u[u] % k;
    else color[u] = ((color[d_v] - dis_v[u]) % k + k) % k;
  }

  puts("Yes");
  for (int i=1; i<=n; ++i)
    printf("%d%c", color[i] + 1, " \n"[i == n]);

  return 0;
}