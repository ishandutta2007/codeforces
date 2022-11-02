#include<bits/stdc++.h>
using namespace std;
const int N=200010,M=200010,Inf=1<<30;
struct event
{
	int type,x,v;
}e[N+M+M]={};
struct wall
{
	int l,r,t;
}w[M]={};
int n,m,q,ans[N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&w[i].l,&w[i].r,&w[i].t);
	sort(w+1,w+m+1,[](const wall &w1,const wall &w2){return w1.t<w2.t;});
	set<pair<int,int> > s;
	s.insert({-Inf,Inf});
	for(int i=1;i<=m;++i)
	{
		auto it=--s.upper_bound({w[i].l,0});
		if(w[i].l<it->second)
		{
			if(it->second<=w[i].r)
			{
				//l=w[i].l r=it->second
				e[++q]={1,w[i].t-it->second,1};
				e[++q]={1,w[i].t-w[i].l,-1};
				int tl=it->first;
				s.erase(it);
				s.insert({tl,w[i].l});
			}
			else
			{
				//l=w[i].l r=w[i].r
				int tl=it->first,tr=it->second;
				e[++q]={1,w[i].t-w[i].r,1};
				e[++q]={1,w[i].t-w[i].l,-1};
				s.erase(it);
				s.insert({tl,w[i].l});
				s.insert({w[i].r,tr});
			}
		}
		it=s.lower_bound({w[i].l,0});
		while(it->first<w[i].r)
		{
			if(it->second<=w[i].r)
			{
				e[++q]={1,w[i].t-it->second,1};
				e[++q]={1,w[i].t-it->first,-1};
				s.erase(it);
			}
			else
			{
				int tr=it->second;
				e[++q]={1,w[i].t-w[i].r,1};
				e[++q]={1,w[i].t-it->first,-1};
				s.erase(it);
				s.insert({w[i].r,tr});
			}
			it=s.lower_bound({w[i].l,0});
		}
	}
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		e[++q]={2,x,i};
	}
	sort(e+1,e+q+1,[](const event &w1,const event &w2){return w1.x<w2.x;});
}
void work()
{
	int last=0,v=0,s=0; 
	for(int i=1;i<=q;++i)
		if(e[i].type==1)
		{
			s+=(e[i].x-last)*v;
			last=e[i].x;
			v+=e[i].v;
		}
		else
			ans[e[i].v]=s+(e[i].x-last)*v;
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
}
int main()
{
	init();
	work();
	return 0;
}