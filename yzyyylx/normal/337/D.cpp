#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100100
using namespace std;

int n,m,d,deep[4][N],num[N],bb,first[N],ans;
struct Bn
{
	int to,next;
}bn[N*2];

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void dfs(int u,int now,int last)
{
	int p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		deep[u][bn[p].to]=deep[u][now]+1;
		dfs(u,bn[p].to,now);
	}
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,j,p,q,mm,mx;
	cin>>n>>m>>d;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		add(p,q);
		add(q,p);
	}
	dfs(1,1,-1);
	mx=0;
	for(i=1;i<=m;i++)
	{
		if(deep[1][num[i]]>mx)
		{
			mx=deep[1][num[i]];
			mm=num[i];
		}
	}
	dfs(2,mm,-1);
	mx=0;
	for(i=1;i<=m;i++)
	{
		if(deep[2][num[i]]>mx)
		{
			mx=deep[2][num[i]];
			mm=num[i];
		}
	}
	dfs(3,mm,-1);
	for(i=1;i<=n;i++)
	{
		if(deep[2][i]<=d&&deep[3][i]<=d)
		{
			ans++;
		}
	}
	cout<<ans;
}