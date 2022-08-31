#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#define SIZE 1005
#define MX 100005
#define INF 1000000005
#define LINF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

struct edge
{
	int to,cost,id;
	edge(int to=0,int cost=0,int id=-1):to(to),cost(cost),id(id){}
};
vector <edge> vec[SIZE];
ll dist[SIZE];
ll dp[SIZE];
int left[MX],right[MX],wt[MX];
int n,m,L,s,t;

void dijkstra(int v)
{
	for(int i=0;i<n;i++) dist[i]=LINF;
	dist[v]=0;
	priority_queue <P,vector <P>,greater <P> > que;
	que.push(P(0,v));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second;
		if(dist[v]<p.first) continue;
		for(int i=0;i<vec[v].size();i++)
		{
			edge e=vec[v][i];
			if(dist[e.to]>dist[v]+e.cost)
			{
				dist[e.to]=dist[v]+e.cost;
				que.push(P(dist[e.to],e.to));
			}
		}
	}
}
int main()
{
	scanf("%d %d %d %d %d",&n,&m,&L,&s,&t);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vec[a].push_back(edge(b,max(1,c),i));
		vec[b].push_back(edge(a,max(1,c),i));
		left[i]=a,right[i]=b,wt[i]=c;
	}
	dijkstra(t);
	priority_queue <P,vector <P>,greater <P> > que;
	for(int i=0;i<n;i++) dp[i]=LINF;
	//for(int i=0;i<n;i++) printf("%lld ",dist[i]);puts("");
	dp[s]=0;
	que.push(P(0,s));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second;
		if(dp[v]<p.first) continue;
		for(int i=0;i<vec[v].size();i++)
		{
			edge e=vec[v][i];
			e.cost=wt[e.id];
			if(e.cost==0)
			{
				ll w=max(1LL,(ll) L-dp[v]-dist[e.to]);
				//printf("%d %d : %lld %lld -> %lld\n",v,e.to,dp[v],dist[e.to],w);
				e.cost=(int) w;
				wt[e.id]=w;
			}
			if(dp[e.to]>dp[v]+e.cost)
			{
				dp[e.to]=dp[v]+e.cost;
				que.push(P(dp[e.to],e.to));
			}
		}
	}
	if(dp[t]!=L)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		for(int i=0;i<m;i++) printf("%d %d %d\n",left[i],right[i],wt[i]);
	}
	return 0;
}