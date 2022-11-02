#include<bits/stdc++.h>
using namespace std;
const int M=100010,N=100010;
const long long Inf=1ll<<60,ansmax=314000000;
struct split
{
	vector<int> v;
	int s,w;
}p[M];
int m,n;
long long dis[N]={},maxv[N]={};
set<int> rules[N]={};
bool vis[N]={},ins[N]={};
void init()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	{
		int tot=0,x=0;
		scanf("%d%d",&p[i].s,&tot);
		rules[p[i].s].insert(i);
		while(tot--)
		{
			scanf("%d",&x);
			if(x==-1)
				++p[i].w;
			else
				p[i].v.push_back(x);
		}
	}
}
void get_minv()
{
	fill(dis+1,dis+n+1,Inf);
	priority_queue<pair<int,int> >q;
	multiset<int> s1[M]={},s2[N]={};
	long long tmpmin[M]={};
	for(int i=1;i<=m;++i)
		tmpmin[i]=p[i].w;
	bool v[N]={};
	for(int i=1;i<=m;++i)
		if(p[i].v.empty())
		{
			dis[p[i].s]=min(dis[p[i].s],1ll*p[i].w);
			q.push({-dis[p[i].s],p[i].s});
		}
		else
		{
			s1[i].insert(p[i].v.begin(),p[i].v.end());
			for(auto tmp:p[i].v)
				s2[tmp].insert(i);
		}
	while(!q.empty())
	{
		auto now=q.top();
		q.pop();
		if(v[now.second])
			continue;
		v[now.second]=true;
		for(auto next:s2[now.second])
		{
			tmpmin[next]+=-now.first;
			s1[next].erase(s1[next].find(now.second));
			if(s1[next].empty())
			{
				dis[p[next].s]=min(dis[p[next].s],tmpmin[next]);
				q.push({-dis[p[next].s],p[next].s});
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(dis[i]==Inf)
			dis[i]=maxv[i]=-1;
}
void dfs(int s)
{
	if(vis[s] || ins[s])
		return;
	vis[s]=true;
	ins[s]=true;
	for(auto now : rules[s])
	{
		long long sum=p[now].w;
		for(auto tmp : p[now].v)
			if(maxv[tmp]==-1)
			{
				sum=-1;
				break;
			}
		if(sum==-1)
			continue;
		for(auto tmp : p[now].v) 
		{
			dfs(tmp);
			if(ins[tmp] || maxv[tmp]==Inf)
			{
				sum=Inf;
				break;
			}
			sum+=maxv[tmp];
		}
		maxv[s]=max(maxv[s],sum);
	}
	ins[s]=false;
	return;
}
void get_maxv()
{
	for(int i=1;i<=n;++i)
		if(maxv[i]!=-1 && !vis[i])
			dfs(i);
	for(int i=1;i<=n;++i)
		if(maxv[i]==Inf)
			maxv[i]=-2;
	for(int i=1;i<=n;++i)
		printf("%I64d %I64d\n",min(dis[i],ansmax),min(maxv[i],ansmax));
}
int main()
{	
	init();
	get_minv();
	get_maxv();
	return 0;
}