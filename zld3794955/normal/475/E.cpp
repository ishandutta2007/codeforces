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
const int N=2020,M=2000200,None=-1;
struct edge
{
	int u,v;
}e[M]={};
int last[N]={},end[M+M]={},next[M+M]={},total_edge=0;
int n,m,color[N]={},tot_color=0,csize[N]={};
int s[N]={},top=0,dfn[N]={},low[N]={},tot_dfn=0;
int ans=0,size[N]={},up[N]={},now=0,v[N]={};
bool in[N]={},add[N][N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&e[i].u,&e[i].v);
		add_edge(e[i].u,e[i].v);
		add_edge(e[i].v,e[i].u);
	}
}
void Tarjan(int p,int f)
{
	dfn[p]=low[p]=++tot_dfn;
	s[++top]=p;
	v[p]=now;
	in[p]=true;
	for(int i=last[p];i;i=next[i])
	{
		int j=end[i];
		if(j==f)
			continue;
		if(v[j]!=now)
		{
			Tarjan(j,p);
			low[p]=min(low[j],low[p]);
		}
		else
			if(in[j])
				low[p]=min(dfn[j],low[p]);
	}
	if(dfn[p]==low[p])
	{
		int l=top;
		while(s[l]!=p)
			--l;
		++tot_color;
		csize[tot_color]=top-l+1;
		for(int i=l;i<=top;++i)
		{
			color[s[i]]=tot_color;
			in[s[i]]=true;
			//cout<<s[i]<<' ';
		}
		//cout<<endl;
		top=l-1;
	}
}
void work()
{
	++now;
	Tarjan(1,None);
	total_edge=0;
	//cout<<"tot_color="<<tot_color<<endl;
	for(int i=1;i<=n;++i)
		last[i]=0;
	for(int i=1;i<=m;++i)
	{
		e[i].u=color[e[i].u];
		e[i].v=color[e[i].v];
		if(e[i].u!=e[i].v && !add[e[i].u][e[i].v])
		{
			add_edge(e[i].u,e[i].v);
			add_edge(e[i].v,e[i].u);
			add[e[i].u][e[i].v]=add[e[i].v][e[i].u]=true;
		}
	}
}
void dp1(int s)
{
	size[s]=csize[s];
	v[s]=now;
	for(int i=last[s];i;i=next[i])
		if(v[end[i]]!=now)
		{
			dp1(end[i]);
			size[s]+=size[end[i]];
		}
}
void dp2(int s,int sum)
{
	int tmps=0;
	v[s]=now;
	up[s]=0;
	for(int i=last[s];i;i=next[i])
		if(v[end[i]]!=now)
		{
			dp2(end[i],sum+csize[end[i]]);
			tmps+=csize[end[i]];
			up[s]+=up[end[i]];
		}
	up[s]+=sum*tmps;
}
void calc()
{
	int sum=0,w[N]={};
	for(int i=1;i<=tot_color;++i)
		sum+=csize[i]*csize[i];
	//cout<<"sum="<<sum<<endl;
	//for(int i=1;i<=n;++i)
	//	cout<<color[i]<<' ';
	//cout<<endl;
	for(int s=1;s<=tot_color;++s)
	{
		bool f[N]={};
		++now;
		v[s]=now;
		for(int i=last[s];i;i=next[i])
			dp1(end[i]);
		//cout<<"root="<<s<<endl;
		//for(int i=last[s];i;i=next[i])
		//	cout<<"end[i]="<<end[i]<<" size="<<size[end[i]]<<endl;
		++now;
		v[s]=now;
		for(int i=last[s];i;i=next[i])
			dp2(end[i],csize[end[i]]);
		//cout<<"root="<<s<<endl;
		//for(int i=last[s];i;i=next[i])
		//	cout<<"end[i]="<<end[i]<<" up="<<up[end[i]]<<endl;
		int tot=0,s1=0,s2=0;
		for(int i=last[s];i;i=next[i])
		{
			s1+=up[end[i]];
			s2+=size[end[i]];
			w[++tot]=size[end[i]];
		}
		s1+=csize[s]*s2;
		//cout<<"s="<<s<<" s1="<<s1<<" s2="<<s2<<endl;
		f[0]=1;
		for(int i=1;i<=tot;++i)
			for(int j=n;j>=w[i];--j)
				f[j]|=f[j-w[i]];
		//for(int i=1;i<=tot;++i)
		//	cout<<w[i]<<' ';
		//cout<<endl;
		//for(int i=0;i<=n;++i)
		//	cout<<f[i]<<' ';
		//cout<<endl;
		s2=0;
		for(int i=0;i<=n;++i)
			if(f[i])
				s2=max(s2,i*(n-csize[s]-i));
		//cout<<"s="<<s<<" s1="<<s1<<" s2="<<s2<<endl;
		ans=max(ans,s1+s2+sum);
	}
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	calc();
	return 0;
}