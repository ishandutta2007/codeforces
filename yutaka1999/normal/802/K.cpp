#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#define SIZE 100005

using namespace std;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
int dp1[SIZE];
int dp2[SIZE];
int k;

void dfs(int v=0,int p=-1)
{
	dp1[v]=dp2[v]=0;
	vector <int> vx;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v);
			vx.push_back(dp1[e.to]+e.cost);
		}
	}
	sort(vx.begin(),vx.end(),greater<int>());
	int last=1500000000;
	for(int i=0;i<min(k-1,(int) vx.size());i++)
	{
		dp1[v]+=vx[i];
		last=vx[i];
	}
	int nxt=k-1<vx.size()?vx[k-1]:0;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			int now=dp1[v]+e.cost+dp2[e.to];
			if(dp1[e.to]+e.cost>=last)
			{
				now-=dp1[e.to]+e.cost;
				now+=nxt;
			}
			dp2[v]=max(dp2[v],now);
		}
	}
	//printf("%d : %d %d\n",v,dp1[v],dp2[v]);
}
int main()
{
	int n;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	dfs();
	printf("%d\n",dp2[0]);
	return 0;
}