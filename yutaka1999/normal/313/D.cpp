#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#define SIZE 305
#define MM 100005
#define INF 10000000000000000LL

using namespace std;
typedef long long int ll;
typedef short int ss;
typedef pair <int,int> P;
typedef pair <ll,P> PP;
template <class T> void chmin(T&a,T b){a=min(a,b);}

ll cost[SIZE][SIZE];
ll dp[SIZE][SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=n;i++)
	{
 		for(int j=0;j<=k;j++) dp[i][j]=INF;
		for(int j=0;j<=n;j++) cost[i][j]=INF;
	}
	for(int i=0;i<m;i++)
	{
		int l,r,c;
		scanf("%d %d %d",&l,&r,&c);
		for(int j=l;j<=r;j++) chmin(cost[l][j],(ll) c);
	}
	dp[0][0]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=k;j>=0;j--)
		{
			chmin(dp[i+1][j],dp[i][j]);
			if(j<k) chmin(dp[i][j],dp[i][j+1]);
			for(int to=i+1;to<=n;to++)
			{
				int hm=j+(to-i);
				chmin(hm,k);
				chmin(dp[to][hm],dp[i][j]+cost[i+1][to]);
			}
		}
	}
	if(dp[n][k]==INF) puts("-1");
	else printf("%I64d\n",dp[n][k]);
	return 0;
}
/*
10 6 9
6 8 7
2 8 11
2 6 10
8 10 9
2 5 8
2 3 8

[ans]
20
*/