#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define F first
#define S second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
const int inf = 1e9;
const int M = 1024 * 1024;

int n, p, g;
char C[M];
int dp[M];
vector<int> P, G;

bool check(int m)
{
  for (int i = 0; i <= p; i++)
  {
    dp[i] = 0;
  }
  int lg = -1, rg = -1, pp = -1;
  for (int i = 0; i < n; i++)
  {
    if (C[i] =='.')
    {
      continue;
    }
    if (C[i] == '*')
    {
      rg++;
      continue;
    }
    pp++;
    while (lg < rg && G[lg + 1] + m < i)
    {
      lg++;
    }
    //debug(" %d %d %d %d %d\n", i, lg, G[lg], rg, G[rg]);
    if (rg == -1)
    {
      dp[pp] = i;
      continue;
    }
    if (pp == 0)
    {
      if (rg == -1)
      {
        dp[pp] = i;
      }
      else
      {
        if (G[0] + m < i)
        {
          return false;
        }
        dp[pp] = -inf;
      }
      continue;
    }
    if (dp[pp - 1] + m >= G[rg] || G[rg] < P[pp - 1])
    {
      //debug("lolol ");
      dp[pp] = i;
      continue;
    }
    if (lg >= 0 && G[lg] >= P[pp - 1] && dp[pp - 1] + m < G[lg])
    {
      //debug("lol");
      return false;
    }
    if (pp >= 2 && P[pp - 2] + m >= i)
    {
      dp[pp] = P[pp - 1];
      continue;
    }
    if (P[pp - 1] + m >= i)
    {
      if (lg == -1)
      {
        dp[pp] = P[pp - 1];
        continue;
      }
      if (pp >= 2 && (dp[pp - 2] + m >= G[lg] || G[lg] < P[pp - 2]))
      {
        dp[pp] = P[pp - 1];
        continue;
      }
    }
    dp[pp] = dp[pp - 1];
  }
  //debug("%d: %d\n", m, p);
  for (int i = 0; i < p; i++)
  {
  //  debug("     %d %d\n", i, dp[i]);
  }
  return (G[siz(G) - 1] < P[siz(P) - 1]) || (dp[p - 1] + m >= G[siz(G) - 1]);
}

int main()
{
  scanf("%d%s", &n, C);
  for (int i = 0; i < n; i++)
  {
    if (C[i] == 'P')
    {
      p++;
      P.PB(i);
    }
    if (C[i] == '*')
    {
      g++;
      G.PB(i);
    }
  }
  //debug("%d %d\n", p, g);
  if (p == 1)
  {
    int l = 0, r = 0, ld = P[0] - G[0], rd = G[siz(G) - 1] - P[0];
    for (int i = 0; i < P[0]; i++)
    {
      if (C[i] == '*')
      {
        l++;
      }
    }
    for (int i = P[0]; i < n; i++)
    {
      if (C[i] == '*')
      {
        r++;
      }
    }
    if (l < r)
    {
      printf("%d %d\n", r, rd);
      return 0;
    }
    if (l > r)
    {
      printf("%d %d\n", l, ld);
      return 0;
    }
    printf("%d %d\n", l, min(ld, rd));
    return 0;
  }
  int st = 0, en = 1e6, mid = (st + en) / 2, res = en;
  while (st <= en)
  {
    //debug("%d\n", mid);
    if (check(mid))
    {
      res = min(res, mid);
      en = mid - 1;
    }
    else
    {
      st = mid + 1;
    }
    mid = (st + en) / 2;
  }
  printf("%d %d\n", siz(G), res);
  return 0;
}