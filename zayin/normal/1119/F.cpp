#include<bits/stdc++.h>
#define maxn 250050
using namespace std;
typedef long long LL;

int n;
int D,deg[maxn];

int nxt[maxn];
vector<int> vert[maxn];

struct Edge	{
	int w,j;
	Edge(int _w=0,int _j=0)	{
		w=_w,j=_j;
	}
	bool operator < (const Edge& E)	const	{
		return deg[j]<deg[E.j];
	}
}	;
vector<Edge> G[maxn];
int cur[maxn];

int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}

void join(int u,int v,int w)	{
	++deg[u]; G[u].emplace_back(w,v);
	++deg[v]; G[v].emplace_back(w,u);
}

void init()	{
	scanf("%d",&n);
	LL res=0;
	for (int k=1;k<n;++k)	{
		int u=read(),v=read(),w=read();
		join(u,v,w);
		res+=w;
	}
	
	for (int i=1;i<=n;++i)
		sort(G[i].begin(),G[i].end());
	for (int i=1;i<=n;++i)
		vert[deg[i]].push_back(i);
	nxt[n]=n+1;
	for (int i=n-1;i;--i)
		nxt[i]=vert[i+1].size()?i+1:nxt[i+1];
	printf("%lld ",res);
}

bool vis[maxn];

LL sum[maxn];
multiset<LL,greater<LL> > s[maxn];//multiset

LL dp[maxn][2];

LL cnt=0;

void dfs(int i)	{
	vis[i]=1;
	while (cur[i]<G[i].size()&&deg[G[i][cur[i]].j]<D)	++cur[i];
	
	int del=deg[i]-D+1;
	while (s[i].size()>del)	sum[i]-=*s[i].begin(),s[i].erase(s[i].begin());
	
	vector<LL> ins;
	dp[i][0]=dp[i][1]=0;
	for (int k=cur[i],j;k<G[i].size();++k)	{
		++cnt;
		if (vis[j=G[i][k].j])	continue;
		dfs(j);
		dp[i][0]+=dp[j][0];
		LL t=dp[j][1]+G[i][k].w-dp[j][0];
		ins.push_back(t);
		sum[i]+=t,s[i].insert(t);
	}

	dp[i][0]+=sum[i];
	auto it=s[i].begin();
	for (int j=0;j+del<s[i].size()&&*it>0;++j)//*it>0
		dp[i][0]-=*(it++);
	dp[i][1]=min(dp[i][0],dp[i][0]-*it);
	for (LL w:ins)
		sum[i]-=w,s[i].erase(s[i].find(w));
	//sub from set
	
}

void solve()	{
	for (D=2;D<=n;++D)	{
		for (int i:vert[D-1])	{
			vis[i]=1;
			for (Edge E:G[i])	{
				if (vis[E.j])	continue;
				sum[E.j]+=E.w;
				s[E.j].insert(E.w);
			}
		}
			
		LL ans=0;
		for (int d=D;d<=n;d=nxt[d])
			for (int i:vert[d])	{
				if (vis[i])	continue;
				dfs(i);
				ans+=dp[i][0];
			}
		printf("%lld ",ans);
		for (int d=D;d<=n;d=nxt[d])
			for (int i:vert[d])
				vis[i]=0;
	} 
}

int main()	{
	init();
	solve();
	return 0;
}