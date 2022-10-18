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

int arr[605][605];

int main()
{
  //freopen("test.in", "r", stdin);
  int q, n, m;
  cin >> q;
  while(q--)
  {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        scanf("%d", &arr[i][j]);
    int x = 0, y = 0;
    for(int j=0;j<m;j++)
    {
      x += (arr[n / 2 - 1][j] - arr[n / 2][j]) * (arr[n / 2 - 1][j] - arr[n / 2][j]);
      y += (arr[0][j] - arr[n - 1][j]) * (arr[0][j] - arr[n - 1][j]);
    }
    if(y < x) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}