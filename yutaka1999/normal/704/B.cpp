#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <iostream>
#include <string>
#include <cmath>
#define SIZE 5005
#define INF 1000000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll dp[2][SIZE];
ll X[SIZE],A[SIZE],B[SIZE],C[SIZE],D[SIZE];
int n;

void fill(int pos)
{
	for(int i=0;i<=n;i++)
	{
		dp[pos][i]=INF;
	}
}
int main()
{
	int s,e;
	scanf("%d %d %d",&n,&s,&e);s--,e--;
	for(int i=0;i<n;i++) scanf("%lld",&X[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		A[i]+=X[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&B[i]);
		B[i]-=X[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&C[i]);
		C[i]+=X[i];
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&D[i]);
		D[i]-=X[i];
	}
	int pos=0;
	fill(pos);
	if(s==0) dp[pos][0]=D[0];
	else if(e==0) dp[pos][0]=B[0];
	else dp[pos][1]=B[0]+D[0];
	ll ret=INF;
	for(int i=1;i<n;i++)
	{
		pos^=1;
		fill(pos);
		for(int j=0;j<=n;j++)
		{
			if(dp[pos^1][j]>=INF) continue;
			if(i==s)
			{
				dp[pos][j]=min(dp[pos][j],dp[pos^1][j]+D[i]);
				if(j>0) dp[pos][j-1]=min(dp[pos][j-1],dp[pos^1][j]+C[i]);
				else if(i==n-1) ret=min(ret,dp[pos^1][j]+C[i]);
			}
			else if(i==e)
			{
				dp[pos][j]=min(dp[pos][j],dp[pos^1][j]+B[i]);
				if(j>0) dp[pos][j-1]=min(dp[pos][j-1],dp[pos^1][j]+A[i]);
				else if(i==n-1) ret=min(ret,dp[pos^1][j]+A[i]);
			}
			else
			{
				int in=j+(s<i?1:0);
				int out=j+(e<i?1:0);
				if(in>0) dp[pos][j]=min(dp[pos][j],dp[pos^1][j]+A[i]+D[i]);
				if(out>0) dp[pos][j]=min(dp[pos][j],dp[pos^1][j]+B[i]+C[i]);
				if(in>=2||out>=2) dp[pos][j-1]=min(dp[pos][j-1],dp[pos^1][j]+A[i]+C[i]);
				if(j==0&&i==n-1) ret=min(ret,dp[pos^1][j]+A[i]+C[i]);
				dp[pos][j+1]=min(dp[pos][j+1],dp[pos^1][j]+B[i]+D[i]);
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}