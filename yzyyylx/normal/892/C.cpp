#include<iostream>
#include<cstdio>
#define N 2010
using namespace std;

int n,dp[N][20],zero;

inline int gcd(int u,int v)
{
	for(;u&&v&&u!=v;)
	{
		u>v?u%=v:v%=u;
	}
	return max(u,v);
}

inline int log(int u)
{
	register int res;
	for(res=0;u;u>>=1,res++);
	return res-1;
}

inline int ask(int u,int v)
{
	int len=v-u+1;
	len=log(len);
	return gcd(dp[u][len],dp[v-(1 << len)+1][len]);
}

int main()
{
	register int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&dp[i][0]);
		zero+=(dp[i][0]==1);
	}
	if(zero)
	{
		printf("%d",n-zero);
		return 0;
	}
	for(i=1;(1 << i)<=n;i++)
	{
		for(j=1;j+(1 << i)-1<=n;j++)
		{
			dp[j][i]=gcd(dp[j][i-1],dp[j+(1 << (i-1))][i-1]);
		}
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j+i-1<=n;j++)
		{
			if(ask(j,i+j-1)==1)
			{
				printf("%d",n+i-2);
				return 0;
			}
		}
	}
	printf("-1");
}