#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 5005
#define INF 1000000000

using namespace std;

int in[SIZE];
int bad[SIZE];
int dp[SIZE];

int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int ret=0;
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<m;i++) scanf("%d",&bad[i]);
	for(int i=0;i<n;i++)
	{
		int now=in[i],pos=0;
		for(int j=2;j*j<=now;j++)
		{
			if(now%j==0)
			{
				int cnt=0;
				while(now%j==0)
				{
					now/=j;
					cnt++;
				}
				while(pos<m&&bad[pos]<j) pos++;
				if(pos<m&&bad[pos]==j) ret-=cnt;
				else ret+=cnt;
			}
		}
		if(now!=1)
		{
			while(pos<m&&bad[pos]<now) pos++;
			if(pos<m&&bad[pos]==now) ret--;
			else ret++;
		}
	}
	int gd=0;
	for(int i=0;i<n;i++)
	{
		gd=gcd(gd,in[i]);
		int now=gd,pos=0;
		int sum=0;
		for(int j=2;j*j<=now;j++)
		{
			if(now%j==0)
			{
				int cnt=0;
				while(now%j==0)
				{
					now/=j;
					cnt++;
				}
				while(pos<m&&bad[pos]<j) pos++;
				if(pos<m&&bad[pos]==j) sum-=cnt;
				else sum+=cnt;
			}
		}
		if(now!=1)
		{
			while(pos<m&&bad[pos]<now) pos++;
			if(pos<m&&bad[pos]==now) sum--;
			else sum++;
		}
		for(int j=i+1;j>0;j--) dp[j]=dp[j-1];
		dp[0]=-INF;
		for(int j=i+1;j>0;j--) dp[0]=max(dp[0],dp[j]-j*sum);
	}
	int mx=-INF;
	for(int j=0;j<=n;j++) mx=max(mx,dp[j]);
	printf("%d\n",mx+ret);
	return 0;
}