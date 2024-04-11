#include <stdio.h>
#include <string.h>

#define mod 1000000007
#define N 2005

#define int long long

int p, alpha, a[N], a_len;
char sa[N];

int M(int x)
{
  return x >= mod ? x - mod : x;
}

int len, x[4003];
void init()
{
  while (a_len)
  {
    int t = 0;
    for (int i = a_len; i >= 1; --i)
    {
      t = t * 10 + a[i], a[i] = t / p, t %= p;
      if (!a[i] && i == a_len)
        --a_len;
    }
    x[++len] = t;
  }
}

signed f[3505][3505][2][2];
void solve()
{
  f[len + 1][0][0][1] = 1;
  for (int i = len, c1, c2, c3, c4, c5, c6; i >= 1; --i)
  {
    c1 = (p + 1) * p / 2 % mod;
    c2 = (x[i] + 1) * x[i] / 2 % mod;
    c3 = p * (p - 1) / 2 % mod;
    c4 = x[i] * ((p << 1) - x[i] - 1) / 2 % mod;
    c5 = x[i] * (x[i] - 1) / 2 % mod;
    c6 = x[i] * ((p << 1) - x[i] + 1) / 2 % mod;

    for (int j = 0, f0, f1, f2, f3; j <= len - i + 1; ++j)
    {
      f0 = f[i + 1][j][0][0], f1 = f[i + 1][j][0][1], f2 = f[i + 1][j][1][0], f3 = f[i + 1][j][1][1];
      if (!f0 && !f1 && !f2 && !f3)
        continue;
      f[i][j][0][0] = (c1 * f0 + c2 * f1 + c3 * f2 + c4 * f3) % mod;
      f[i][j][0][1] = ((x[i] + 1) * f1 + (p - x[i] - 1) * f3) % mod;
      f[i][j + 1][1][0] = (c3 * f0 + c5 * f1 + c1 * f2 + c6 * f3) % mod;
      f[i][j + 1][1][1] = (x[i] * f1 + (p - x[i]) * f3) % mod;
    }
  }
  int res = 0;
  for (int i = alpha; i <= len; ++i)
    res = (res + f[1][i][0][0] + f[1][i][0][1]) % mod;
  printf("%lld\n", res);
}

signed main()
{
  scanf("%lld%lld", &p, &alpha);
  scanf("%s", sa + 1);
  a_len = (int)strlen(sa + 1);

  if (alpha > 4000)
  {
    puts("0");
    return 0;
  }

  for (int i = 1; i <= a_len; ++i)
    a[i] = sa[a_len - i + 1] - '0';
  init();
  solve();
  return 0;
}