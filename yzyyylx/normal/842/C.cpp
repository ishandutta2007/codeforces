#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200100
using namespace std;

int n,m,dn[N],bb,first[N],g[N],deep[N],cnt[N],ans[N];
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

inline int fj(int u,int v)
{
	int i,res=1;
	cnt[u]++;
	if(cnt[u]>=v) res=u;
	for(i=2;i*i<=u;i++)
	{
		if(u%i==0)
		{
			cnt[i]++;
			if(cnt[i]>=v) res=max(res,i);
			if(i*i!=u)
			{
				cnt[u/i]++;
				if(cnt[u/i]>=v) res=max(res,u/i);
			}
		}
	}
	return res;
}

inline void ffj(int u)
{
	int i;
	cnt[u]--;
	for(i=2;i*i<=u;i++)
	{
		if(u%i==0)
		{
			cnt[i]--;
			if(i*i!=u)
			{
				cnt[u/i]--;
			}
		}
	}
}

inline int gcd(int u,int v)
{
	if(u<v) swap(u,v);
	for(;u!=v&&u&&v;swap(u,v))
	{
		u%=v;
	}
	return max(u,v);
}

void dfs(int now,int last)
{
	int p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		deep[bn[p].to]=deep[now]+1;
		g[bn[p].to]=gcd(dn[bn[p].to],g[now]);
		
		ans[bn[p].to]=fj(dn[bn[p].to],deep[now]);
		ans[bn[p].to]=max(ans[bn[p].to],g[now]);
		dfs(bn[p].to,now);
		ffj(dn[bn[p].to]);
	}
}

int main()
{
	memset(first,-1,sizeof(first));
	register int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&dn[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		add(p,q);
		add(q,p);
	}
	deep[1]=1;
	g[1]=ans[1]=dn[1];
	fj(dn[1],1);
	dfs(1,-1);
	for(i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
}