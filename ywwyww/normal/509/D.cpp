#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
ll a[110],b[110];
ll v[110][110];
ll c[110][110];
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%I64d",&v[i][j]);
	a[1]=0;
	for(i=1;i<=m;i++)
		b[i]=v[1][i]-a[1];
	for(i=2;i<=n;i++)
		a[i]=v[i][1]-b[1];
	ll p=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			c[i][j]=abs(a[i]+b[j]-v[i][j]);
			p=gcd(p,c[i][j]);
		}
	if(!p)
		p=1000000007;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(p<=v[i][j])
			{
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	printf("%I64d\n",p);
	for(i=1;i<=n;i++)
	{
		a[i]=(a[i]%p+p)%p;
		printf("%I64d ",a[i]);
	}
	printf("\n");
	for(i=1;i<=m;i++)
	{
		b[i]=(b[i]%p+p)%p;
		printf("%I64d ",b[i]);
	}
	return 0;
}