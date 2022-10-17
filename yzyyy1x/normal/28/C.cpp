#include<bits/stdc++.h>
#define db double
#define ll long long
using namespace std;
const int N=55;
int n,m,a[N],tax[N];ll c[N][N];
db dp[N][N][N],ans=0;
ll C(int x,int y)
{return c[x][y];}
db qpow(db x,ll y)
{
	db res=1.0;
	while(y)
	{
		if(y&1)res=res*x;
		x=x*x,y>>=1;
	}
	return res;
}
db gl(int x,int a,int y)
{return 1.0*C(x,a)/qpow(y,a)*qpow(y-1,x-a)/qpow(y,x-a);}
int gcd(int x,int y)
{return !y?x:gcd(y,x%y);}
void init()
{
	ll nw;int tp,g;
	for(int i=0;i<=50;i++)
	{
		for(int j=i;j>=0;j--)
		{
			if(c[i][i-j]!=0)c[i][j]=c[i][i-j];
			else
			{
				nw=1;
				for(int k=1;k<=i-j;k++)tax[k]=k;
				for(int k=i;k>j;k--)
				{
					tp=k;
					for(int x=1;x<=i-j;x++)
					{
						if(tax[x]!=1)
						{
							g=gcd(tp,tax[x]);
							tp/=g,tax[x]/=g;
						}
					}
					nw=nw*tp;
				}
				c[i][j]=nw;
			}
		}
	}
}
int main()
{
	int las;
	init();
	scanf("%d%d",&n,&m),swap(n,m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[0][0][0]=1.0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(dp[i-1][j][k])
				{
					las=m-k;
					for(int nx=0;nx<=las;nx++)
					{
						dp[i][max(j,nx/a[i]+(nx%a[i]?1:0))][k+nx]+=dp[i-1][j][k]*gl(las,nx,n-i+1);
					}
				}
			}
		}
	}
	for(int i=0;i<=m;i++)
		ans+=dp[n][i][m]*i;
	printf("%.10lf",ans);
}