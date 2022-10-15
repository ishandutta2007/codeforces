#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e5+5;
int n,m;
int ans;
int w[maxn];
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	struct cmp{bool operator()(int x,int y){return w[x]==w[y]?x<y:w[x]<w[y];}};
	struct Data
	{
		multiset<int,cmp>val;int del;
		void merge(Data &x)
		{
			if(val.size()<x.val.size())swap(*this,x);
			for(int i:x.val)
			{
				w[i]+=x.del-del;
				val.insert(i);
			}
		}
		int query(){return w[*val.begin()]+del;}
		void insert(int x){w[x]-=del;val.insert(x);}
		void erase(int x){val.erase(x);}
		void add(int x){del+=x;}
	}s[maxn];
	vector<pair<int,int>>del[maxn];
	void dfs(int u,int fa)
	{
		for(int &i:e[u])
		{
			if(i==fa)continue;
			dfs(i,u);
			s[u].merge(s[i]);
		}
		for(auto &i:del[u])
		{
			if(i.second==1)
				s[u].erase(i.first);
			else
				s[u].insert(i.first);
		} 
		if(u==1)return;
		if(s[u].val.empty()){puts("-1");exit(0);}
		int val=s[u].query();
		ans+=val;s[u].add(-val);
	}
}o;
signed main()
{
	n=read();m=read();
	for(int i=1;i<=n-1;i++)o.add(read(),read());
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();w[i]=read();
		o.del[u].push_back({i,0});
		o.del[v].push_back({i,1});
	}
	o.dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}