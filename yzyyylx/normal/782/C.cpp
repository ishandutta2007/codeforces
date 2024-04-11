#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 200100
using namespace std;

int n,m,bb,ds[N],first[N],ans,an[N],fa[N];
struct Bn
{
	int to,next;
}bn[N*2];
set<int>col;

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void dfs(int now,int last)
{
	int p,q=1;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		for(;q==an[now]||q==an[fa[now]];q++);
		fa[bn[p].to]=now;
		an[bn[p].to]=q++;
	}
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		dfs(bn[p].to,now);
	}
}

int main()
{
	memset(first,-1,sizeof(first));
	register int i,j,p,q;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		add(p,q);
		add(q,p);
		ds[p]++,ds[q]++;
	}
	for(i=1;i<=n;i++)
	{
		ans=max(ans,ds[i]);
	}
	ans++;
	cout<<ans<<endl;
	an[1]=1;
	dfs(1,-1);
	for(i=1;i<=n;i++)
	{
		printf("%d ",an[i]);
	}
}