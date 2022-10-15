#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e4+10;
const int maxm=maxn*10;
const int inf=1e9;
int n,b,q;
int count(int l,int r,int x)
{
	int nl=ceil((l-x)/5.0),nr=floor((r-x)/5.0);
	return max(0,nr-nl+1);
}
pair<int,int>hi[maxn];
struct network_flow
{
	int s,t;
	int head[maxn],cur[maxn],ver[maxm<<1],nxt[maxm<<1],val[maxm<<1],tot=1;
	void add(int x,int y,int z){ver[++tot]=y;val[tot]=z;nxt[tot]=head[x];head[x]=tot;}
	void link(int x,int y,int z){add(x,y,z);add(y,x,0);}
	int d[maxn];
	bool getd()
	{
		queue<int>q;
		memset(d,0,sizeof d);
		d[s]=1;cur[s]=head[s];q.push(s);
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
			cur[x]=i;
		}
		return flow-res;
	}
	int solve()
	{
		int ret=0,flow=0;
		while(getd())while(flow=dinic(s,inf))ret+=flow;
		return ret;
	}
}o;
int main()
{
	n=read();b=read();q=read();
	for(int i=1;i<=q;i++)hi[i].first=read(),hi[i].second=read();
	sort(hi+1,hi+q+1);
	if(hi[q].first!=b)hi[++q]={b,n};
	for(int i=q;i>=1;i--)hi[i].second-=hi[i-1].second;
	for(int i=1;i<=q;i++)if(hi[i].second<0){puts("unfair");return 0;}
	o.s=0;o.t=q+6;
	for(int i=1;i<=5;i++)o.link(q+i,o.t,n/5);
	for(int i=1;i<=q;i++)o.link(o.s,i,hi[i].second);
	for(int i=1;i<=q;i++)
		for(int j=0;j<5;j++)
			o.link(i,q+j+1,count(hi[i-1].first+1,hi[i].first,j));
	puts(o.solve()==n?"fair":"unfair");
	return 0;
}