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
#include<numeric>
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
const int N=100100,M=100100;
int n,m,last[N]={},next[M+M]={},end[M+M]={},z[M+M]={},total_edge=1;
int f[N]={},unc[M+M]={};
pair<int,int> dis[N];
inline void add_edge(int u,int v,int l)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	z[total_edge]=l;
}
void init()
{
	cin>>n>>m;
	for(int i=1,u=0,v=0,z=0;i<=m;++i)
	{
		cin>>u>>v>>z;
		add_edge(u,v,z);
		add_edge(v,u,z);
	}
}
void spfa()
{
	queue<int> q;
	bool in[N]={};
	in[1]=true;
	q.push(1);
	for(int i=2;i<=n;++i)
		dis[i].first=1<<20;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		in[s]=false;
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			pair<int,int> tmp(dis[s].first+1,dis[s].second+!z[i]);
			if(tmp<dis[j])
			{
				dis[j]=tmp;
				f[j]=i;
				if(!in[j])
				{
					q.push(j);
					in[j]=true;
				}
			}
		}
	}
}
void work()
{
	int now=n;
	while(now!=1)
	{
		unc[f[now]]=unc[f[now]^1]=true;
		now=end[f[now]^1];
	}
	int ans=0;
	for(int s=1;s<=n;++s)
		for(int i=last[s];i;i=next[i])
			if(s<end[i] && (unc[i]^z[i]))
				++ans;
	cout<<ans<<endl;
	for(int s=1;s<=n;++s)
		for(int i=last[s];i;i=next[i])
			if(s<end[i] && (unc[i]^z[i]))
				cout<<s<<' '<<end[i]<<' '<<unc[i]<<endl;
}
int main()
{	
	init();
	spfa();
	work();
	return 0;
}