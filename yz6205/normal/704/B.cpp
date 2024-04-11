#include <bits/stdc++.h>

inline int read()
{
  char c;
  int  x;
  for (c = getchar(); !isdigit(c); c = getchar())
    ;
  for (x = 0; isdigit(c); c = getchar())
  {
    x = x * 10 + c - '0';
  }
  return x;
}

const int N = 5e3 + 5;

int       n, s, t, x[N], a[N], b[N], c[N], d[N];
long long f[N], g[N];

int main()
{
  n = read();
  s = read();
  t = read();
  for (int i = 1; i <= n; i++)
  {
    x[i] = read();
  }
  for (int i = 1; i <= n; i++)
  {
    a[i] = read();
    a[i] += x[i];
  }
  for (int i = 1; i <= n; i++)
  {
    b[i] = read();
    b[i] -= x[i];
  }
  for (int i = 1; i <= n; i++)
  {
    c[i] = read();
    c[i] += x[i];
  }
  for (int i = 1; i <= n; i++)
  {
    d[i] = read();
    d[i] -= x[i];
  }
  memset(f, 60, (n + 1) * 8);
  f[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    memcpy(g, f, (n + 1) * 8);
    memset(f, 60, (n + 1) * 8);
    for (int j = 0; j <= n; j++)
    {
      if (i == s)
      {
        if (s < t)
        {
          if (j < n)
          {
            f[j] = std::min(f[j], g[j + 1] + c[i]);
          }
          if (j > 0 || s == 1)
          {
            f[j] = std::min(f[j], g[j] + d[i]);
          }
        }
        else
        {
          if (j > 0)
          {
            f[j] = std::min(f[j], g[j - 1] + d[i]);
          }
          if (j > 0 || s == n)
          {
            f[j] = std::min(f[j], g[j] + c[i]);
          }
        }
        continue;
      }
      if (i == t)
      {
        if (s < t)
        {
          if (j > 0)
          {
            f[j] = std::min(f[j], g[j - 1] + b[i]);
          }
          if (j > 0 || t == n)
          {
            f[j] = std::min(f[j], g[j] + a[i]);
          }
        }
        else
        {
          if (j < n)
          {
            f[j] = std::min(f[j], g[j + 1] + a[i]);
          }
          if (j > 0 || t == 1)
          {
            f[j] = std::min(f[j], g[j] + b[i]);
          }
        }
        continue;
      }
      if (j > 0)
      {
        f[j] = std::min(f[j], g[j - 1] + b[i] + d[i]);
      }
      if (j > 0 || (s < i && i < t))
      {
        f[j] = std::min(f[j], g[j] + a[i] + d[i]);
      }
      if (j > 0 || (t < i && i < s))
      {
        f[j] = std::min(f[j], g[j] + b[i] + c[i]);
      }
      if (j < n && (j > 0 || (s < i && i < t) || (t < i && i < s) || i == n))
      {
        f[j] = std::min(f[j], g[j + 1] + a[i] + c[i]);
      }
    }
  }
  printf("%lld\n", f[0]);
  return 0;
}