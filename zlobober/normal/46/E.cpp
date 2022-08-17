#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1501;

const long long INF = 10000000000000LL;

long long F[N][N];

long long A[N][N];
long long S[N][N];

int main()
{
  //freopen("in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	  scanf("%I64d", &F[i][j]);
	
  
  for (int i = 0; i < n; i++)
  {
	S[i][0] = F[i][0];
	for (int j = 1; j < m; j++)
	  S[i][j] = S[i][j - 1] + F[i][j];
  }
  
  for (int j = 0; j < m; j++)
	A[0][j] = S[0][j];
  
  
  for (int i = 1; i < n; i++)
  {
	if (i % 2)
	{
	  long long mx = -INF;
	  for (int j = m - 1; j >= 0; j--)
	  {
		A[i][j] = mx + S[i][j];
		mx = max(mx, A[i - 1][j]);
	  }
	}
	else
	{
	  long long mx = -INF;
	  for (int j = 0; j < m; j++)
	  {
		A[i][j] = mx + S[i][j];
		mx = max(mx, A[i - 1][j]);
	  }
	}
  }
  long long mx = -INF;
  for (int j = 0; j < m; j++)
  {
	mx = max(mx, A[n - 1][j]);
  }
  printf("%I64d", mx);
}