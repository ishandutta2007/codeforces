#include<iostream>
#include<cstdio>
#include<cmath>
#define N 100100
using namespace std;

int n,m,num[N],s,cs[N],to[N],be[N],ans;

inline void get(int u)
{
	if(u+num[u]>n)
	{
		to[u]=-1;
		cs[u]=1;
	}
	else if(be[u]!=be[u+num[u]] || to[u+num[u]]==-1)
	{
		to[u]=u+num[u];
		cs[u]=1;
	}
	else
	{
		to[u]=to[u+num[u]];
		cs[u]=cs[u+num[u]]+1;
	}
}

int main()
{
	int i,j,o,p,q;
	cin>>n>>m;
	s=sqrt(n);
	for(i=1;i<=n;i++)
		be[i]=i/s+1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=n;i>=1;i--)
		get(i);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&o);
		if(!o)
		{
			scanf("%d%d",&p,&q);
			num[p]=q;
			for(j=p;be[j]==be[p];j--) get(j);
		}
		else
		{
			scanf("%d",&p);
			ans=0;
			for(;to[p]!=-1;p=to[p])
			{
				ans+=cs[p];
			}
			printf("%d %d\n",p,ans+1);
		}
	}
}