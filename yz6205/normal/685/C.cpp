#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100005

long long xi[N], yi[N], zi[N];
int       n;

long long max(long long a, long long b)
{
  return a > b ? a : b;
}

long long calc(long long x, long long y, long long z)
{
  long long res = 0;
  for (int i = 1; i <= n; ++i)
    res = max(res, llabs(xi[i] - x) + llabs(yi[i] - y) + llabs(zi[i] - z));
  return res;
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%lld%lld%lld", &xi[i], &yi[i], &zi[i]);
    if (n == 1)
    {
      printf("%lld %lld %lld\n", xi[1], yi[1], zi[1]);
    }
    else
    {
      long long x = 0, y = 0, z = 0, ans = calc(x, y, z);
      for (long long d = 1e18; d;)
      {
        bool flag = 1;
        for (long long dx = -d; flag && dx <= d; dx += d)
          for (long long dy = -d; flag && dy <= d; dy += d)
            for (long long dz = -d; flag && dz <= d; dz += d)
            {
              long long t = calc(x + dx, y + dy, z + dz);
              if (t < ans)
                ans = t, x += dx, y += dy, z += dz, flag = 0;
            }
        if (flag)
          d >>= 1;
      }
      printf("%lld %lld %lld\n", x, y, z);
    }
  }
}