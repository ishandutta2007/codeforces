#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

#define MOD 1000000007
#define N 100005
#define B 20
#define M 305

struct node_t
{
  struct node_t *f;
  struct node_t *s[2];
  int val, tot;
  bool rev;
};

bool is_root(struct node_t *const this)
{
  return this->f == NULL || 
        (this->f->s[0] != this && this->f->s[1] != this);
}

bool get_son(struct node_t *const this)
{
  return this->f->s[1] == this;
}

void push_up(struct node_t *const this)
{
  this->tot = this->val;
  if (this->s[0]) this->tot += this->s[0]->tot;
  if (this->s[1]) this->tot += this->s[1]->tot;
}

void reverse(struct node_t *const this)
{
  struct node_t *tmp = this->s[0];
  this->s[0] = this->s[1], this->s[1] = tmp;
  this->rev = !this->rev;
}

void push_down(struct node_t *const this)
{
  if (this->rev)
  {
    if (this->s[0]) reverse(this->s[0]);
    if (this->s[1]) reverse(this->s[1]);
    this->rev = false;
  }
}

void push(struct node_t *const this)
{
  if (!is_root(this)) push(this->f);
  push_down(this);
}

void rotate(struct node_t *const this)
{
  struct node_t *const uu = this, *const ff = uu->f, *const aa = ff->f;
  bool ss = get_son(this);
  if (!is_root(ff)) aa->s[get_son(ff)] = uu;
  ff->f = uu, ff->s[ss] = uu->s[!ss];
  uu->f = aa, uu->s[!ss] = ff;
  if (ff->s[ss]) ff->s[ss]->f = ff;
  push_up(ff);
}

void splay(struct node_t *const this)
{
  push(this);
  while (!is_root(this))
  {
    if (is_root(this->f))
    {
      rotate(this);
      break;
    }
    rotate(get_son(this) == get_son(this->f) ? this->f : this);
    rotate(this);
  }
  push_up(this);
}

void access(struct node_t *const this)
{
  struct node_t *uu = this, *ss = NULL;
  while (uu)
  {
    splay(uu);
    uu->s[1] = ss;
    push_up(uu);
    ss = uu, uu = uu->f;
  }
}

void make_root(struct node_t *const this)
{
  access(this);
  splay(this);
  reverse(this);
}

struct node_t p[N];

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

int dep[N];
int fa[N][B];
int n, q;

void dfs(int u, int f)
{
  dep[u] = dep[f] + 1;
  fa[u][0] = f;
  for (int i=0; i+1<B; ++i)
    fa[u][i+1] = fa[fa[u][i]][i];

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    if (v == f) continue;
    p[v].f = &p[u];
    dfs(v, u);
  }
}

int lca(int u, int v)
{
  if (dep[u] < dep[v])
  {
    int tmp = u;
    u = v, v = tmp;
  }
  int delta = dep[u] - dep[v];
  for (int i=0; i<B; ++i)
    if (delta & (1 << i))
      u = fa[u][i];
  for (int i=B-1; i>=0; i--)
    if (fa[u][i] != fa[v][i])
      u = fa[u][i], v = fa[v][i];
  return u == v ? u : fa[u][0];
}

int dis(int u, int v)
{
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int deps[N], us[N], ids[N];

int cmp_deps(const void *a, const void *b)
{
  return deps[*(int*)a] - deps[*(int*)b];
}

int dp[N][M];

void solve()
{
  int k, r, m;
  scanf("%d%d%d", &k, &m, &r);
  make_root(&p[r]);
  for (int i=0; i<k; ++i)
  {
    scanf("%d", &us[i]);
    deps[i] = dis(r, us[i]);
    ids[i] = i;
  }
  qsort(ids, (size_t)k, sizeof(*ids), cmp_deps);

  dp[0][0] = 1;
  for (int i=0; i<k; ++i)
  {
    int u = us[ids[i]];
    access(&p[u]);
    splay(&p[u]);
    int conflict = p[u].tot;
    p[u].val++, p[u].tot++;
    for (int j=1; j<=m; ++j)
      dp[i+1][j] = (1ll * max(0, j-conflict) * dp[i][j] + dp[i][j-1]) % MOD;
  }

  for (int i=0; i<k; ++i)
  {
    int u = us[ids[i]];
    access(&p[u]);
    splay(&p[u]);
    p[u].val--, p[u].tot--;
  }

  int ans = 0;
  for (int i=1; i<=m; ++i)
    ans = (ans + dp[k][i]) % MOD;

  printf("%d\n", ans);
}

int main()
{
  scanf("%d%d", &n, &q);
  for (int i=1; i<n; ++i)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  dfs(1, 0);

  for (int i=0; i<q; ++i)
    solve();
  
  return 0;
}