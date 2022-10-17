#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300100
using namespace std;

int bb,n,m,fa[N],size[N],ans[N],first[N];
struct Bn
{
	int to,next;
}bn[N];

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void dfs(register int now)
{
	register int p,q;
	size[now]=1;
	ans[now]=now;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		dfs(bn[p].to);
		size[now]+=size[bn[p].to];
	}
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(( size[bn[p].to]<<1 )>size[now])
		{
			ans[now]=ans[bn[p].to];
			break;
		}
	}
	for(;((size[now]-size[ans[now]])<<1)>size[now];ans[now]=fa[ans[now]]);
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,p;
	cin>>n>>m;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	dfs(1);
//	for(i=1;i<=n;i++) cout<<size[i]<<" ";
	for(i=1;i<=m;i++)
	{
		scanf("%d",&p);
		printf("%d\n",ans[p]);
	}
}