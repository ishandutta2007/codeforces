#include<bits/stdc++.h>
using namespace std;
class network
{
	static const int N=12020,M=(N+2000*12)*2;
	int S,T,last[N],next[M],end[M],f[M],total_edge,dis[N],nlast[N];
	void add_edge(int u,int v,int flow)
	{
		next[++total_edge]=last[u];
		last[u]=total_edge;
		end[total_edge]=v;
		f[total_edge]=flow;
	}
	bool bfs()
	{
		static int q[N]={};
		int head=0,tail=0;
		bool v[N]={};
		q[++tail]=T,v[T]=true,dis[T]=0;
		while(head!=tail)
			for(int s=q[++head],i=last[s];i;i=next[i])
				if(f[i^1] && !v[end[i]])
					v[end[i]]=true,q[++tail]=end[i],dis[end[i]]=dis[s]+1;
		return v[S];
	}
	int dinic(int s,int flow)
	{
		if(s==T)
			return flow;
		int x=flow;
		for(int &i=nlast[s];i;i=next[i])
		{
			int j=end[i];
			if(f[i] && dis[s]==dis[j]+1)
			{
				int a=dinic(j,min(x,f[i]));
				f[i]-=a,f[i^1]+=a;
				if((x-=a)==0)
					return flow;
			}
		}
		return flow-x;
	}
	public:
	static const int Inf=1<<30;
	void clear(int size)
	{
		S=0,T=size+1;
		fill(last+S,last+T+1,0);
		total_edge=1;
	}
	int getS() { return S; }
	int getT() { return T; }
	void add(int u,int v,int f)
	{
		add_edge(u,v,f),add_edge(v,u,0);
	}
	int mincut()
	{
		int sum=0;
		while(bfs())
		{
			copy(last+S,last+T+1,nlast+S);
			sum+=dinic(S,Inf);
		}
		return sum;
	}
}G;
const int N=10010,M=2010,K=12;
int n,m,g,sex[N]={},ans;
int main()
{
	scanf("%d%d%d",&n,&m,&g);
	G.clear(n+m);
	for(int i=1;i<=n;++i)
		scanf("%d",sex+i);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		sex[i] ? G.add(G.getS(),i,x) : G.add(i,G.getT(),x);
	}
	for(int i=1,a,w,k,x;i<=m;++i)
	{
		scanf("%d%d%d",&a,&w,&k);
		ans+=w;
		while(k--)
		{
			scanf("%d",&x);
			a ? G.add(i+n,x,G.Inf) : G.add(x,i+n,G.Inf);
		}
		scanf("%d",&x);
		a ? G.add(G.getS(),i+n,w+x*g) : G.add(i+n,G.getT(),w+x*g);
	}
	printf("%d\n",ans-G.mincut());
	return 0;
}