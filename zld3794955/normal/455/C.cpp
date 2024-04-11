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
const int N=300010;
int n,m,Q,root[N]={},d[N]={},last[N]={},next[N+N]={},end[N+N]={},total_edge=0;
int q[N]={},v[N]={};
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;++i)
		root[i]=i;
	for(int i=1,u=0,v=0;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		root[get_root(u)]=get_root(v);
	}
}
void get_dis(int s)
{
	int head=0,tail=0,now=0;
	q[++tail]=s;
	v[s]=++now;
	d[s]=0;
	while(head!=tail)
	{
		int s=q[++head];
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(v[j]!=now)
			{
				v[j]=now;
				q[++tail]=j;
				d[j]=d[s]+1;
			}
		}
	}
	for(int i=1;i<=tail;++i)
		if(d[q[i]]>d[s])
			s=q[i];
	head=tail=0;
	q[++tail]=s;
	v[s]=++now;
	d[s]=0;
	while(head!=tail)
	{
		int s=q[++head];
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(v[j]!=now)
			{
				v[j]=now;
				q[++tail]=j;
				d[j]=d[s]+1;
			}
		}
	}
	int dis=0;
	for(int i=1;i<=tail;++i)
		dis=max(d[q[i]],dis);
	d[get_root(s)]=dis;
}
void get_d()
{
	for(int i=1;i<=n;++i)
		if(!v[i])
			get_dis(i);
	//for(int i=1;i<=n;++i)
	//	cout<<root[i]<<' ';
	//cout<<endl;
	//for(int i=1;i<=n;++i)
	//	cout<<d[i]<<' ';
	//cout<<endl; 
}
void work()
{
	int type,u,v,x;
	for(int i=1;i<=Q;++i)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%d",&x);
			printf("%d\n",d[get_root(x)]);
		}
		if(type==2)
		{
			scanf("%d%d",&u,&v);
			int ur=get_root(u),vr=get_root(v);
			if(ur!=vr)
			{
				int d1=d[ur],d2=d[vr];
				root[ur]=vr;
				d[vr]=(d1+1)/2+(d2+1)/2+1;
				d[vr]=max(d1,d[vr]);
				d[vr]=max(d2,d[vr]);
			}
		}
	}
}
int main()
{	
	init();
	get_d();
	work();
	return 0;
}