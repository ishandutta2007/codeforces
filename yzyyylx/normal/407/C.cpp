#include<iostream>
#include<cstdio>
#define ll long long
#define N 100100
#define M 1000000007
#define MN 100000
#define T 102
using namespace std;

ll n,m,cf[110][N],C[N][110],num[N];

inline void get()
{
	ll i,j;
	for(i=0;i<=MN;i++)
	{
		C[i][0]=1;
		if(i<=T) C[i][i]=1;
		for(j=1;j<=min(i,(ll)T);j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
		}
	}
}

int main()
{
//	freopen("sequence2.in","r",stdin);
//	freopen("sequence2.out","w",stdout);
	ll i,j,k,t,p,q,o,tmp;
	get();
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	while(m--)
	{
		scanf("%lld%lld%lld",&p,&q,&o);
		t=p;
		for(j=1,k=o;j<=T+1&&t<=n+1&&k>=0;j++,k--,t++)
		{
			cf[j][t]=(cf[j][t]+C[o][k])%M;
		}
		t=q+1;
		for(j=1,k=o,o+=q-p+1;j<=T+1&&t<=n+1&&k>=0;j++,k--,t++)
		{
			cf[j][t]=(cf[j][t]-C[o][k]+M)%M;
		}
	}
	/*
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<cf[i][j]<<" ";
		}
		puts("");
	}
	//*/
	for(i=T;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			cf[i][j]=(cf[i][j]+cf[i][j-1]+cf[i+1][j])%M;
		}
	}
	/*
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<cf[i][j]<<" ";
		}
		puts("");
	}
	//*/
	for(i=1;i<=n;i++) printf("%lld ",(cf[1][i]+num[i])%M);
}