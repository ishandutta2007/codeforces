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
const int M = 1024 * 512;

vector<int> V[M];
int zrob[2][M];
PII E[M];
bool vis[2][M];
char R[2][M];
int n, k = 1, s, m, r[2];

int dir(int i, int v, int ind)
{
  zrob[ind][i] = 1;
  //debug("%d %d %d\n", i, v, ind);
  if (E[i].F == abs(v))
  {
    if (v > 0)
    {
      R[ind][i] = '-';
      return v;
    }
    else
    {
      R[ind][i] = '+';
      return E[i].S;
    }
  }
  else
  {
    if (v < 0)
    {
      R[ind][i] = '-';
      return E[i].F;
    }
    else
    {
      R[ind][i] = '+';
      return E[i].S;
    }
  }
  
}

int DFSmi(int v, int ind)
{
  vis[ind][v] = 1;
  int siz = 1;
  for (int i = 0; i < siz(V[v]); i++)
  {
    if (V[v][i] > 0)
    {
      if (!vis[ind][V[v][i]])
      {
        siz += DFSmi(V[v][i], ind);
      }
    }
    else
    {
      if (zrob[ind][-V[v][i]])
      {
        continue;
      }
      dir(-V[v][i], v, ind);
    }
  }
  return siz;
}

int DFSma(int v, int ind)
{
  vis[ind][v] = 1;
  int siz = 1;
  for (int i = 0; i < siz(V[v]); i++)
  {
    if (V[v][i] > 0)
    {
      if (!vis[ind][V[v][i]])
      {
        siz += DFSma(V[v][i], ind);
      }
    }
    else
    {
      if (zrob[ind][-V[v][i]])
      {
        continue;
      }
      int u = dir(-V[v][i], -v, ind);
      if (!vis[ind][u])
      {
        siz += DFSma(u, ind);
      }
    }
  }
  return siz;
}

int main()
{
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1)
    {
      V[b].PB(c);
    }
    else
    {
      E[k] = MP(b, c);
      V[b].PB(-k);
      V[c].PB(-k);
      k++;
    }
  }
  r[1] = DFSmi(s, 1);
  r[0] = DFSma(s, 0);
  for (int i = 0; i < 2; i++)
  {
    printf("%d\n", r[i]);
    for (int j = 1; j < k; j++)
    {
      if (R[i][j] != '+' && R[i][j] != '-')
      {
        printf("+");
      }
      else
      {
        printf("%c", R[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}