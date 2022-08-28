#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MINF -1000000000

using namespace std;

struct edge
{
	int to,rev;
	edge(int to=-1,int rev=-1):to(to),rev(rev){}
};
vector <edge> vec[SIZE];
vector <int> dp[SIZE];
int m1[SIZE],m2[SIZE];
bool ok[SIZE];

int dfs(int v=0,int p=-1)
{
	int ret=MINF;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dp[v][i]=dfs(e.to,v)+1;
			ret=max(ret,dp[v][i]);
		}
	}
	if(ok[v]) ret=max(ret,0);
	return ret;
}
int val(edge e)
{
	int v=e.to,id=e.rev;
	if(m1[v]==dp[v][id]) return max(m2[v],ok[v]?0:MINF);
	return max(m1[v],ok[v]?0:MINF);
}
void again(int v=0,int p=-1)
{
	m1[v]=m2[v]=MINF;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to==p) dp[v][i]=val(e)+1;
		if(m1[v]<dp[v][i])
		{
			m2[v]=m1[v];
			m1[v]=dp[v][i];
		}
		else if(m2[v]<dp[v][i]) m2[v]=dp[v][i];
	}
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) again(e.to,v);
	}
}
int main()
{
	int n,m,d;
	scanf("%d %d %d",&n,&m,&d);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);a--;
		ok[a]=true;
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		int as=vec[a].size(),bs=vec[b].size();
		vec[a].push_back(edge(b,bs));
		vec[b].push_back(edge(a,as));
	}
	for(int i=0;i<n;i++) dp[i].resize(vec[i].size());
	dfs();again();
	int ret=0;
	for(int i=0;i<n;i++) if(m1[i]<=d) ret++;
	printf("%d\n",ret);
	return 0;
}