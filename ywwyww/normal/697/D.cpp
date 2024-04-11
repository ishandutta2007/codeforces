#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
list<int> l[1000010];
int sz[1000010];
double ans[1000010];
void dfs(int x)
{
	sz[x]=1;
	for(auto v:l[x])
	{
		dfs(v);
		sz[x]+=sz[v];
	}
}
void dfs2(int x,double p)
{
	ans[x]=p;
	for(auto v:l[x])
		dfs2(v,p+(sz[x]-sz[v]-1)/2.+1);
}
int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		l[x].push_back(i);
	}
	dfs(1);
	dfs2(1,1);
	for(i=1;i<=n;i++)
		printf("%.10lf ",ans[i]);
	return 0;
}