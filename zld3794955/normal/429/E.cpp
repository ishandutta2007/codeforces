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
const int N=101000,Any=0;
struct point
{
	int pos,num;
}s[N+N]={};
bool point_cmp(const point &p1,const point &p2)
{
	return p1.pos<p2.pos;
}
int n,tot=0,last[N+N]={},end[N<<3]={},next[N<<3]={},total_edge=0;
int color[N+N]={},q[N+N]={},head=0,tail=0;
bool v[N+N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d",&n);
	for(int i=1,l(0),r(0);i<=n;++i)
	{
		scanf("%d%d",&l,&r);
		s[++tot].pos=2*l;
		s[tot].num=2*i;
		s[++tot].pos=2*r+1;
		s[tot].num=2*i+1;
		add_edge(2*i,2*i+1);
		add_edge(2*i+1,2*i);
	}
	sort(s+1,s+tot+1,point_cmp);
	for(int i=1;i<=tot;i+=2)
	{
		add_edge(s[i].num,s[i+1].num);
		add_edge(s[i+1].num,s[i].num);
	}
}
void bfs(int start)
{
	//cout<<"start="<<start<<endl;
	head=tail=0;
	q[++tail]=start;
	v[start]=true;
	color[start]=Any;
	while(head!=tail)
	{
		int s=q[++head];
		//cout<<"s="<<s<<endl;
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(!v[j])
			{
				color[j]=!color[s];
				v[j]=true;
				q[++tail]=j;
			}
		}
	}
}
void work()
{
	for(int i=2;i<=n+n+1;++i)
		if(!v[i])
			bfs(i);
	for(int i=2;i<=n+n;i+=2)
		printf("%d ",color[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}