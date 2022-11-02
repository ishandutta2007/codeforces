#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 200
#define M 2000

struct Edge 
{
  int u, v;
};

int d[N][N], n, m;
struct Edge e[M];

void floyd(int (*d)[N][N], int n)
{
  for (int r=0; r<n; ++r)
    for (int u=0; u<n; ++u)
      for (int v=0; v<n; ++v)
        if ((*d)[u][v] > (*d)[u][r] + (*d)[r][v])
          (*d)[u][v] = (*d)[u][r] + (*d)[r][v];
}

int main(void)
{
  memset(d, 0x3f, sizeof(d));
  for (int i=0; i<N; ++i) d[i][i] = 0;

  scanf("%d%d", &n, &m);
  for (int i=0; i<m; ++i)
  {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--; v--;
    e[i].u = u, e[i].v = v;
    if (c == 0) d[u][v] = 1, d[v][u] =  1;
    else        d[u][v] = 1, d[v][u] = -1;
  }

  floyd(&d, n);
  
  for (int i=0; i<n; ++i) if (d[i][i] < 0)
  {
    puts("no");
    return 0;
  }

  int ans = -1, start = 0;
  for (int s=0; s<n; ++s)
  {
    // check if starting from s is valid
    bool valid = true;
    for (int i=0; i<m; ++i) if (d[s][e[i].u] == d[s][e[i].v])
    {
      valid = false;
      break;
    }
    if (!valid) continue;

    int max_dis = d[s][0], min_dis = d[s][0];
    for (int i=1; i<n; ++i)
      if (d[s][i] > max_dis) max_dis = d[s][i];
      else if (d[s][i] < min_dis) min_dis = d[s][i];
    int delta = max_dis - min_dis;
    if (delta > ans)
      ans = delta, start = s;
  }

  if (ans == -1)
  {
    puts("NO");
    return 0;
  }

  puts("YES");
  printf("%d\n", ans);
  for (int i=0; i<n; ++i)
    printf("%d%c", d[start][i] + n, " \n"[i == n-1]);

  return 0;
}