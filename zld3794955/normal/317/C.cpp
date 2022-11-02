#include<bits/stdc++.h>
using namespace std;
const int N=303,M=50050,T=2*N*N;
int n,m,e,a[N]={},b[N]={},last[N]={},next[M+M]={},end[M+M]={},total_edge=0;
int w[N]={},len=0,vis[N]={},now=0,u[T]={},v[T]={},d[T]={},tot=0;
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=1,u,v;i<=e;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
}
bool get_way(int s)
{
	if(vis[s]==now)
		return false;
	vis[s]=now;
	w[++len]=s;
	if(a[s]>b[s])
		return true;
	for(int i=last[s];i;i=next[i])
		if(get_way(end[i]))
			return true;
	--len;
	return false;
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		while(a[i]<b[i])
		{
			len=0,++now;
			get_way(i);
			if(len==0)
			{
				puts("NO");
				return;
			}
			int amount=min(b[i]-a[i],a[w[len]]-b[w[len]]);
			int d1=amount/2,d2=amount-d1;
			bool flag=true,t[N]={};
			while(flag)
			{
				flag=false;
				for(int j=2;j<=len;++j)
					if(!t[w[j]] && a[w[j]]>=d1)
					{
						++tot,u[tot]=w[j],v[tot]=w[j-1],d[tot]=d1;
						a[w[j]]-=d1,a[w[j-1]]+=d1;
						t[w[j]]=true;
						flag=true;
					}
			}
			flag=true;
			fill(t,t+N,false);
			while(flag)
			{
				flag=false;
				for(int j=2;j<=len;++j)
					if(!t[w[j]] && a[w[j]]>=d2)
					{
						++tot,u[tot]=w[j],v[tot]=w[j-1],d[tot]=d2;
						a[w[j]]-=d2,a[w[j-1]]+=d2;
						t[w[j]]=true;
						flag=true;
					}
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(a[i]!=b[i])
		{
			puts("NO");
			return;
		}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)
		printf("%d %d %d\n",u[i],v[i],d[i]);
}
int main()
{	
	init();
	work();
	return 0;
}