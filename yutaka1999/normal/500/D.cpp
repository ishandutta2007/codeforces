#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef long double ld;

struct edge
{
	int to,cost,id;
	edge(int to=0,int cost=0,int id=0):to(to),cost(cost),id(id){}
};
vector <edge> vec[SIZE];
int len[SIZE],nd[SIZE];
ll cnt[SIZE],sum;
int n,q;

void dfs(int v=0,int p=-1)
{
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v);
			cnt[e.id]=(ll) nd[e.to]*(ll) (n-nd[e.to]);
			sum+=cnt[e.id]*(ll) e.cost;
			nd[v]+=nd[e.to];
		}
	}
}
int main()
{
	scanf("%d",&n);
	ld d=1.0-(ld) ((ll) (n-2)*(ll) (n-3)*(ll) (n-4)/6LL+(ll) (n-2)*(ll) (n-3))/(ld) ((ll) n*(ll) (n-1)*(ll) (n-2)/6LL);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		vec[a].push_back(edge(b,c,i));
		vec[b].push_back(edge(a,c,i));
		len[i]=c;
	}
	dfs();
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;
		sum-=(ll) (len[a]-b)*cnt[a];
		len[a]=b;
		printf("%.10f\n",(double) (d*sum));
	}
	return 0;
}