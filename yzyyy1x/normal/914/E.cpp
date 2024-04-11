#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
int n,a[N],tot,root,minx,sz[N],dp[1<<20],cnt[1<<20];
vector<int>mp[N],trash,rem,P[1<<20];
bool vis[N];ll ans[N]={0};
void get_sz(int x,int fa)
{
	int nw=0;sz[x]=1;
	for(int i=0;i<mp[x].size();i++)
	{
		if(!vis[mp[x][i]]&&mp[x][i]!=fa)
		{
			get_sz(mp[x][i],x);
			sz[x]+=sz[mp[x][i]];
			nw=max(nw,sz[mp[x][i]]);
		}
	}
	nw=max(nw,tot-sz[x]);
	if(minx>nw)minx=nw,root=x;
}
void find(int x)
{minx=1e9;get_sz(x,-1);}
ll work(int x,int fa,int w)
{
	trash.push_back(w);ll nw=0;
	dp[w]++;if(cnt[w]<=1)nw++;
	for(int i=0;i<mp[x].size();i++)
	{
		if(!vis[mp[x][i]]&&mp[x][i]!=fa)
			nw+=work(mp[x][i],x,w^(1<<(a[mp[x][i]]-1)));
	}
	ans[x]+=nw;
	return nw;
}
void down(int x,int fa,int w)
{
	dp[w]--,rem.push_back(w);
	for(int i=0;i<mp[x].size();i++)
		if(!vis[mp[x][i]]&&mp[x][i]!=fa)down(mp[x][i],x,w^(1<<(a[mp[x][i]]-1)));
}
ll calc(int x,int fa,int w)
{
	ll nw=0;
	for(int i=0;i<P[w].size();i++)
		nw+=dp[P[w][i]];
	for(int i=0;i<mp[x].size();i++)
	{
		if(!vis[mp[x][i]]&&mp[x][i]!=fa)
			nw+=calc(mp[x][i],x,w^(1<<(a[mp[x][i]]-1)));
	}	
	ans[x]+=nw;
	return nw;
}
void solve(int x)
{
	vis[x]=1;int tmp=1<<(a[x]-1);ll tp=0;
	for(int i=0;i<trash.size();i++)
		dp[trash[i]]=0;
	trash.clear();	
	for(int i=0;i<mp[x].size();i++)	
		if(!vis[mp[x][i]])ans[x]+=work(mp[x][i],x,tmp^(1<<(a[mp[x][i]]-1)));
	for(int i=0;i<mp[x].size();i++)
	{
		if(!vis[mp[x][i]])
		{
			down(mp[x][i],x,tmp^(1<<(a[mp[x][i]]-1)));
			tp+=calc(mp[x][i],x,1<<(a[mp[x][i]]-1));
			for(register int j=0;j<rem.size();j++)
				dp[rem[j]]++;
			rem.clear();
		}	
	}
	ans[x]+=tp/2;
	for(int i=0;i<mp[x].size();i++)
	{
		if(!vis[mp[x][i]])
		{
			tot=sz[mp[x][i]];
			find(mp[x][i]);
			solve(root);
		}
	}
}
void init()
{
	cnt[0]=0;
	for(int i=0;i<(1<<20);i++)
	{
		for(int j=1;j<=20;j++)
		{
			if(i&(1<<(j-1)))continue;
			cnt[i|(1<<(j-1))]=cnt[i]+1;
		}
	}
	for(int i=0;i<(1<<20);i++)
	{
		for(int k=1;k<=20;k++)
			P[i].push_back(i^(1<<(k-1)));
		P[i].push_back(i);
	}
}
int main()
{
	string s;int u,v;
	init();
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	cin>>s;
	for(int i=0;i<s.length();i++)
		a[i+1]=s[i]-'a'+1;
	tot=n;find(1);solve(root);
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]+1);
}