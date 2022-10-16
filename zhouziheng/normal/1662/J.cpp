#include<cstdio>
#include<queue>

using namespace std;

const int INF=1e9;

namespace MaxF
{
	struct e
	{
		int to,val,nxt;
	}ed[1000000];int n,s,t,used;
	void init(int N,int S,int T){n=N,s=S,t=T,used=1;}
	int head[300000],cur[300000];
	void add_edge(int u,int v,int val)
	{
		used++;ed[used].to=v,ed[used].val=val,ed[used].nxt=head[u];head[u]=used;
	}
	void add_pair(int u,int v,int val)
	{
		add_edge(u,v,val);add_edge(v,u,0);
	}
	int dis[300000];
	bool bfs()
	{
		for(int i=0;i<=n;i++)dis[i]=-1;dis[s]=0;queue<int> q;q.push(s);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=head[u];i;i=ed[i].nxt)
			{
				int v=ed[i].to;
				if(ed[i].val>0&&dis[v]==-1){dis[v]=dis[u]+1;q.push(v);}
			}
		}
		return dis[t]!=-1;
	}
	int dfs(int u,int flow)
	{
		if(u==t)return flow;
		int rlow=0;
		for(int &i=cur[u];i&&rlow<flow;i=ed[i].nxt)
		{
			int v=ed[i].to;
			if(ed[i].val>0&&dis[v]==dis[u]+1)
			{
				int tmp=dfs(v,min(flow-rlow,ed[i].val));
				ed[i].val-=tmp,rlow+=tmp,ed[i^1].val+=tmp;
			}
		}
		return rlow;
	}
	int Dinic()
	{
		int ans=0,tmp=0;
		while(bfs())
		{
			for(int i=0;i<=n;i++)cur[i]=head[i];
			while((tmp=dfs(s,INF)))ans+=tmp;
		}
		return ans;
		
	}
}

int n;
int a[200][200],r[200][200],c[200][200],val[200][200];

int id(int i,int j){return (i-1)*n+j;}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){scanf("%d",&a[i][j]);r[i][a[i][j]]=j,c[j][a[i][j]]=i;}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){scanf("%d",&val[i][j]);}
	int B=n*n,s=0,t=2*n*n+1;MaxF::init(t,s,t);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)MaxF::add_pair(id(i,j)+B,id(i,j),2*n+1-val[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1){MaxF::add_pair(s,id(i,j)+B,INF);}
			if(a[i][j]<n){MaxF::add_pair(id(i,j),id(i,r[i][a[i][j]+1]+B),INF),MaxF::add_pair(id(i,j),id(c[j][a[i][j]+1],j)+B,INF);}
			else{MaxF::add_pair(id(i,j),t,INF);};
		}
	}
	printf("%d\n",2*n*n+n-MaxF::Dinic());
}