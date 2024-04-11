#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007
#define N 100005

#ifdef __LOCALE__
#define eprintf(...) do { printf(__VA_ARGS__); fflush_unlocked(stdout); } while (false)
#else
#define eprintf(...)
#endif

#define this t

__attribute__ ((always_inline))
int test_dec(int x)
{
  return x >= MOD ? x - MOD : x;
}

__attribute__ ((always_inline))
int test_inc(int x)
{
  return x < 0 ? x + MOD : x;
}

int power(int a, int b)
{
  int r = 1;
  for (; b; b >>= 1)
  {
    if (b & 1) r = (1ll * r * a) % MOD;
    a = (1ll * a * a) % MOD;
  }
  return r;
}

int inv[N];
void init_inv()
{
  inv[1] = 1;
  for (int i=2; i<N; ++i)
    inv[i] = 1ll * (MOD - MOD/i) * inv[MOD % i] % MOD;
}

int l[N], r[N], inv_len[N], n;

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


int sgt_l = 0x3f3f3f3f, sgt_r = -1;

struct node_t
{
  int len;
  int cnt, tot;
  int cnt_add, tot_add;
  bool clear;
} p[N * 4];

__attribute__ ((always_inline))
void node_init(struct node_t *this)
{
  this->cnt = this->cnt_add = 0;
  this->tot = this->tot_add = 0;
  this->clear = false;
}

void sgt_init(int u, int l, int r)
{
  p[u].len = r - l;
  if (r - l == 1) return;
  int mid = (l + r) / 2;
  sgt_init(u+u, l, mid);
  sgt_init(u+u+1, mid, r);
}

__attribute__ ((always_inline)) 
struct node_t push_up(const struct node_t *a, const struct node_t *b)
{
  const struct node_t res = 
  {
    .len = a->len + b->len,
    .cnt = test_dec(a->cnt + b->cnt),
    .tot = test_dec(a->tot + b->tot),
    .cnt_add = 0,
    .tot_add = 0,
    .clear = false,
  };
  return res;
}

__attribute__ ((always_inline))
void cnt_add(struct node_t *this, int val)
{
  this->cnt = (this->cnt + 1ll * this->len * val) % MOD;
  this->cnt_add = test_dec(this->cnt_add + val);
}

__attribute__ ((always_inline))
void tot_add(struct node_t *this, int val)
{
  this->tot = (this->tot + 1ll * this->len * val) % MOD;
  this->tot_add = test_dec(this->tot_add + val);
}

__attribute__ ((always_inline))
void cnt_tot_add(struct node_t *this, int val_cnt, int val_tot)
{
  this->cnt = (this->cnt + 1ll * this->len * val_cnt) % MOD;
  this->cnt_add = test_dec(this->cnt_add + val_cnt);
  this->tot = (this->tot + 1ll * this->len * val_tot) % MOD;
  this->tot_add = test_dec(this->tot_add + val_tot);
}

__attribute__ ((always_inline))
void node_clear(struct node_t *this)
{
  node_init(this);
  this->clear = true;
}

__attribute__ ((always_inline))
void push_down(struct node_t *this, struct node_t *l, struct node_t *r)
{
  if (this->clear)
  {
    node_clear(l);
    node_clear(r);
    this->clear = false;
  }
  if (this->cnt_add)
    cnt_add(l, this->cnt_add), cnt_add(r, this->cnt_add), this->cnt_add = 0;
  if (this->tot_add)
    tot_add(l, this->tot_add), tot_add(r, this->tot_add), this->tot_add = 0;
}

void modify(int u, int l, int r, int ml, int mr, int arg0, int arg1)
{
  /* eprintf("modify: [%d -> (%d, %d)], [%d, %d] += %d\n", u,l,r,ml,mr,arg); */
  if (ml <= l && r <= mr)
  {
    cnt_tot_add(&p[u], arg0, arg1);
    return;
  }
  push_down(&p[u], &p[u + u], &p[u + u + 1]);
  int mid = (l + r) / 2;
  if (ml < mid) modify(u+u, l, mid, ml, mr, arg0, arg1);
  if (mr > mid) modify(u+u+1, mid, r, ml, mr, arg0, arg1);
  p[u] = push_up(&p[u + u], &p[u + u + 1]);
}

struct node_t query(int u, int l, int r, int ql, int qr)
{
  if (ql <= l && r <= qr)
    return p[u];
  push_down(&p[u], &p[u + u], &p[u + u + 1]);
  int mid = (l + r) / 2;
  if (qr <= mid) return query(u+u, l, mid, ql, qr);
  if (ql >= mid) return query(u+u+1, mid, r, ql, qr);
  const struct node_t l_ans = query(u+u, l, mid, ql, qr);
  const struct node_t r_ans = query(u+u+1, mid, r, ql, qr);
  return push_up(&l_ans, &r_ans);
}


int ans = 0;

bool vis[N];
int size[N];

void get_size(int u, int f)
{
  size[u] = 1;
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f || vis[v]) continue;
    get_size(v, u);
    size[u] += size[v];
  }
}

int tot_size;
int best_val, best_id;

void get_root(int u, int f)
{
  int cur_val = tot_size - size[u];
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f || vis[v]) continue;
    get_root(v, u);
    if (cur_val < size[v])
      cur_val = size[v];
  }
  if (best_val > cur_val)
    best_val = cur_val, best_id = u;
}

int get(int u)
{
  get_size(u, -1);
  tot_size = size[u];
  best_val = 0x3f3f3f3f;
  get_root(u, -1);
  return best_id;
}

struct modify_t
{
  int l, r, cnt_del, tot_del;
};

struct modify_t mdfs[N], *mdfs_top = mdfs;

void dfs(int u, int f, int dep)
{
  struct node_t info = query(1, sgt_l, sgt_r, l[u], r[u] + 1); 
  ans = (ans + 1ll * info.cnt * dep % MOD * inv_len[u]
             + 1ll * info.tot * inv_len[u]) % MOD;
  mdfs_top->l = l[u], mdfs_top->r = r[u] + 1;
  mdfs_top->cnt_del = inv_len[u];
  mdfs_top->tot_del = 1ll * dep * inv_len[u] % MOD;
  mdfs_top++;

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f || vis[v]) continue;
    dfs(v, u, dep + 1);
  }
}

void dac(int u)
{
  u = get(u);
  vis[u] = true;
  eprintf("dac: %d\n", u);

  node_clear(&p[1]);
  modify(1, sgt_l, sgt_r, l[u], r[u] + 1, inv_len[u], 0);
  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (vis[v]) continue;

    mdfs_top = mdfs;
    dfs(v, u, 1);
    for (struct modify_t *i = mdfs; i < mdfs_top; ++i)
      modify(1, sgt_l, sgt_r, i->l, i->r, i->cnt_del, i->tot_del);
  }

  for (struct edge_t *i = e[u]; i; i = i->next)
    if (!vis[i->v]) dac(i->v);
}

int main()
{
  init_inv();

  int mul = 1;
  scanf("%d", &n);
  for (int i=1; i<=n; ++i)
  {
    scanf("%d%d", &l[i], &r[i]);
    if (l[i] < sgt_l) sgt_l = l[i];
    if (r[i] + 1 > sgt_r) sgt_r = r[i] + 1;
    inv_len[i] = inv[r[i] - l[i] + 1];
    mul = (1ll * (r[i] - l[i] + 1) * mul) % MOD;
  }
  for (int i=1; i<n; ++i) 
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  sgt_init(1, sgt_l, sgt_r);
  dac(1);
  printf("%lld\n", 1ll * mul * ans % MOD);

  return 0;
}