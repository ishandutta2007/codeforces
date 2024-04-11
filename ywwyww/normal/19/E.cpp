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
struct graph
{
	int h[2000010];
	int v[4000010];
	int w[4000010];
	int t[4000010];
	int n;
	graph()
	{
		memset(h,0,sizeof h);
		n=0;
	}
	void add(int x,int y,int z)
	{
		n++;
		v[n]=y;
		w[n]=z;
		t[n]=h[x];
		h[x]=n;
	}
};
graph l;
int f[2000010];
int g[2000010];
int d[2000010];
int id[2000010];
int dfn[2000010];
int b[2000010];
int ti;
int cnt=0;
int ans2;
int op(int x)
{
	return ((x-1)^1)+1;
}
void dfs(int x,int fa,int w,int dep)
{
	b[x]=1;
	dfn[x]=++ti;
	d[x]=dep;
	id[x]=w;
	int i;
	for(i=l.h[x];i;i=l.t[i])
		if(i!=op(fa))
		{
			int v=l.v[i];
			if(b[v])
			{
				if(dfn[v]>=dfn[x])
				{
					if((d[v]-d[x])&1)
						g[x]--;
					else
						f[x]--;
				}
				else 
				{
					if((d[x]-d[v])&1)
						g[x]++;
					else
					{
						f[x]++;
						cnt++;
						ans2=l.w[i];
					}
				}
			}
			else
			{
				dfs(v,i,l.w[i],dep+1);
				g[x]+=g[v];
				f[x]+=f[v];
			}
		}
}
int n,m;
int ans[2000010];
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		l.add(x,y,i);
		l.add(y,x,i);
	}
	for(i=1;i<=n;i++)
		if(!b[i])
			dfs(i,0,0,1);
	if(!cnt)
	{
		printf("%d\n",m);
		for(i=1;i<=m;i++)
			printf("%d ",i);
		return 0;
	}
	int num=0;
	for(i=1;i<=n;i++)
		if(f[i]==cnt&&!g[i]&&id[i])
		{
			ans[id[i]]=1;
			num++;
		}
	if(cnt==1)
	{
		num++;
		ans[ans2]=1;
	}
	printf("%d\n",num);
	for(i=1;i<=m;i++)
		if(ans[i])
			printf("%d ",i);
	return 0;
}