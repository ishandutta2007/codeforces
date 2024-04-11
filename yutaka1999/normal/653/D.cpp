#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 55
#define MX 505
#define INF 1000000000
#define DINF 1e7

using namespace std;
typedef long long int ll;

struct edge
{
	int to,rev,cap;
	edge(int to=0,int cap=0,int rev=0):to(to),cap(cap),rev(rev){}
};
vector <edge> vec[SIZE];
int left[MX],right[MX],cost[MX];
bool use[SIZE];
int n,m,x;

void rem()
{
	for(int i=0;i<n;i++)
	{
		vec[i].clear();
	}
}
void add(int s,int t,int c)
{
	int S=vec[s].size(),T=vec[t].size();
	vec[s].push_back(edge(t,c,T));
	vec[t].push_back(edge(s,0,S));
}
int dfs(int v,int t,int f)
{
	if(v==t) return f;
	use[v]=true;
	for(int i=0;i<vec[v].size();i++)
	{
		edge &e=vec[v][i];
		if(!use[e.to]&&e.cap>0)
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				vec[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{
	int flow=0;
	while(1)
	{
		memset(use,false,sizeof(use));
		int f=dfs(s,t,INF);
		if(f==0) return flow;
		flow+=f;
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&x);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&left[i],&right[i],&cost[i]);
		left[i]--,right[i]--;
	}
	double l=0.0,r=DINF;
	for(int i=0;i<80;i++)
	{
		double d=(l+r)/2;
		rem();
		for(int j=0;j<m;j++)
		{
			ll L=(ll) (cost[j]/d);
			L=min(L,(ll) x);
			add(left[j],right[j],(int) L);
		}
		int f=max_flow(0,n-1);
		if(f>=x) l=d;
		else r=d;
	}
	printf("%.10f\n",(double) l*(double) x);
	return 0;
}