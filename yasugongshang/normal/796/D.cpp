#include <bits/stdc++.h>
using namespace std;
const int N=6e5+20;
typedef pair<int,int> ii;

int n,k,d,ans;
vector<ii> e[N];//to id
queue<ii> q;//u,from
int vis[N],mk[N];
void init()
{
	ans=0;
	for(int i=1;i<=n;i++)
		e[i].clear();
	while(!q.empty())
		q.pop();
	memset(vis,0,sizeof(vis));
	memset(mk,0,sizeof(mk));
}
void bfs()
{
	while(!q.empty())
	{
		int u=q.front().first,from=q.front().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].first,id=e[u][i].second;
			if(v!=from)
			{
				if(vis[v])//v,u
					mk[id]=1,ans++;
				else
					q.push(ii(v,u));
			}
		}
	}
}
int main()
{
	while(cin>>n>>k>>d)
	{
		int u,v;
		init();
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&u);
			q.push(ii(u,0));
		}
		for(int i=1;i<=n-1;i++)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(ii(v,i));
			e[v].push_back(ii(u,i));
		}
		bfs();
		
		cout<<ans<<endl;
		for(int i=1;i<=n-1;i++)
			if(mk[i])
				cout<<i<<' ';	
		cout<<endl;		
	}	
	return 0;
}