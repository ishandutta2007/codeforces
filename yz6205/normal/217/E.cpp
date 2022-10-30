#include <stdio.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

#ifdef __LOCALE__
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...)
#endif


#define N 5005
#define M 3000005



struct sgt_node_t
{
  int sum;
};

struct sgt_node_t sgt_p[M * 4];
int sgt_l, sgt_r;
const int sgt_root = 1;

void sgt_init(int u, int l, int r)
{
  sgt_p[u].sum = r - l;
  if (r - l > 1)
  {
    int mid = (l + r) / 2;
    sgt_init(u + u, l, mid);
    sgt_init(u + u + 1, mid, r);
  }
}

void sgt_setz(int u, int l, int r, int p)
{
  if (r - l == 1)
  {
    sgt_p[u].sum = 0;
    return;
  }
  int mid = (l + r) / 2;
  if (p < mid) sgt_setz(u + u, l, mid, p);
  else sgt_setz(u + u + 1, mid, r, p);
  sgt_p[u].sum = sgt_p[u + u].sum + sgt_p[u + u + 1].sum;
}

int sgt_query(int u, int l, int r, int k)
{
  if (r - l == 1) return l;
  int mid = (l + r) / 2;
  if (sgt_p[u + u].sum < k) 
    return sgt_query(u + u + 1, mid, r, k - sgt_p[u + u].sum);
  else return sgt_query(u + u, l, mid, k);
}


int origin[M], o2p[M];
int get_origin(int u)
{
  if (u == origin[u])
    return u;
  origin[u] = get_origin(origin[u]);
  return origin[u];
}


char s[M];
struct
{
  int l, r;
} opt[N];
int n, k;


int main()
{
  scanf("%s", s);
  scanf("%d", &k);
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    scanf("%d%d", &opt[i].l, &opt[i].r);
    opt[i].l--;
  }

  sgt_l = 0, sgt_r = k;
  sgt_init(sgt_root, sgt_l, sgt_r);
  for (int i=0; i<k; ++i)
    origin[i] = i;

  int act_len = k;
  for (int i=n-1; i>=0; i--)
  {
    int len = opt[i].r - opt[i].l;
    int src_pos = opt[i].l + 1;
    int dest_l = opt[i].r;
    for (int j=0; j < len && dest_l < act_len; j++)
    {
      if (src_pos >= opt[i].r)
        src_pos = opt[i].l;

      int act_pos = sgt_query(sgt_root, sgt_l, sgt_r, dest_l + 1);
      eprintf("j = %d, act_pos = %d, act_len = %d, src_pos = %d, dest_l = %d\n", j, act_pos, act_len, src_pos, dest_l);
      origin[act_pos] = sgt_query(sgt_root, sgt_l, sgt_r, src_pos + 1);

      sgt_setz(sgt_root, sgt_l, sgt_r, act_pos);
      act_len--;
      src_pos += 2;
    }
  }
  for (int i=0; i<act_len; ++i)
    o2p[sgt_query(sgt_root, sgt_l, sgt_r, i + 1)] = i;

  for (int i=0; i<k; ++i)
    eprintf("origin[%d] = %d\n", i, origin[i]);
  for (int i=0; i<k; ++i)
    putchar(s[o2p[get_origin(i)]]);
  
  return 0;
}