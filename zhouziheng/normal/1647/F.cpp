#include<cstdio>
#include<algorithm>

using namespace std;

const int INF=1e9+1;

int a[1000000],f[1000000][2],g[1000000],h[1000000];

int main()
{
	int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int k=1;for(int i=2;i<=n;i++)if(a[i]>a[k])k=i;
	f[0][0]=f[n+1][1]=-INF,a[0]=a[n+1]=-INF;
	for(int i=1;i<=k;i++)
	{
		f[i][0]=INF;
		if(a[i]>f[i-1][0])f[i][0]=min(f[i][0],a[i-1]);
		if(a[i]>a[i-1])f[i][0]=min(f[i][0],f[i-1][0]);
	}
	for(int i=n;i>=k;i--)
	{
		f[i][1]=INF;
		if(a[i]>f[i+1][1])f[i][1]=min(f[i][1],a[i+1]);
		if(a[i]>a[i+1])f[i][1]=min(f[i][1],f[i+1][1]);
	}
	//for(int i=1;i<=k;i++)printf("%d ",f[i][0]);puts("");
	//for(int i=k;i<=n;i++)printf("%d ",f[i][1]);puts("");
	
	int ans=0;
	g[k]=-INF,h[k]=f[k][1];
	for(int i=k-1;i>=1;i--)
	{
		g[i]=-INF,h[i]=INF;
		if(a[i]<a[i+1])h[i]=min(h[i],h[i+1]);
		if(a[i]>h[i+1])g[i]=max(g[i],a[i+1]);
		if(a[i]>a[i+1])g[i]=max(g[i],g[i+1]);
		if(a[i]<g[i+1])h[i]=min(h[i],a[i+1]);
		if(g[i]>f[i][0])ans++;
	}
	g[k]=-INF,h[k]=f[k][0];
	for(int i=k+1;i<=n;i++)
	{
		g[i]=-INF,h[i]=INF;
		if(a[i]<a[i-1])h[i]=min(h[i],h[i-1]);
		if(a[i]>h[i-1])g[i]=max(g[i],a[i-1]);
		if(a[i]>a[i-1])g[i]=max(g[i],g[i-1]);
		if(a[i]<g[i-1])h[i]=min(h[i],a[i-1]);
		if(g[i]>f[i][1])ans++;
	}
	printf("%d",ans);
}