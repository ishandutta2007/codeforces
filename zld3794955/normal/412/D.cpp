#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=30030,M=100100;
int n,m,last[N]={},next[M]={},end[M]={},total_edge=0;
bool v[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u=0,v=0;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
}
void dfs(int s)
{
	if(v[s])
		return;
	v[s]=true;
	for(int i=last[s];i;i=next[i])
		dfs(end[i]);
	printf("%d ",s);
}
int main()
{	
	init();
	for(int i=1;i<=n;++i)
		if(!v[i])
			dfs(i);
	printf("\n");
	return 0;
}