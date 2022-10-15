#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=55;
int n,m;
set<pair<int,int>>exi;
map<int,pair<int,int>>id;
int in[maxn];
bool ans[maxn][maxn];
struct network_flow
{
	static const int maxn=3025,maxm=maxn<<2;
	int s,t;
	struct edge{int to,nxt,w,c;}e[maxm<<1];int head[maxn],tot=1;
	void add(int x,int y,int z,int c){e[++tot]={y,head[x],z,c};head[x]=tot;}
	void link(int x,int y,int z,int c){add(x,y,z,c);add(y,x,0,-c);}
	int dis[maxn],pre[maxn],incf[maxn],h[maxn];
	struct node{int x,d;bool operator >(const node &a)const{return d>a.d;}};
	priority_queue<node,vector<node>,greater<node>>q;
	bool dijkstra()
	{
		memset(dis,0x3f,sizeof dis);
		dis[s]=0;q.push({s,0});incf[s]=1e9;
		while(!q.empty())
		{
			node now=q.top();q.pop();
			if(dis[now.x]<now.d)continue;
			for(int i=head[now.x];i;i=e[i].nxt)
			{
				if(!e[i].w)continue;
				int to=e[i].to,val=now.d+e[i].c+h[now.x]-h[e[i].to];
				if(dis[to]>val)
				{
					pre[to]=i;incf[to]=min(incf[now.x],e[i].w);
					dis[to]=val;q.push({to,dis[to]});
				}
			}
		}
		return dis[t]!=0x3f3f3f3f;
	}
	void update()
	{
		for(int i=1;i<=n;i++)h[i]+=dis[i];
		int now=t;
		while(now!=s)
		{
			int i=pre[now];
			e[i].w-=incf[t];
			e[i^1].w+=incf[t];
			now=e[i^1].to;
		}
	}
	void solve(){while(dijkstra())update();}
}o;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		ans[u][v]=1;in[v]++;
		if(u>v)swap(u,v);
		exi.insert({u,v});
	}
	o.s=0;
	for(int i=1;i<=n;i++)for(int j=in[i];j<=n;j++)o.link(o.s,i,1,2*j+1);
	int cnt=n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!exi.count({i,j}))
			{
				id[++cnt]={i,j};
				o.link(i,cnt,1,0);
				o.link(j,cnt,1,0);
			}
	o.t=cnt+1;
	for(int i=n+1;i<=cnt;i++)o.link(i,o.t,1,0);
	o.solve();
	for(int i=1;i<=n;i++)
		for(int j=o.head[i];j;j=o.e[j].nxt)
			if(o.e[j].to>n&&!o.e[j].w)
			{
				pair<int,int>now=id[o.e[j].to];
				ans[now.first^now.second^i][i]=1;
			}
	for(int i=1;i<=n;i++,putchar('\n'))for(int j=1;j<=n;j++)printf("%d",ans[i][j]);
	return 0;
}