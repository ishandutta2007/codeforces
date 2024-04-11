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
const int N=25,M=25;
int n,m,p=0,num[N][M]={};
int last[N*M]={},next[N*M*2]={},end[N*M*2]={},total_edge=0;
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			num[i][j]=++p;
	char c1[N]={},c2[M]={};
	scanf("%s\n",c1+1);
	scanf("%s\n",c2+1);
	for(int i=1;i<=n;++i)
		if(c1[i]=='>')
			for(int j=1;j<m;++j)
				add_edge(num[i][j],num[i][j+1]);
		else
			for(int j=m;j>1;--j)
				add_edge(num[i][j],num[i][j-1]);
	for(int j=1;j<=m;++j)
		if(c2[j]=='v')
			for(int i=1;i<n;++i)
				add_edge(num[i][j],num[i+1][j]);
		else
			for(int i=n;i>1;--i)
				add_edge(num[i][j],num[i-1][j]);
}
bool bfs(int start)
{
	int q[N*M]={},head=0,tail=0;
	bool v[N*M]={};
	q[++tail]=start;
	v[start]=true;
	while(head!=tail)
	{
		int s=q[++head];
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(!v[j])
			{
				v[j]=true;
				q[++tail]=j;
			}
		}
	}
	return tail==p;
}
void work()
{
	for(int i=1;i<=p;++i)
		if(!bfs(i))
		{
			puts("NO");
			return;
		}
	puts("YES");
}
int main()
{	
	init();
	work();
	return 0;
}