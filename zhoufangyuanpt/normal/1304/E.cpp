#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,next;
}a[210000];int len,last[110000];
inline void ins(int x,int y)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int n,fa[110000],dep[110000],son[110000],tot[110000];
void dfs(int x)
{
	tot[x]=1;son[x]=0;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa[x])
		{
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
			if(tot[son[x]]<tot[y])son[x]=y;
			tot[x]+=tot[y];
		}
	}
}
int top[110000];
void dfs(int x,int tp)
{
	top[x]=tp;
	if(son[x]!=0)dfs(son[x],tp);
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa[x]&&y!=son[x])dfs(y,y);
	}
}
int solve(int x,int y)
{
    int tx=top[x],ty=top[y];
    while(tx!=ty)
    {
        if(dep[tx]>dep[ty])
        {
            tx^=ty^=tx^=ty;
            x^=y^=x^=y;
        }
        y=fa[ty];ty=top[y];
    }
    if(dep[x]>dep[y])x^=y^=x^=y;
	return x;
}
inline int dis(int x,int y){return dep[x]+dep[y]-2*dep[solve(x,y)];}
int main()
{
	int n;scanf("%d",&n);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	fa[1]=0;dep[1]=1;dfs(1);dfs(1,1);
	int t;scanf("%d",&t);
	while(t--)
	{
		int x,y,a,b,k;scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		int ab=dis(a,b);
		if(ab<=k&&ab%2==k%2)
		{
			puts("YES");
		}
		else
		{
			int xy=dis(x,y);
			if(ab%2==k%2)
			{
				if(xy%2==0)puts("NO");
				else
				{
					ab=min(dis(a,x)+dis(y,b),dis(a,y)+dis(x,b))+1;
					if(ab<=k)puts("YES");
					else puts("NO");
				}
			}
			else
			{
				if(xy%2==1)puts("NO");
				else
				{
					ab=min(dis(a,x)+dis(y,b),dis(a,y)+dis(x,b))+1;
					if(ab<=k)puts("YES");
					else puts("NO");
				}
			}
		}
	}
	return 0;
}