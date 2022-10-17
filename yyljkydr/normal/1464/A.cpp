#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,fa[N],sz[N],sze[N],m;

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			fa[i]=i,sze[i]=0,sz[i]=1;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==y)
				continue;
			int fx=find(x),fy=find(y);
			if(fx==fy)
				sze[fx]++;
			else
			{
				sze[fx]+=sze[fy]+1;
				sz[fx]+=sz[fy];
				fa[fy]=fx;
			}
		} 
		int ans=0;
		for(int i=1;i<=n;i++)
			if(fa[i]==i)
			{
				ans+=sz[i]-1+(sze[i]-sz[i]+1)*2;
			}
		printf("%d\n",ans);
	}
}