#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 200005

using namespace std;
typedef long long int ll;

struct edge
{
	int to,cost,id,dr;
	edge(int to=0,int cost=0,int id=0,int dr=0):to(to),cost(cost),id(id),dr(dr){}
};
vector <edge> vec[SIZE];
ll deg[SIZE];
ll now[SIZE];
int ans[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[a].push_back(edge(b,c,i,0));
		vec[b].push_back(edge(a,c,i,1));
		deg[a]+=c;
		deg[b]+=c;
	}
	for(int i=0;i<n;i++) now[i]=deg[i];
	queue <int> que;
	que.push(0);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		now[v]=0;
		for(int i=0;i<vec[v].size();i++)
		{
			edge e=vec[v][i];
			now[e.to]-=e.cost;
			if(now[e.to]>=0) ans[e.id]=e.dr;
			if(e.to!=n-1&&now[e.to]*2==deg[e.to]) que.push(e.to);
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}