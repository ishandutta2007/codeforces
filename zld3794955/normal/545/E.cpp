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
const int N=300030,M=300030;
int n,m,last[N]={},next[M+M]={},end[M+M]={},l[M+M]={},total_edge=0;
int a[M+M]={},tot=0,c[N]={};
long long dis[N]={};
inline void add_edge(int u,int v,int w,int num)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	l[total_edge]=w;
	a[total_edge]=num;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u=0,v=0,w=0;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w,i),add_edge(v,u,w,i);
	}
}
struct node
{
	long long dis;
	int to,l,num;
};
struct node_cmp
{
	bool operator() (const node &n1,const node &n2)
	{
		return n1.dis>n2.dis || (n1.dis==n2.dis && n1.l>n2.l);
	}
};
void work()
{
	long long ans=0;
	bool v[N]={};
	priority_queue<node,vector<node>,node_cmp> q;
	int s;
	scanf("%d",&s);
	q.push((node){0,s,0,0});
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		if(v[tmp.to])
			continue;
		ans+=tmp.l;
		dis[tmp.to]=tmp.dis;
		v[tmp.to]=true;
		c[++tot]=tmp.num;
		for(int i=last[tmp.to];i;i=next[i])
			q.push((node){tmp.dis+l[i],end[i],l[i],a[i]});
	}
	cout<<ans<<endl;
	sort(c+1,c+tot+1);
	for(int i=2;i<=tot;++i)
		printf("%d ",c[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}