#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005
#define INF 10000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
ll dist[SIZE];
bool use[SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	for(int i=0;i<n;i++) dist[i]=INF;
	priority_queue <P,vector <P>,greater <P> > que;
	dist[0]=0;
	que.push(P(0,0));
	for(int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;
		dist[a]=min(dist[a],(ll) b);
		use[a]=true;
	}
	for(int i=0;i<n;i++) if(use[i]) que.push(P(dist[i],i));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int v=p.second;
		if(dist[v]<p.first) continue;
		for(int i=0;i<vec[v].size();i++)
		{
			edge e=vec[v][i];
			if(dist[e.to]>dist[v]+(ll) e.cost)
			{
				use[e.to]=false;
				dist[e.to]=dist[v]+(ll) e.cost;
				que.push(P(dist[e.to],e.to));
			}
			else if(dist[e.to]==dist[v]+(ll) e.cost) use[e.to]=false;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++) if(use[i]) cnt++;
	printf("%d\n",k-cnt);
	return 0;
}