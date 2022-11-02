#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,u[N]={},v[N]={},w[N]={},tot=0;
set<pair<int,int> > node[2];
void init()
{
	scanf("%d",&n);
	for(int i=1,c,s;i<=n;++i)
	{
		scanf("%d%d",&c,&s);
		node[c].insert({s,i});
	}
}
void add_edge(int side)
{
	auto p1=*node[side].begin();
	auto p2=*node[!side].rbegin();
	node[side].erase(p1);
	node[!side].erase(p2);
	++tot,u[tot]=p1.second,v[tot]=p2.second,w[tot]=p1.first;
	p2.first-=p1.first;
	node[!side].insert(p2);
}
void work()
{
	for(int i=2;i<=n;++i)
	{
		auto p0=*node[0].begin();
		auto p1=*node[1].begin();
		if(p0.first<p1.first || (p0.first==p1.first && node[0].size()>node[1].size()))
			add_edge(0);
		else
			add_edge(1);
	}
	for(int i=1;i<=tot;++i)
		printf("%d %d %d\n",u[i],v[i],w[i]);
}
int main()
{	
	init();
	work();
	return 0;
}