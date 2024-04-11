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
const int N=3008,M=30030;
int n,m,last[N]={},end[M]={},next[M]={},total_edge=0;
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
void work()
{
	long long ans=0;
	for(int s=1;s<=n;++s)
	{
		int a[N]={};
		for(int i=last[s];i;i=next[i])
			for(int j=last[end[i]];j;j=next[j])
				if(end[j]!=s)
					ans+=a[end[j]]++;
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}