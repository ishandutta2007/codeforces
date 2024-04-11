#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std; 

typedef long long ll;

const int N=3e3+1e2+7;

int n,m,a,b;

ll h[N][N],g[N*N],x,y,z,mn[N][N];

ll q[N],head,tail;

int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	scanf("%lld%lld%lld%lld",&g[0],&x,&y,&z);
	for(int i=1;i<n*m;i++)
		g[i]=(g[i-1]*x+y)%z;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			h[i][j]=g[(i-1)*m+j-1];
	for(int j=1;j<=m;j++)
	{
		memset(q,0,sizeof(q)); 
		head=1,tail=0;
		for(int i=1;i<a;i++)
		{
			while(h[q[tail]][j]>=h[i][j]&&tail>=head)
				tail--;
			q[++tail]=i;
		}
		for(int i=a;i<=n;i++)
		{
			while(h[q[tail]][j]>=h[i][j]&&tail>=head)
				tail--;
			q[++tail]=i;
			mn[i-a+1][j]=h[q[head]][j];
			while(q[head]<=i-a+1&&head<=tail)
				head++;
		}
	}
	ll ans=0;
	for(int i=1;i<=n-a+1;i++)
	{
		memset(q,0,sizeof(q));
		head=1,tail=0;
		for(int j=1;j<b;j++)
		{
			while(mn[i][q[tail]]>=mn[i][j]&&tail>=head)
				tail--;
			q[++tail]=j;
		}
		for(int j=b;j<=m;j++)
		{
			while(mn[i][q[tail]]>=mn[i][j]&&tail>=head)
				tail--;
			q[++tail]=j;
			ans+=mn[i][q[head]];
			while(q[head]<=j-b+1&&head<=tail)
				head++;
		}
	}
	printf("%lld",ans);
}