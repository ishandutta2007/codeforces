#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=205,maxm=1e3+5;
int n,m;
struct network_flow
{
	int s,t,mf;
	struct edge{int to,nxt,val;}orie[maxm<<1],e[maxm<<1];int head[maxn],cur[maxn],tot=1;
	void add(int x,int y,int z){orie[++tot]={y,head[x],z};head[x]=tot;}
	void link(int x,int y,int z){add(x,y,z);add(y,x,z);}
	int d[maxn];
	bool getd()
	{
		queue<int>q;
		memset(d,0,sizeof d);
		d[s]=1;q.push(s);cur[s]=head[s];
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i;i=e[i].nxt)
			{
				int to=e[i].to;
				if(!d[to]&&e[i].val)
				{
					d[to]=d[x]+1;
					cur[to]=head[to];
					if(to==t)return true;
					q.push(to);
				}
			}
		}
		return false;
	}
	int dinic(int x,int flow)
	{
		if(x==t)return flow;
		int res=flow;
		for(int i=cur[x];i&&res;cur[x]=i,i=e[i].nxt)
			if(e[i].val&&d[e[i].to]==d[x]+1)
			{
				int tmp=dinic(e[i].to,min(e[i].val,res));
				if(!tmp)d[e[i].to]=0;
				e[i].val-=tmp;e[i^1].val+=tmp;res-=tmp;
			}
		return flow-res;
	}
	int getmf(int _s,int _t)
	{
		s=_s;t=_t;mf=0;
		memcpy(e,orie,sizeof(edge)*(tot+1));
		int flow=0;
		while(getd())while(flow=dinic(s,1e9))mf+=flow;
		return mf;
	}
}o;
int anssum;
vector<int>porder;
struct gomory_hu_tree
{
	struct edge{int fr,to,val;}e[maxn];int cnt;
	void build(vector<int>p)
	{
		if(p.size()<=1)return;
		int x=p[0],y=p[1];
		e[++cnt]={x,y,o.getmf(x,y)};
		static bool vis[maxn];
		queue<int>q;q.push(x);vis[x]=true;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=o.head[x];i;i=o.e[i].nxt)
				if(o.e[i].val&&!vis[o.e[i].to])
				{
					vis[o.e[i].to]=true;
					q.push(o.e[i].to);
				}
		}
		vector<int>lp,rp;
		for(int &i:p)
		{
			if(vis[i])lp.push_back(i);
			else rp.push_back(i);
		}
		memset(vis,0,sizeof(bool)*(n+1));
		build(lp);build(rp);
	}
	struct dsu
	{
		int fa[maxn<<1];
		void init(){iota(fa+1,fa+2*n,1);}
		int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
		void merge(int x,int y){fa[get(x)]=get(y);}
	}S;
	vector<int>ke[maxn<<1];
	void dfs(int u)
	{
		if(u<=n)porder.push_back(u);
		for(int &i:ke[u])dfs(i);
	}
	void solve()
	{
		vector<int>tmp(n);
		iota(tmp.begin(),tmp.end(),1);
		build(tmp);
		assert(cnt==n-1);
		sort(e+1,e+n,[](edge &i,edge &j){return i.val>j.val;});
		S.init();
		for(int i=1;i<n;i++)
		{
			anssum+=e[i].val;
			ke[n+i].push_back(S.get(e[i].fr));
			ke[n+i].push_back(S.get(e[i].to));

			S.merge(e[i].fr,n+i);
			S.merge(e[i].to,n+i);
		}
		dfs(2*n-1);
	}
}v;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		o.link(a,b,c);
	}
	v.solve();
	printf("%d\n",anssum);
	for(int &i:porder)printf("%d ",i);
	putchar('\n');
	return 0;
}