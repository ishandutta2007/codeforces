#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int x,y,c,next;
}a[2100];int len,last[1100];
inline void ins(int x,int y)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
bool b[1100];
int xx,xd;
void dfs(int x,int fa,int dep)
{
	if(!b[x])return ;
	if(dep>xd)xx=x,xd=dep;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)dfs(y,x,dep+1);
	}
}
int yy,yd,f[1100];
void dfs(int x,int dep)
{
	if(!b[x])return ;
	if(dep>yd)yy=x,yd=dep;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=f[x])
		{
			f[y]=x;
			dfs(y,dep+1);
		}
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	memset(b,true,sizeof(b));
	int lca=1;
	while(true)
	{
		xd=0;dfs(lca,0,1);
		memset(f,0,sizeof(f));
		yd=0;dfs(xx,1);
		if(xx==yy)
		{
			printf("! %d\n",xx);
			return 0;
		}
		printf("? %d %d\n",xx,yy);
		fflush(stdout);
		scanf("%d",&lca);
		while(yy!=xx)
		{
			if(yy!=lca)b[yy]=false;
			yy=f[yy];
		}
		if(xx!=lca)b[xx]=false;
	}
	return 0;
}