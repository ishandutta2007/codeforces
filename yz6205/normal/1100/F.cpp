#include <stdio.h>
#include <stdlib.h>

#define N 500005
#define M 20

struct query_t
{
  int l, r, id;
};

struct query_t qs[N];
int a[N], n, m;

int query_cmp(const void *a, const void *b)
{
  return ((struct query_t*)a)->r - ((struct query_t*)b)->r;
}

int p[M], pid[M];

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void insert(int x, int xid)
{
  for (int i=M-1; i>=0; --i) if (x & (1 << i))
  {
    if (p[i] == 0) 
    {
      p[i] = x;
      pid[i] = xid;
      return;
    }
    if (xid > pid[i])
    {
      swap(&xid, &pid[i]);
      swap(&x, &p[i]); 
    }
    x ^= p[i];
  }
}

int query(int min_xid)
{
  int ans = 0;
  for (int i=M-1; i>=0; --i)
    if (pid[i] >= min_xid && (ans ^ p[i]) > ans)
      ans ^= p[i];
  return ans;
}

int ans[N];

int main()
{
  scanf("%d", &n);
  for (int i=0; i<n; ++i) 
    scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i=0; i<m; ++i)
  {
    scanf("%d%d", &qs[i].l, &qs[i].r);
    qs[i].l --;
    qs[i].id = i;
  }
  qsort(qs, m, sizeof(*qs), query_cmp);

  int ar = 0;
  for (int i=0; i<m; ++i)
  {
    while (ar < qs[i].r)
    {
      insert(a[ar], ar);
      ar++;
    }
    ans[qs[i].id] = query(qs[i].l);
  }

  for (int i=0; i<m; ++i)
    printf("%d\n", ans[i]);
  return 0;
}