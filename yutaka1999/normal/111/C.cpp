#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 45
#define BT 1<<13
#define INF 1000000000

using namespace std;
template <class T> void chmax(T&a,T b){a=max(a,b);}

int dp[2][BT];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n>m) swap(n,m);
	int pos=0;
	memset(dp[pos],-1,sizeof(dp[pos]));
	dp[pos][0]=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			pos^=1;
			memset(dp[pos],-1,sizeof(dp[pos]));
			for(int S=0;S<1<<(2*n);S++)
			{
				if(dp[pos^1][S]==-1) continue;
				int T=S<<1;
				if(T>>(2*n)&1) T-=1<<(2*n);
				chmax(dp[pos][T|1<<n],dp[pos^1][S]+(S>>(n-1)&1));
				if(i!=m-1) chmax(dp[pos][T|1],dp[pos^1][S]);
				if(i!=0) chmax(dp[pos][T],dp[pos^1][S]+(S>>(2*n-1)&1));
				if(j!=n-1) chmax(dp[pos][T|1<<(n-1)],dp[pos^1][S]+(S>>(n-2)&1));
				if(j!=0) chmax(dp[pos][T|1<<(n+1)],dp[pos^1][S]+(S>>n&1));
			}
		}
	}
	int ret=0;
	for(int S=0;S<1<<(2*n);S++) ret=max(ret,dp[pos][S]);
	printf("%d\n",ret);
	return 0;
}