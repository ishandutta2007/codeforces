#include<bits/stdc++.h>
using namespace std;
const int N=100010,C=100010;
int n,size[N]={},color[N]={},w[C]={},tot=0;
long long d[N]={};
vector<pair<int,int>> e[N];
set<pair<int,int>> s;
priority_queue<int,vector<int>,greater<int>> node[C];
map<int,int> node_list;
void init()
{
	scanf("%d",&n);
	for(int i=1,u=0,v=0,l=0;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		e[u].push_back({v,l});
		e[v].push_back({u,l});
	}
}
int dfs1(int s,int f)
{
	size[s]=1;
	for(auto i:e[s])
		if(i.first!=f)
			size[s]+=dfs1(i.first,s);
	return size[s];
}
void dfs2(int p,int f)
{
	w[tot]+=2;
	color[p]=tot;
	node[tot].push(p);
	for(auto i:e[p])
		if(i.first!=f)
		{
			d[i.first]=d[p]+i.second;
			dfs2(i.first,p);
		}
}
void work1()
{
	dfs1(1,0);
	int center=0;
	for(center=1;center<=n;++center)
		if(size[center]>=(n+1)/2)
		{
			bool flag=true;
			for(auto p:e[center])
				flag&=size[p.first]>size[center] || size[p.first]<=n/2;
			if(flag)
				break;
		}
	node[++tot].push(center);
	w[tot]+=2;
	color[center]=tot;
	s.insert({w[tot],tot});
	node_list[center]=tot;
	for(auto p:e[center])
	{
		++tot;
		d[p.first]=p.second;
		dfs2(p.first,center);
		s.insert({w[tot],tot});
		node_list[node[tot].top()]=tot;
	}
	cout<<2*accumulate(d+1,d+n+1,0ll)<<endl;
}
void work2()
{
	for(int i=1;i<=n;++i)
	{
		int c=color[i];
		if(s.count({w[c],c}))
			s.erase({w[c],c}),s.insert({--w[c],c});
		int now=s.rbegin()->second;
		if(now==1 || s.rbegin()->first<n-i+1)
		{
			auto it=node_list.begin();
			if(it->second!=1 && it->second==c)
				++it;
			now=it->second;
		}
		s.erase({w[now]--,now});
		node_list.erase(node[now].top());
		printf("%d ",node[now].top());
		node[now].pop();
		if(!node[now].empty())
		{
			node_list.insert({node[now].top(),now});
			s.insert({w[now],now});
		}
	}
	printf("\n");
}
int main()
{	
	init();
	work1();
	work2();
	return 0;
}