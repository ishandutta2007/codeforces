#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 510
#define M 
using namespace std;

ll m,n,a[N][N],b[N][N];

int main()
{
	ll i,j,t;
	cin>>m>>n;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&b[i][j]);
		}
	}
	for(i=1;i<=m;i++)
	{
		ll t=0;
		for(j=1;j<=n;j++)
		{
			t+=a[i][j];
			t-=b[i][j];
		}
		if(t%2)
		{
			puts("No");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		ll t=0;
		for(j=1;j<=m;j++)
		{
			t+=a[j][i];
			t-=b[j][i];
		}
		if(t%2)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}