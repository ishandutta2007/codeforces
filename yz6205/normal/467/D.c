#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100005
#define M 500005
#define S 1000005
#define P (N + M * 2)

char s_pool[S], *sp_top = s_pool;
int art_id[N], se_id[M][2];
int rs[P], rsl[P];
int n, m;

struct edge_t
{
  struct edge_t *next;
  int v;
};

struct edge_t e_pool[M], *ep_top = e_pool, *e[P];

void add_edge(int u, int v)
{
  ep_top->next = e[u];
  ep_top->v    = v;
  e[u] = ep_top++;
}

struct str_sort_t
{
  char *s;
  int  *r;
};

struct str_sort_t str_id[P], *str_id_top = str_id;

int str_cmp(const void *a, const void *b)
{
  return strcmp(((const struct str_sort_t*)a)->s, 
                ((const struct str_sort_t*)b)->s);
}

void to_lower(char *s)
{
  while (*s)
  {
    if (*s >= 'A' && *s <= 'Z')
      *s = 'a' + (*s - 'A');
    s++;
  }
}

int count_r(const char *s)
{
  int res = 0;
  while (*s)
  {
    if (*s == 'r')
      res ++;
    s++;
  }
  return res;
}


int dfn[P], low[P], dfn_top;
int stack[P], *stack_top = stack;
bool in_stack[P];

void dfs(int u)
{
  /* printf("u = %d\n", u); */
  dfn[u] = low[u] = dfn_top++;
  *stack_top++ = u, in_stack[u] = true;

  for (struct edge_t *i = e[u]; i; i = i->next)
  {
    int v = i->v;
    /* printf("%d -> %d\n", u, v); */
    if (dfn[v] == -1)
      dfs(v);
    if (rs[v] < rs[u] || (rs[v] == rs[u] && rsl[v] < rsl[u]))
      rs[u] = rs[v], rsl[u] = rsl[v];
    if (in_stack[v])
      if (low[v] < low[u])
        low[u] = low[v];
  }

  if (low[u] == dfn[u])
  {
    while (stack_top[-1] != u)
    {
      stack_top--;
      rs[*stack_top] = rs[u], rsl[*stack_top] = rsl[u];
      in_stack[*stack_top] = false;
    }
    stack_top--;
    in_stack[u] = false;
  }
}


int main()
{
  scanf("%d", &m);
  for (int i=0; i<m; ++i)
  {
    scanf("%s", sp_top);
    to_lower(sp_top);
    str_id_top->s = sp_top;
    str_id_top->r = &art_id[i];
    str_id_top++;
    sp_top += strlen(sp_top) + 1;
  }


  scanf("%d", &n);
  for (int i=0; i<n; ++i)
  {
    scanf("%s", sp_top);
    to_lower(sp_top);
    str_id_top->s = sp_top;
    str_id_top->r = &se_id[i][0];
    str_id_top++;
    sp_top += strlen(sp_top) + 1;

    scanf("%s", sp_top);
    to_lower(sp_top);
    str_id_top->s = sp_top;
    str_id_top->r = &se_id[i][1];
    str_id_top++;
    sp_top += strlen(sp_top) + 1;
  }

  qsort(str_id, (size_t)(str_id_top - str_id), sizeof(*str_id), str_cmp);
  int cur_id = 0;
  for (struct str_sort_t *i = str_id; i != str_id_top; ++i)
  {
    if (i != str_id && strcmp((i-1)->s, i->s))
    {
      /* printf("%s %s\n", (i-1)->s, i->s); */
      cur_id++;
    }
    *i->r = cur_id;
    rs[cur_id] = count_r(i->s);
    rsl[cur_id] = (int)strlen(i->s);
  }

  /* for (int i=0; i<m; ++i) */
  /*   printf("%d\n", art_id[i]); */
  /* for (int i=0; i<n; ++i) */
  /*   printf("%d %d\n", se_id[i][0], se_id[i][1]); */

  for (int i=0; i<n; ++i) 
    add_edge(se_id[i][0], se_id[i][1]);
  
  memset(dfn, -1, sizeof(dfn));
  for (int i=0; i<=cur_id; ++i)
    if (dfn[i] == -1) dfs(i);

  long long ans_r = 0, ans_len = 0;
  for (int i=0; i<m; ++i)
  {
    /* printf("art_id = %d, rs = %d, rs_len = %d\n", art_id[i], art_id[i], rs[art_id[i]], rsl[art_id[i]]); */
    ans_r += rs[art_id[i]];
    ans_len += rsl[art_id[i]];
  }

  printf("%lld %lld\n", ans_r, ans_len);
}