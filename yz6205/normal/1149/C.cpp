#include <stdio.h>

#define N 200005
#define this t

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

struct sgt_node_t
{
  int sum;
  /* sum_pre is minimal, sum_suf is maxial  */
  int sum_pre, sum_suf;
  int del_pre, del_suf, del_all;
  int del;
};

struct sgt_node_t p[N * 4];

void push_up(struct sgt_node_t *this, 
             const struct sgt_node_t *l,
             const struct sgt_node_t *r)
{
  this->sum     = l->sum + r->sum;
  this->sum_pre = min(l->sum_pre, l->sum + r->sum_pre);
  this->sum_suf = max(r->sum_suf, r->sum + l->sum_suf);
  this->del_pre = max(l->del_pre, max(l->sum + r->del_pre, l->del_all - r->sum_pre));
  this->del_suf = max(r->del_suf, max(l->del_suf - r->sum, r->del_all + l->sum_suf));
  this->del_all = max(l->del_all - r->sum, l->sum + r->del_all);
  this->del     = max(max(l->del, r->del), max(l->del_suf - r->sum_pre, l->sum_suf + r->del_pre));
}

void sgt_node_set(struct sgt_node_t *this, int val)
{
  this->sum = val;
  this->sum_pre = min(0, val);
  this->sum_suf = max(0, val);
  this->del_pre = this->del_suf = this->del_all = this->del = 1;
}

void modify(int u, int l, int r, int pos, int val)
{
  if (r - l == 1) 
    sgt_node_set(&p[u], val);
  else
  {
    int mid = (l + r) / 2;
    if (pos < mid) modify(u + u, l, mid, pos, val);
    else           modify(u + u + 1, mid, r, pos, val);
    push_up(&p[u], &p[u + u], &p[u + u + 1]);
  }
}

int n, q;
char s[N];
int val[N];

int main()
{
  scanf("%d%d", &n, &q);
  n = n * 2 - 2;
  scanf("%s", s);
  for (int i=0; i<n; ++i)
  {
    val[i] = s[i] == ')' ? 1 : -1;
    modify(1, 0, n, i, val[i]);
    /* printf("val[%d] = %d\n", i, val[i]); */
  }

  printf("%d\n", p[1].del);

  for (int i=0; i<q; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    if (val[a] != val[b])
    {
     modify(1, 0, n, a, val[b]);
     modify(1, 0, n, b, val[a]);
     int tmp = val[a];
     val[a] = val[b];
     val[b] = tmp;
    }
    printf("%d\n", p[1].del);
  }

  return 0;
}