#include<bits/stdc++.h>
using namespace std;
int tot=0,T,n,dfn[300005],ed[300005],siz=0,ans=0,x;
int seq[300005];
int vis[300005],rem[300005];
vector<int>s[300005],s1[300005];
set<int>st;
void init()
{
	tot=0;
	for(int i=1;i<=n;i++)dfn[i]=ed[i]=seq[i]=vis[i]=rem[i]=0;
	siz=0;ans=0;
	st.clear();
	for(int i=1;i<=n;i++)s[i].clear(),s1[i].clear();
}
void dfs(int p)
{
	int id=dfn[p];
	set<int>::iterator it;
	it=st.lower_bound(id);
	if(it==st.end()||*it>ed[p])
	{
		if(it!=st.begin())
		{
			it--;
			if(ed[seq[*it]]>=id)
			{
				int v=seq[*it];
				vis[v]=0;
				siz--;
				rem[p]=v;
				st.erase(dfn[v]);
			}
		}
		vis[p]=1;
		siz++;
		st.insert(id);
	}
	ans=max(ans,siz);
	for(int i=0;i<s[p].size();i++)
	{
		int v=s[p][i];
		dfs(v);
	}
	if(vis[p])
	{
		siz--;
		vis[p]=0;
		st.erase(id);
		if(rem[p])
		{
			siz++;
			vis[rem[p]]=1;
			st.insert(dfn[rem[p]]);
		}
	}
}
void dfs1(int p)
{
	dfn[p]=ed[p]=++tot;
	seq[tot]=p;
	for(int i=0;i<s1[p].size();i++)
	{
		int v=s1[p][i];
		dfs1(v);
		ed[p]=ed[v];
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			s[x].push_back(i);
		}
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			s1[x].push_back(i);
		}
		dfs1(1);
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}