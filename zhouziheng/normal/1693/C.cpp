#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int INF=1e9;

typedef pair<int,int> PAIR;

priority_queue<PAIR> pq;
int out[300000];vector<int> ed[300000];bool vis[300000];
int dis[300000];

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=1,x=0,y=0;i<=m;i++)
	{
		scanf("%d%d",&x,&y);out[x]++;ed[y].push_back(x);
	}
	for(int i=1;i<n;i++)dis[i]=INF;
	pq.push(make_pair(0,n));
	while(!pq.empty())
	{
		int u=pq.top().second;pq.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i];
			out[v]--;int x=dis[u]+out[v]+1;
			if(dis[v]>x){dis[v]=x;pq.push(make_pair(-dis[v],v));}
		}
	}
	printf("%d",dis[1]);
}