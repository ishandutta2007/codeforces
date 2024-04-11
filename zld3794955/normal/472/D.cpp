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
const int N=2020;
int n,d[N][N]={},last[N]={},next[N+N]={},end[N+N]={},l[N+N]={},total_edge=0;
int f[N]={};
inline void add_edge(int u,int v,int len)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	l[total_edge]=len;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&d[i][j]);
}
bool check1()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(i==j && d[i][j])
				return false;
			if(i!=j && !d[i][j])
				return false;
			if(d[i][j]!=d[j][i])
				return false;
		}
	return true;
}
bool cmp(int x,int y)
{
	return d[1][x]<d[1][y];
}
bool bfs(int start)
{
	int q[N]={},head=0,tail=0,dis[N]={};
	bool v[N]={};
	q[++tail]=start;
	dis[start]=0;
	v[start]=true;
	while(head!=tail)
	{
		int s=q[++head];
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(!v[j])
			{
				dis[j]=dis[s]+l[i];
				q[++tail]=j;
				v[j]=true;
				if(dis[j]!=d[start][j])
					return false;
			}
		}
	}
	return true;
}
bool check2()
{
	for(int i=2;i<=n;++i)
	{
		int a[N]={},tot=0;
		for(int j=1;j<=n;++j)
			if(d[1][j]+d[j][i]==d[1][i])
				a[++tot]=j;
		sort(a+1,a+tot+1,cmp);
		for(int j=2;j<=tot;++j)
			f[a[j]]=a[j-1];
	}
	for(int i=2;i<=n;++i)
		if(!f[i])
			return false;
		else
		{
			add_edge(i,f[i],d[1][i]-d[1][f[i]]);
			add_edge(f[i],i,d[1][i]-d[1][f[i]]);
		}
	for(int i=1;i<=n;++i)
		if(!bfs(i))
			return false;
	return true;
}
void work()
{
	if(check1() && check2())
		puts("YES");
	else
		puts("NO");
}
int main()
{	
	init();
	work();
	return 0;
}