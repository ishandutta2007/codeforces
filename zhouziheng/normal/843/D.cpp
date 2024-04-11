#include<cstdio>
#include<queue>

using namespace std;

struct pri
{
	int id;long long val;pri(int i=0,long long v=0):id(i),val(v){}
};bool operator<(pri a,pri b){return a.val>b.val;}

struct e
{
	int to;long long val;e(int t=0,long long v=0):to(t),val(v){}
};vector<e> ed[200000];

bool vis[200000];
const long long INF=1e15;
void Dijsktra(int n,int s,long long *dis)
{
	for(int i=1;i<=n;i++)dis[i]=INF;dis[s]=0;priority_queue<pri> pq;pq.push(pri(s,0));
	for(int i=1;i<=n;i++)vis[i]=0;
	while(!pq.empty())
	{
		pri x=pq.top();pq.pop();
		if(vis[x.id])continue;vis[x.id]=1;int u=x.id;//printf("%d\n",x.id);
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i].to;//printf("%d\n",v);
			if(dis[u]+ed[u][i].val<dis[v])
			{
				dis[v]=dis[u]+ed[u][i].val;
				pq.push(pri(v,dis[v]));
			}
		}
	}
}

int u[200000],id[200000];
long long dis[200000];

int n=0,m=0,q=0;
void subtract(long long *dis)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<ed[i].size();j++)
		{
			int u=ed[i][j].to;ed[i][j].val=dis[i]+ed[i][j].val-dis[u];
		}
	}
}

vector<int> v[2000000];
void another(int n,int s,long long *dis)
{
	for(int i=1;i<=n;i++)dis[i]=INF;dis[s]=0;v[0].push_back(s);
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			int u=v[i][j];if(dis[u]!=i||vis[u])continue;vis[u]=1;
			for(int k=0;k<ed[u].size();k++)
			{
				int w=ed[u][k].to;
				if(dis[u]+ed[u][k].val<n&&dis[u]+ed[u][k].val<dis[w])
				{
					dis[w]=dis[u]+ed[u][k].val;
					if(dis[w]<n)v[dis[w]].push_back(w);
					//puts("???");
				}
			}
		}
	}
	for(int i=0;i<n;i++)v[i].clear();
}

long long dis2[200000];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&u[i]);id[i]=ed[u[i]].size();
		int v=0,w=0;scanf("%d%d",&v,&w);
		ed[u[i]].push_back(e(v,w));
	}

	Dijsktra(n,1,dis);subtract(dis);
	
	while(q--)
	{
		/*for(int i=1;i<=n;i++)
		{
			for(int j=0;j<ed[i].size();j++)printf("%d %d: %d\n",i,ed[i][j].to,ed[i][j].val);
		}*/
		int op=0;scanf("%d",&op);
		if(op==1)
		{
			int x=0;scanf("%d",&x);
			printf("%lld\n",dis[x]>=INF?-1:dis[x]);
		}
		else
		{
			int c=0;scanf("%d",&c);
			while(c--)
			{
				int i=0;scanf("%d",&i);ed[u[i]][id[i]].val++;
			}
			another(n,1,dis2);subtract(dis2);for(int i=1;i<=n;i++)dis[i]+=dis2[i];
		}
	}
	return 0;
}