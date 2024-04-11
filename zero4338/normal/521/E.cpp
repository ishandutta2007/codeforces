#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,m;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int fa[maxn],dep[maxn];
	vector<pair<int,int>>dfs(int u,int f)
	{
		fa[u]=f;dep[u]=dep[f]+1;
		vector<pair<int,int>>ret;
		for(int &i:e[u])
		{
			if(i==f)continue;
			if(!dep[i])
			{
				auto tmp=dfs(i,u);
				for(auto &j:tmp)if(j.second!=u)ret.push_back(j);
			}
			else if(dep[i]<dep[u])ret.push_back({u,i});
		}
		if(ret.size()>=2)
		{
			puts("YES");
			if(dep[ret[0].second]<dep[ret[1].second])swap(ret[0],ret[1]);
			vector<int>ans0,ans1,ans2;
			int now=u;
			while(now!=ret[0].second){ans0.push_back(now);now=fa[now];}ans0.push_back(now);
			now=ret[0].first;
			while(now!=u){ans1.push_back(now);now=fa[now];}ans1.push_back(now);
			reverse(ans1.begin(),ans1.end());ans1.push_back(ret[0].second);
			now=ret[1].first;
			while(now!=u){ans2.push_back(now);now=fa[now];}ans2.push_back(now);
			reverse(ans2.begin(),ans2.end());
			vector<int>tmp;
			now=ret[0].second;
			while(now!=ret[1].second){tmp.push_back(now);now=fa[now];}tmp.push_back(now);
			reverse(tmp.begin(),tmp.end());
			ans2.insert(ans2.end(),tmp.begin(),tmp.end());
			printf("%lu ",ans0.size());for(int &i:ans0)printf("%d ",i);putchar('\n');
			printf("%lu ",ans1.size());for(int &i:ans1)printf("%d ",i);putchar('\n');
			printf("%lu ",ans2.size());for(int &i:ans2)printf("%d ",i);putchar('\n');
			exit(0);
		}
		return ret;
	}
}o;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)o.add(read(),read());
	for(int i=1;i<=n;i++)if(!o.dep[i])o.dfs(i,0);
	puts("NO");
	return 0;
}