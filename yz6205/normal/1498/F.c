#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) 
#endif

#define N 100005
#define B 41

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

int w[N], n, k;

struct block_t
{
  int data[B];
};

void block_init(struct block_t *const this)
{
  memset(this->data, 0, sizeof(this->data));
}

void block_shift(struct block_t *const this)
{
  for (int i=2*k-1; i>=0; --i)
    this->data[i+1] = this->data[i];
  this->data[0] = this->data[2*k];
}

void block_add(struct block_t *const this, const struct block_t *const rhs)
{
  for (int i=0; i<2*k; ++i)
    this->data[i] ^= rhs->data[i];
}

struct block_t sum[N];

void dfs0(int u, int f)
{
  block_init(&sum[u]);
  sum[u].data[0] ^= w[u];
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    dfs0(v, u);
    struct block_t vb = sum[v];
    block_shift(&vb);
    block_add(&sum[u], &vb);
  }
  eprintf("sum[%d] = [%d, %d]\n", u, sum[u].data[0], sum[u].data[1]);
}

void dfs1(int u, int f, struct block_t fb)
{
  block_shift(&fb);
  eprintf("fb[%d] = [%d, %d]\n", u, fb.data[0], fb.data[1]);
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    struct block_t vb = sum[v];
    block_shift(&vb);
    block_add(&vb, &sum[u]);
    block_add(&vb, &fb);
    dfs1(v, u, vb);
  }
  block_add(&sum[u], &fb);
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
  for (int i=1; i<=n; ++i)
    scanf("%d", &w[i]);
  
  dfs0(1, 0);
  dfs1(1, 0, sum[0]);

  for (int i=1; i<=n; ++i) 
  {
    int sg = 0;
    for (int j=k; j<k+k; ++j)
      sg ^= sum[i].data[j];
    fputs(sg ? "1 " : "0 ", stdout);
  }
  return 0;
}