#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

vector<int>g[N];

set<int>son[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>era,ins;

int du[N],dc;

void dfs(int x,int f)
{
	du[++dc]=x;
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		son[x].insert(v);
	}
	for(auto v:g[x])
	{
		if(v==f)
			continue;
		dfs(v,x);
	}
	if(son[x].size()==2)
	{
		if(!f)
			return;
		son[f].erase(x);
		era.push_back(mp(f,x));
	}
	else if(son[x].size()>2)
	{
		int dec=son[x].size()-2;
		if(f)
			son[f].erase(x),era.push_back(mp(f,x));
		for(int i=0;i<dec;i++)
			era.push_back(mp(x,*son[x].begin())),son[x].erase(son[x].begin());
	}
}

vector<int>ver;

vector<pii>chn;

int deg[N];

void getp(int x)
{
	ver.push_back(x);
	for(auto v:son[x])
	{
		++deg[v],++deg[x];
		getp(v);
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		dc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			g[i].clear(),son[i].clear(),deg[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		era.clear(),ins.clear();
		chn.clear();
		dfs(1,0);
		for(int x=1;x<=n;x++)
		{
			int i=du[x];
			if(!deg[i])
			{
				ver.clear();
				getp(i);
				pii tmp=mp(0,0);
				for(auto x:ver)
					if(deg[x]<=1)
					{
						if(!tmp.fs)
							tmp.fs=x;
						else
							tmp.sd=x;
					}
				if(!tmp.sd)
					tmp.sd=tmp.fs;
				chn.push_back(tmp);
			}
		}
		for(int i=0;i+1<chn.size();i++)
			ins.push_back(mp(chn[i].sd,chn[i+1].fs));
		printf("%d\n",era.size());
		for(int i=0;i<ins.size();i++)
			printf("%d %d %d %d\n",era[i].fs,era[i].sd,ins[i].fs,ins[i].sd);
	}
}