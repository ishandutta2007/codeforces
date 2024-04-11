#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=13;

int n,m,k;

int f[1<<N][N];

vector<int>p[2];

int g[N][N];

int dp()
{
	int all=(1<<(n/2))-1;
	for(int S=0;S<=all;S++)
		for(int i=0;i<n/2;i++)
			f[S][i]=0;
	for(int i=0;i<n/2;i++)
		f[1<<i][i]=1;
	for(int S=0;S<=all;S++)
		for(int i=0;i<n/2;i++)
			if(f[S][i])
			{
				for(int j=0;j<n/2;j++)
					if(!(S&(1<<j))&&((g[p[0][i]][p[0][j]]&&g[p[1][i]][p[1][j]])||(g[p[0][i]][p[1][j]]&&g[p[1][i]][p[0][j]])))
						f[S|(1<<j)][j]=1;
			}
	for(int i=0;i<n/2;i++)
		if(f[all][i]&&g[p[0][i]][p[1][i]])
			return 1;
	return 0;
}

bool vis[N];

unordered_map<int,bool>ok;

int getha()
{
	int ret=0;
	for(int i=0;i<n/2;i++)
		for(int j=0;j<2;j++)
			ret=ret*n+p[j][i];
	return ret;
}

void dfspair(int x)
{
	if(x==n)
	{
		if(!dp())
			return;
		ok[getha()]=1;
		return;
	}
	if(vis[x])
	{
		dfspair(x+1);
		return;
	}
	for(int i=x+1;i<n;i++)
	{
		if(vis[i])
			continue;
		vis[x]=vis[i]=1;
		p[0].push_back(x);
		p[1].push_back(i);
		dfspair(x+1);
		p[0].pop_back();
		p[1].pop_back();
		vis[x]=vis[i]=0;
	}
}

vector<vector<int> >group;

int cnt[2];

int ans;

int A(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	int ret=1;
	for(int i=n;i>=n-m+1;i--)
		ret*=i;
	return ret;
}

bool cmp(const vector<int>&a,const vector<int>&b)
{
	return a[0]<b[0];
}

map<vector<vector<int> >,bool>mem;

bool chk(vector<vector<int> >group)
{
    sort(group.begin(),group.end(),cmp);
	if(mem.count(group))
		return mem[group];
	if(group.size()==n/2)
	{
		p[0].clear(),p[1].clear();
		for(int i=0;i<n/2;i++)
			p[0].push_back(group[i][0]),p[1].push_back(group[i][1]);
		if(!ok.count(getha()))
			return 0;
		return 1;
	}
	bool &ret=mem[group];
	for(int i=0;i<group.size();i++)
		if(group[i].size()>2)
		{
			auto rem=group[i];
			int x=group[i].back();
			for(int j=0;j<rem.size()-1;j++)
			{
				group[i].pop_back();
				group.push_back({group[i][j],x});
				group[i].erase(group[i].begin()+j);
				if(chk(group))
					return ret=1;
				group.pop_back();
				group[i]=rem;
			}
		}
	return ret=0;
}

void dfs(int x)
{
	if(n-x<cnt[1])
		return;
	if(x==n)
	{
		if(chk(group))
			ans+=A(k,group.size());
		return;
	}
	group.push_back({x});
	cnt[1]++;
	dfs(x+1);
	cnt[1]--;
	group.pop_back();
	for(int i=0;i<group.size();i++)
	{
		cnt[group[i].size()&1]--;
		group[i].push_back(x);
		cnt[group[i].size()&1]++;
		dfs(x+1);
		cnt[group[i].size()&1]--;
		group[i].pop_back();
		cnt[group[i].size()&1]++;
	}
}

signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		--u,--v;
		g[u][v]=g[v][u]=1;
	}
	dfspair(0);
	dfs(0);
	printf("%lld\n",ans);
}