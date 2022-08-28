#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 205
#define INF 1000000000
#define LIM 1000000000000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int tm[SIZE];
int ans[SIZE];
ll dp[2][SIZE];
int n,m,all;
ll k;

void pl(ll&a,ll b)//a+=b
{
	if(a+b>k) a=k+1;
	else a+=b;
}
ll calc()
{
	int pos=0;
	memset(dp,0,sizeof(dp));
	dp[pos][0]=1;
	for(int i=0;i<all;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int j=0;j<SIZE;j++)
		{
			if(j<SIZE-1&&ans[i]<=0) pl(dp[pos][j],dp[pos^1][j+1]);
			if(j>0&&ans[i]>=0) pl(dp[pos][j],dp[pos^1][j-1]);
		}
	}
	return dp[pos][0];
}
int main()
{
	scanf("%d %d %llld",&n,&m,&k);
	all=n+m-1;
	for(int i=0;i<all;i++) tm[i]=INF;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a;
			scanf("%d",&a);
			tm[i+j]=min(tm[i+j],a);
		}
	}
	for(int i=0;i<all;i++)
	{
		int now=INF,p;
		for(int j=0;j<all;j++)
		{
			if(now>tm[j])
			{
				now=tm[j];
				p=j;
			}
		}
		tm[p]=INF;
		ans[p]=1;
		ll val=calc();
		if(val<k)
		{
			k-=val;
			ans[p]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ans[i+j]==-1) printf(")");
			else if(ans[i+j]==1) printf("(");
		}
		puts("");
	}
	return 0;
}