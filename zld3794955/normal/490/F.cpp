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
const int N=6060;
int n,p[N]={},last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
int ans=0,v[N]={},now=0,f[N]={},len=0;
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>p[i];
	for(int i=1,u=0,v=0;i<n;++i)
	{
		cin>>u>>v;
		add_edge(u,v);
		add_edge(v,u);
	}
}
void dfs(int s)
{
	v[s]=now;
	bool flag=false;
	int pos=0,tmp=0;
	if(p[s]>f[len])
	{
		f[++len]=p[s];
		flag=true;
		ans=max(ans,len);
	}
	else
	{
		pos=lower_bound(f+1,f+len+1,p[s])-f;
		tmp=f[pos];
		f[pos]=p[s];
	}
	for(int i=last[s];i;i=next[i])
		if(v[end[i]]!=now)
			dfs(end[i]);
	if(flag)
		f[len--]=0;
	else
		f[pos]=tmp;
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		++now;
		dfs(i);
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}