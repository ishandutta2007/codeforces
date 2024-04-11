#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=20;
const int inf=1e9;
int n,m;
struct network_flow
{
	static const int maxn=400;
	static const int maxm=1600;
	int s,t;
	int head[maxn],cur[maxn],ver[maxm<<1],nxt[maxm<<1],val[maxm<<1],tot=1;
	void add(int x,int y,int z){ver[++tot]=y;val[tot]=z;nxt[tot]=head[x];head[x]=tot;}
	void link(int x,int y,int z){add(x,y,z);add(y,x,0);}
	int d[maxn];
	bool getd()
	{
		queue<int>q;
		memset(d,0,sizeof d);
		d[s]=1;q.push(s);cur[s]=head[s];
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i;i=nxt[i])
			{
				if(!d[ver[i]]&&val[i])
				{
					d[ver[i]]=d[x]+1;
					cur[ver[i]]=head[ver[i]];
					if(ver[i]==t)return true;
					q.push(ver[i]);
				}
			}
		}
		return false;
	}
	int dinic(int x,int flow)
	{
		if(x==t)return flow;
		int res=flow;
		for(int i=cur[x];i&&res;i=nxt[i])
			if(val[i]&&d[ver[i]]==d[x]+1)
			{
				int tmp=dinic(ver[i],min(res,val[i]));
				if(!tmp)d[ver[i]]=0;
				res-=tmp;val[i]-=tmp;val[i^1]+=tmp;
			}
		return flow-res;
	}
	void solve(){int ret=0,flow=0;while(getd())while(flow=dinic(s,inf))ret+=flow;}
}v;
int id(int x,int y){return (x-1)*n+y;}
struct graph
{
	vector<int>e[maxn];int w[maxn];
	void add(int x,int y,int z){e[x].push_back(y);w[y]-=z;w[x]+=z;}
	int len[maxn],in[maxn];
	void topo()
	{
		queue<int>q;
		for(int i=1;i<=n;i++)for(int &j:e[i])in[j]++;
		for(int i=1;i<=n;i++)if(!in[i])q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int &i:e[x])
			{
				len[i]=max(len[i],len[x]+1);
				if(!--in[i])q.push(i);
			}
		}
	}
	void build()
	{
		topo();
		v.s=0;v.t=n*n+1;
		for(int i=1;i<=n;i++)w[i]=-w[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n-len[i];j++)
			{
				if(w[i]>=0)v.link(v.s,id(i,j),w[i]);
				else v.link(id(i,j),v.t,-w[i]);
			}
			for(int j=2;j<=n-len[i];j++)v.link(id(i,j),id(i,j-1),inf);
			v.link(v.s,id(i,1),inf);
		}
		for(int i=1;i<=n;i++)
			for(int &j:e[i])
				for(int k=1;k<=n-len[j];k++)
					v.link(id(j,k),id(i,k+1),inf);
	}
	int ans[maxn];
	bool vis[maxn*maxn];
	void solve()
	{
		v.solve();
		queue<int>q;
		q.push(v.s);vis[v.s]=1;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=v.head[x];i;i=v.nxt[i])
				if(v.val[i]&&!vis[v.ver[i]])q.push(v.ver[i]),vis[v.ver[i]]=1;
		}
		for(int i=v.head[v.s];i;i=v.nxt[i])
			if(vis[v.ver[i]])
			{
				int x=(v.ver[i]-1)/n+1,y=v.ver[i]-(x-1)*n;
				ans[x]=max(ans[x],y);
			}
		for(int i=1;i<=n;i++)
		{
			if(w[i]<0)
				for(int j=1;j<=n-len[i];j++)
					if(vis[id(i,j)])ans[i]=j;
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);exit(0);
	}
}o;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),w=read();
		o.add(x,y,w);
	}
	o.build();o.solve();
	return 0;
}