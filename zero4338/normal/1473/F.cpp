#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e3+5;
const int inf=1e9;
int n,a[maxn],b[maxn];
int ans;
struct network_flow
{
	static const int maxm=maxn*105;
	int s,t;
	int head[maxn],cur[maxn],ver[maxm<<1],nxt[maxm<<1],val[maxm<<1],tot=1;
	void add(int x,int y,int z){ver[++tot]=y;val[tot]=z;nxt[tot]=head[x];head[x]=tot;}
	void link(int x,int y,int z){add(x,y,z);add(y,x,0);}
	void build()
	{
		map<int,bool>exi;
		s=0;t=n+1;
		for(int i=1;i<=n;i++)
		{
			if(b[i]>=0)link(s,i,b[i]),ans+=b[i];
			else link(i,t,-b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(exi[a[j]])continue;
				exi[a[j]]=1;
				if(a[i]%a[j]==0)link(i,j,inf);
			}
			exi.clear();
		}
	}
	int d[maxn];
	bool getd()
	{
		memset(d,0,sizeof(int)*(n+2));
		queue<int>q;
		q.push(s);d[s]=1;cur[s]=head[s];
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i;i=nxt[i])
			{
				if(val[i]&&!d[ver[i]])
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
		{
			if(val[i]&&d[ver[i]]==d[x]+1)
			{
				int tmp=dinic(ver[i],min(val[i],res));
				if(!tmp)d[ver[i]]=0;
				res-=tmp;val[i]-=tmp;val[i^1]+=tmp;
			}
		}
		return flow-res;
	}
	void solve()
	{
		int flow=0;
		while(getd())while(flow=dinic(s,inf))ans-=flow;
	}
}o;
int main()
{
	n=read();generate_n(a+1,n,read);generate_n(b+1,n,read);
	o.build();o.solve();
	printf("%d\n",ans);
	return 0;
}