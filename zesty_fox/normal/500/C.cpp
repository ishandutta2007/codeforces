#include<cstdio>
#include<cstring>
using namespace std;
int n,m,w[501],p[1001],vis[501],ans,i,j;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
		
	for(i=1;i<=m;i++)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&p[i]);
		for(j=i-1;j>0&&p[i]!=p[j];j--)
		{
			if(!vis[p[j]])
			{
				vis[p[j]]=1;
				ans+=w[p[j]];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}