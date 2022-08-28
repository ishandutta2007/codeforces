#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#define SIZE 100005

using namespace std;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
int ans;

void dfs(int v=0,int p=-1,int d=0)
{
	ans=max(ans,d);
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v,d+e.cost);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	dfs();
	printf("%d\n",ans);
	return 0;
}