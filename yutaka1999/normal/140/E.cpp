#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005
#define MX 1000005

using namespace std;
typedef long long int ll;

ll n,m,MOD;
ll dp[SIZE];
int way[SIZE][SIZE];
int way2[SIZE][SIZE];

void make()
{
	for(int i=1;i<SIZE;i++)
	{
		way[i][1]=(i==1?1:0);
		for(int j=2;j<=i;j++)
		{
			ll vl=((ll) way[i-1][j-1]*(ll) j%MOD+(ll) way[i-1][j]*(ll) (j-1)%MOD);
			if(vl>=MOD) vl-=MOD;
			way[i][j]=(int) vl;
		}
	}
	for(int i=1;i<SIZE;i++)
	{
		way2[i][1]=(i==1?m:0);
		for(int j=2;j<=i;j++)
		{
			ll vl=(way2[i-1][j-1]*(ll) (m-j+1)%MOD+way2[i-1][j]*(ll) (j-1)%MOD);
			if(vl>=MOD) vl-=MOD;
			way2[i][j]=(int) vl;
		}
	}
}
int main()
{
	scanf("%lld %lld %lld",&n,&m,&MOD);
	make();
	int bef=0;
	memset(dp,0,sizeof(dp));
	ll all=1;
	int back=0;
	for(int i=0;i<n;i++)
	{
		int L;
		scanf("%d",&L);
		for(int j=1;j<=L;j++)
		{
			ll now=all*(ll) way2[L][j]%MOD;
			now-=dp[j]*(ll) way[L][j]%MOD;
			if(now<0) now+=MOD;
			dp[j]=now;
		}
		for(int j=L+1;j<=back;j++) dp[j]=0;back=L;
		//for(int j=1;j<=L;j++) printf("%lld ",dp[j]);puts("");
		all=0;
		for(int j=1;j<=L;j++)
		{
			all+=dp[j];
			if(all>=MOD) all-=MOD;
		}
	}
	printf("%lld\n",all);
	return 0;
}