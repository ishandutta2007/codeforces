#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define EPS 1e-8
#define LL long long
#define mod 1000003
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

const int MAXN = 105;

struct matrix
{
  int arr[MAXN][MAXN];
  int n, m;

  matrix(int x, int y)
  {
    n = x, m = y;
  };

  matrix(int x, int y, int v)
  {
    n = x, m = y;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        arr[i][j] = v;
  };

  matrix operator * (const matrix &mat) const
  {
    matrix res(n, mat.m, 0);
    for(int i=0;i<n;i++)
      for(int j=0;j<mat.m;j++)
        for(int k=0;k<m;k++)
          res.arr[i][j] = (arr[i][k] * 1LL * mat.arr[k][j] + res.arr[i][j]) % mod;
    return res;
  }
};

matrix mat_pow(const matrix &base, int power)
{
  if(power == 1) return base;
  if(power & 1) return base * mat_pow(base, power - 1);
  matrix temp = mat_pow(base, power/2);
  return temp * temp;
}

int main()
{
  int c, h, w;
  cin >> c >> w >> h;
  matrix base(w + 1, w + 1, 0);
  for(int i=0;i<=w;i++)
  {
    if(i != w) base.arr[i][i + 1] = h;
    base.arr[i][0] = 1;
  }
  base = mat_pow(base, c);
  int res = 0;
  for(int i=0;i<=w;i++)
  {
    res += base.arr[0][i];
    if(res >= mod) res -= mod;
  }
  cout << res;
  return 0;
}

/*
  DP[i][curr] = DP[i + 1][curr + 1] * H + DP[i + 1][0]
*/