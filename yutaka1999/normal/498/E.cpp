#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE (1<<7)
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll cnt[SIZE][SIZE];
ll dp[SIZE][SIZE];
ll cur[SIZE][SIZE];
ll way[2][SIZE];

void dfs(int w,int bit)
{
	if(w==0)
	{
		for(int S=0;S<bit;S++)
		{
			for(int T=0;T<bit;T++)
			{
				dp[S][T]=S==T;
			}
		}
		return;
	}
	dfs(w/2,bit);
	for(int S=0;S<bit;S++)
	{
		for(int T=0;T<bit;T++)
		{
			cur[S][T]=0;
			for(int i=0;i<bit;i++)
			{
				cur[S][T]+=dp[S][i]*dp[i][T]%MOD;
				if(cur[S][T]>=MOD) cur[S][T]-=MOD;
			}
		}
	}
	for(int S=0;S<bit;S++)
	{
		for(int T=0;T<bit;T++)
		{
			dp[S][T]=cur[S][T];
		}
	}
	if(w%2==1)
	{
		for(int S=0;S<bit;S++)
		{
			for(int T=0;T<bit;T++)
			{
				cur[S][T]=0;
				for(int i=0;i<bit;i++)
				{
					cur[S][T]+=dp[S][i]*cnt[i][T]%MOD;
					if(cur[S][T]>=MOD) cur[S][T]-=MOD;
				}
			}
		}
		for(int S=0;S<bit;S++)
		{
			for(int T=0;T<bit;T++)
			{
				dp[S][T]=cur[S][T];
			}
		}
	}/*
	if(bit==4)
	{
		printf("%d\n",w);
		for(int S=0;S<bit;S++)
		{
			for(int T=0;T<bit;T++)
			{
				printf("[%d %d] %d\n",S,T,dp[S][T]);
			}
		}
	}*/
}
int main()
{
	memset(way,0,sizeof(way));
	int pos=0;
	way[pos][0]=1;
	for(int i=0;i<7;i++)
	{
		int w;
		scanf("%d",&w);
		int bit=1<<(i+1);
		for(int S=0;S<bit;S++)
		{
			for(int T=0;T<bit;T++)
			{
				int a=1,b=0;//a:exist,b:not exist
				for(int j=0;j<=i;j++)
				{
					int na=0,nb=a+b;
					if(nb>=MOD) nb-=MOD;
					na=b;
					if(!(S>>j&1)||!(T>>j&1))
					{
						na+=a;
						if(na>=MOD) na-=MOD;
					}
					a=na;b=nb;
				}
				cnt[S][T]=a;
				//if(i==1) printf("%d %d %d\n",S,T,a);
			}
		}
		dfs(w,bit);
		pos^=1;
		memset(way[pos],0,sizeof(way[pos]));
		for(int S=0;S<1<<i;S++)
		{
			for(int T=0;T<1<<(i+1);T++)
			{
				way[pos][T]+=way[pos^1][S]*dp[(S<<1)|1][T]%MOD;
				if(way[pos][T]>=MOD) way[pos][T]-=MOD;
			}
		}
	}
	printf("%I64d\n",way[pos][(1<<7)-1]);
	return 0;
}