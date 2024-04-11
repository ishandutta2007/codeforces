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
const int N=100100;
int n,last[N]={},end[N+N]={},next[N+N]={},total_edge=0;
int now[N]={},goal[N]={},tot=0,d[N]={},q[N]={},head=0,tail=0,re[N]={},rf[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&now[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&goal[i]);
}
void work()
{
	bool v[N]={};
	q[++tail]=1;
	v[1]=true;
	while(head!=tail)
	{
		int s=q[++head];
		if(re[s]^now[s]^goal[s])
		{
			d[++tot]=s;
			re[s]^=1;
		}
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(!v[j])
			{
				q[++tail]=j;
				v[j]=true;
				rf[j]=re[s];
				re[j]=rf[s];
			}
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)
		printf("%d\n",d[i]);
}
int main()
{	
	init();
	work();
	return 0;
}