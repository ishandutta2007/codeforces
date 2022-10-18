#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

vector<int> g[10005];

int main()
{
  int n, x, y;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
    scanf("%d %d", &x, &y);
    g[x].pb(y);
    g[y].pb(x);
  }
  LL ans = 0;
  for(int i=1;i<=n;i++)
  {
    for(int x : g[i])
      ans += g[x].size() - 1;
  }
  cout << ans / 2;
  return 0;
}