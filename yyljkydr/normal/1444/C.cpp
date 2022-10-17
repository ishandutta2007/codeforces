#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int n,m,k;

int t[N];

vector<int>g[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii e[N];

int bel[N],col[N],ok[N];

void dfs(int x)
{
	for(auto v:g[x])
	{
		if(t[v]!=t[x])
			continue;
		if(!bel[v])
		{
			col[v]=col[x]^1;
			bel[v]=bel[x];
			dfs(v);
		}
		else
			ok[t[x]]&=col[x]^col[v];
	}
}

int lk[N][2][2];

map<pii,int>id;

int tot;

bool cmp(pii a,pii b)
{
	return t[a.fs]<t[b.fs]||(t[a.fs]==t[b.fs]&&t[a.sd]<t[b.sd]);
}

int vis[N];

int chk(int x)
{
	int ret=1;
	for(auto v:g[x])
	{
		if(vis[v]==-1)
		{
			vis[v]=vis[x]^1;
			ret&=chk(v);
		}
		else
			ret&=(vis[v]^vis[x]);
	}
	return ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>t[i];
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].fs>>e[i].sd;
		if(t[e[i].fs]>t[e[i].sd])
			swap(e[i].fs,e[i].sd);
		g[e[i].fs].push_back(e[i].sd);
		g[e[i].sd].push_back(e[i].fs);
	}
	fill(ok+1,ok+k+1,1);
	for(int i=1;i<=n;i++)
		if(!bel[i])
			bel[i]=i,dfs(i);
	int nk=0;
	for(int i=1;i<=k;i++)
		if(!ok[i])
			nk++;
	int ans=(k-nk)*(k-nk-1)/2;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		g[i].clear();
	fill(vis+1,vis+n*2+1,-1);
	for(int i=1,j=1;i<=m;i=j+1)
	{
		while(j+1<=m&&!cmp(e[i],e[j+1])&&!cmp(e[j+1],e[i]))
			j++;
		if(!ok[t[e[i].fs]]||!ok[t[e[i].sd]])
			continue;
		++tot;
		set<int>ver;
		for(int k=i;k<=j;k++)
		{
			int u=e[k].fs,v=e[k].sd;
			int bu=bel[u],bv=bel[v];
			int nu=bu+col[u]*n,nv=bv+col[v]*n;
			g[nu].push_back(nv);
			g[nv].push_back(nu);
			ver.insert(bu);
			ver.insert(bv);
		}
		for(auto x:ver)
			g[x].push_back(x+n),g[x+n].push_back(x);
		int tok=1;
		for(auto x:ver)
			if(vis[x]==-1)
				vis[x]=0,tok&=chk(x);
		ans-=!tok;
		for(auto x:ver)
		{
			g[x].clear(),g[x+n].clear();
			vis[x]=vis[x+n]=-1;
		}
	}
	cout<<ans<<endl;
}