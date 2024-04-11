#include <stdio.h>

#define N 500005

int pos = 0, val = 0, val2 = 0, cnt = 0, mx, mn, rex, rey;
int du[N], h[N], to[N], ver[N];
int dis[N], tag[N], pre[N], s[N], leaf[N], sec[N];

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y, *y = tmp;
}

void add_edge(int x, int y)
{
  to[++cnt] = y;
  ver[cnt] = h[x];
  h[x] = cnt;
}

void dfs2(int x)
{
  du[x] = 0;
  if (dis[mx] - dis[mn] > val)
    pos = x, val = dis[mx] - dis[mn], val2 = dis[leaf[mn]] + dis[leaf[mx]] + dis[x];
  else if (val == dis[mx] - dis[mn] && dis[leaf[mn]] + dis[leaf[mx]] + dis[x] > val2)
    pos = x, val2 = dis[leaf[mn]] + dis[leaf[mx]] + dis[x];

  for (int i = h[x], y; i; i = ver[i])
  {
    if (pre[x] == (y = to[i]))
      continue;
    ++du[x];
  }

  for (int i = h[x], y; i; i = ver[i])
  {
    if (pre[x] == (y = to[i]))
      continue;
    pre[y] = x;
    dis[y] = dis[x] + 1;
    int premx = mx, premn = mn;
    int flag = 0;
    if (leaf[y] == leaf[x])
    {
      flag = 1;
      swap(&leaf[x], &sec[x]);
    }
    if (du[x] > 1)
    {
      if (dis[x] > dis[mx])
        mx = x;
      else if (dis[x] == dis[mx] && dis[leaf[x]] > dis[leaf[mx]])
        mx = x;
      if (dis[x] < dis[mn])
        mn = x;
      else if (dis[x] == dis[mn] && dis[leaf[x]] > dis[leaf[mn]])
        mn = x;
    }
    dfs2(y);
    mx = premx;
    mn = premn;
    if (flag)
      swap(&leaf[x], &sec[x]);
  }
}

void dfs3(int x)
{
  leaf[x] = x;
  for (int i = h[x], y; i; i = ver[i])
  {
    if (pre[x] == (y = to[i]) || tag[y])
      continue;
    pre[y] = x;
    dfs3(y);

    if (dis[leaf[x]] < dis[leaf[y]])
    {
      sec[x] = leaf[x];
      leaf[x] = leaf[y];
    }
    else if (dis[sec[x]] < dis[leaf[y]])
    {
      sec[x] = leaf[y];
    }
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int top = 0, st, ed;
  dis[0] = mx = 0;
  dis[n + 1] = mn = n + 1;
  for (int i = 1; i < n; ++i)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y), add_edge(y, x);
  }

  dis[1] = pos = val = 0;
  dfs2(1);

  st = pos;
  pre[st] = -1;
  dis[st] = pos = val = 0;
  dfs3(st);
  mx = 0, mn = n + 1;
  dfs2(st);
  ed = pos;

  int cur = ed, rex, rey;
  while (cur != -1)
  {
    s[++top] = cur;
    tag[cur] = 1;
    cur = pre[cur];
  }
  mx = 0, mn = n + 1;
  for (int i = top - 1; i >= 2; --i)
  {
    int x = s[i];
    for (int k = h[x], y; k; k = ver[k])
      if (!tag[y = to[k]])
        mx = (dis[x] > dis[mx] ? x : mx), mn = (dis[x] < dis[mn] ? x : mn);
  }
  dfs3(mn);
  rex = leaf[mn];
  dfs3(mx);
  rey = leaf[mx];

  printf("%d %d\n%d %d\n", st, ed, rex, rey);
  return 0;
}