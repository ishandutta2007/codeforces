#include<bits/stdc++.h>
using namespace std;
const int N=200020,V=200000;
int n,x[N]={},y[N]={},ans[N]={};
set<pair<int,int> > s[N+N]={};
void dfs(int now)
{
	while(!s[now].empty())
	{
		auto edge=*s[now].begin();
		s[now].erase(s[now].begin());
		s[edge.first].erase(make_pair(now,edge.second));
		dfs(edge.first);
		if(edge.second)
			ans[edge.second]=now<=V ? 1 : 2;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		s[x[i]].insert(make_pair(y[i]+V,i));
		s[y[i]+V].insert(make_pair(x[i],i));
	}
	int l=0;
	for(int i=1;i<=V+V;++i)
		if(s[i].size()%2)
		{
			if(l)
			{
				s[l].insert(make_pair(i,0));
				s[i].insert(make_pair(l,0));
				l=0;
			}
			else
				l=i;
		}
	for(int i=1;i<=V+V;++i)
		if(s[i].size())
			dfs(i);
	for(int i=1;i<=n;++i)
		putchar(ans[i]==1 ? 'b' : 'r');
	return 0;
}