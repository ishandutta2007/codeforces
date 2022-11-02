#include <stdio.h>
#include <stdbool.h>

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define N 100005
#define inf 0x3f3f3f3f

int min(int a, int b)
{
  return a < b ? a : b;
}

struct node_t
{
  struct node_t *s[2], *f;
  int rev, vt, at, min, val;
};

struct node_t make_node(int size, int node_val)
{
  struct node_t res = 
  {
    .s   = {NULL, NULL},
    .f   = NULL,
    .rev = 0,
    .vt  = size,
    .at  = size,
    .min = node_val,
    .val = node_val
  };
  return res;
}

struct node_t p[N * 6];

bool is_root(const struct node_t *const this)
{
  return this->f == NULL || (this->f->s[0] != this && this->f->s[1] != this);
}

void push_up(struct node_t *const this)
{
  this->at = this->vt, this->min = this->val;
  if (this->s[0])
  {
    this->at += this->s[0]->at;
    this->min = min(this->min, this->s[0]->min);
  }
  if (this->s[1])
  {
    this->at += this->s[1]->at;
    this->min = min(this->min, this->s[1]->min);
  }
}

void push_rev(struct node_t *const this)
{
  this->rev ^= 1;
  struct node_t *const tmp = this->s[0];
  this->s[0] = this->s[1], this->s[1] = tmp;
}

void push_down(struct node_t *const this)
{
  if (this->rev)
  {
    if (this->s[0]) push_rev(this->s[0]);
    if (this->s[1]) push_rev(this->s[1]);
    this->rev = 0;
  }
}

void push(struct node_t *const this)
{
  if (!is_root(this)) push(this->f);
  push_down(this);
}

void rotate(struct node_t *const this)
{
  struct node_t *const uu=this, *const ff=uu->f, *const aa=ff->f;
  bool ss = ff->s[1] == uu;
  if (!is_root(ff)) aa->s[aa->s[1] == ff] = uu;
  ff->f = uu; ff->s[ss] = uu->s[!ss];
  uu->f = aa; uu->s[!ss] = ff;
  if (ff->s[ss]) ff->s[ss]->f = ff;
  push_up(ff); push_up(uu);
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
    if ((this->f->s[1] == this) == (this->f->f->s[1] == this->f))
      rotate(this->f);
    else 
      rotate(this);
    rotate(this);
  }
}

void access(struct node_t *uu)
{
  struct node_t* ss = NULL;
  while (uu)
  {
    splay(uu);
    if (uu->s[1]) uu->vt += uu->s[1]->at;
    uu->s[1] = ss;
    if (uu->s[1]) uu->vt -= uu->s[1]->at;
    push_up(uu);
    ss = uu, uu = uu->f;
  }
}

void make_root(struct node_t *const uu)
{
  access(uu);
  splay(uu);
  push_rev(uu);
}

struct node_t *find_root(struct node_t *this)
{
  access(this);
  splay(this);
  push_down(this);
  while (this->s[0])
  {
    this = this->s[0];
    push_down(this);
  }
  splay(this);
  return this;
}

void link(struct node_t *const u, struct node_t *const v)
{
  make_root(u);
  make_root(v);
  v->f = u;
  u->vt += v->at;
  u->at += v->at;
}

void split(struct node_t *const u, struct node_t *const v)
{
  make_root(u);
  access(v);
  splay(v);
}

void cut(struct node_t *const u, struct node_t *const v)
{
  split(u, v);
  u->f = v->s[0] = NULL;
  push_up(v);
}

struct edge_t
{
  int u, v, id, day;
  bool is_cut;
};

struct edge_t make_edge(int u, int v, int id, int day)
{
  struct edge_t res = 
  {
    .u      = u,
    .v      = v,
    .id     = id,
    .day    = day,
    .is_cut = false
  };
  return res;
}
 
struct edge_t e[N * 5], *eid_to_e[N * 6];
int n, m, k;

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int i=1; i<=n; ++i)
    p[i] = make_node(1, 0x3f3f3f3f);

  struct edge_t *e_front=e, *e_back=e;
  int eid_top = n + 1;
  int day = 0;

  for (int i=0; i<m; ++i)
  {
    int opt;
    scanf("%d", &opt);
    if (opt == 1)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      struct node_t *ur = find_root(&p[u]);
      struct node_t *vr = find_root(&p[v]);
      if (ur == vr)
      {
        split(&p[u], &p[v]); 
        int min_id = p[v].min;
        int cu = eid_to_e[min_id]->u;
        int cv = eid_to_e[min_id]->v;
        cut(&p[cu], &p[min_id]);
        cut(&p[cv], &p[min_id]);
        eid_to_e[min_id]->is_cut = true;
      }
      int pos_eid = eid_top++;
      p[pos_eid] = make_node(0, pos_eid);
      *e_back = make_edge(u, v, pos_eid, day);
      eid_to_e[pos_eid] = e_back;
      e_back++;
      link(&p[u], &p[pos_eid]);
      link(&p[v], &p[pos_eid]);
    }
    else if (opt == 2)
    {
      int u;
      scanf("%d", &u);
      make_root(&p[u]);
      access(&p[u]);
      printf("%d\n", p[u].vt);
    }
    else
    {
      day++;
      while (e_front < e_back && day - e_front->day >= k)
      {
        eprintf("cutting...\n");
        if (!e_front->is_cut)
        {
          cut(&p[e_front->u], &p[e_front->id]);
          cut(&p[e_front->v], &p[e_front->id]);;
          eprintf("cutting: %d -> %d by %d\n", e_front->u, e_front->v, e_front->id);
          e_front->is_cut = true;
        }
        e_front++;
      }
    }
  }
  return 0;
}