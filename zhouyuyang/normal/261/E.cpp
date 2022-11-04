#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int l,r,n,i,j,k,ans;
int p[105],d[5000005],tot,cnt;
int f[5000005];
bool g[5000005];
void dfs(int x,int y)
{
	if(x>tot)
	{
		d[++cnt]=y;
		return;
	}
	for(;;)
	{
		dfs(x+1,y);
		if(r/p[x]<y)break;
		y*=p[x];
	}
}
int main()
{
	scanf("%d%d%d",&l,&r,&n);
	for(i=2;i<=n;++i)
	{
		for(j=2;j*j<=i;++j)if(i%j==0)break;
		if(j*j>i)p[++tot]=i;
	}
	dfs(1,1);
	sort(d+1,d+cnt+1);
	for(i=2;i<=cnt;++i)f[i]=10000;
	g[1]=true;
	for(i=2;i<=n;++i)
	{
		for(j=k=1;j<=cnt;++j)
		{
			if(d[cnt]/i<d[j])break;
			for(;d[k]<d[j]*i;++k);
			if(f[j]+1<f[k])f[k]=f[j]+1;
		}
		for(j=1;j<=cnt;++j)if(f[j]+i<=n)g[j]=true;
	}
	for(i=1;i<=cnt;++i)if(d[i]>=l&&d[i]<=r&&g[i])++ans;
	printf("%d\n",ans);
}