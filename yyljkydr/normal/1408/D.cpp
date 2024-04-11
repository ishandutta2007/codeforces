#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,m;

struct P{
	int x,y;
}p[N],q[N];

bool cmp(P a,P b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

int c[N],mx[N],g[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&q[i].x,&q[i].y);
	for(int i=0;i<=1000000;i++)
		g[i]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(q[j].x<p[i].x||q[j].y<p[i].y)
				continue;
			g[q[j].x-p[i].x]=max(g[q[j].x-p[i].x],q[j].y-p[i].y);
		}
	}
	int mx=0;
	int ans=0x7fffffff;
	for(int i=1000000;i>=0;i--)
	{
		mx=max(mx,g[i]+1);
		ans=min(ans,i+mx);
	}
	printf("%d\n",ans);
}