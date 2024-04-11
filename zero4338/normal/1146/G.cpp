#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int inf=1e9;
int n,h,m;
int id(int x,int y){return (x-1)*h+y;}
struct network_flow
{
	static const int maxn=3000;
	static const int maxm=8000;
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
					q.push(ver[i]);
					if(ver[i]==t)return true;
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
		{
			if(d[ver[i]]==d[x]+1&&val[i])
			{
				int tmp=dinic(ver[i],min(res,val[i]));
				if(!tmp)d[ver[i]]=0;
				res-=tmp;val[i]-=tmp;val[i^1]+=tmp;
			}
			cur[x]=i;
		}
		return flow-res;
	}
	int solve()
	{
		int ret=0,flow=0;
		while(getd())
			while(flow=dinic(s,inf))ret+=flow;
		return ret;
	}
}o;
int main()
{
	n=read();h=read();m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=h;j++)o.link(id(i,j),id(i,j-1),inf);
		for(int j=1;j<=h;j++)o.link(o.s,id(i,j),2*j-1);
	}
	o.t=n*h+m+1;
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read(),x=read(),c=read();
		if(x==h)continue;
		for(int j=l;j<=r;j++)o.link(id(j,x+1),i+n*h,inf);
		o.link(i+n*h,o.t,c);
	}
	int ans=n*h*h-o.solve();
	printf("%d\n",ans);
	return 0;
}