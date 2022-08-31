#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 500005
#define ALP 30

using namespace std;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
int dep[SIZE],dp[SIZE];
vector <int> cmp;
int go[SIZE][ALP];
int nd[SIZE],id[SIZE];
int memo[SIZE];
int ans[SIZE];

void dfs(int v=0,int p=-1,int d=0,int f=0)
{
	dep[v]=d;
	cmp.push_back(f);
	dp[v]=f;
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			dfs(e.to,v,d+1,f^(1<<e.cost));
			nd[v]+=nd[e.to];
		}
	}
}
int get_id(int v,int t)
{
	if(go[v][t]!=-1) return go[v][t];
	int pos=lower_bound(cmp.begin(),cmp.end(),dp[v]^(1<<t))-cmp.begin();
	if(pos==cmp.size()||cmp[pos]!=(dp[v]^(1<<t))) go[v][t]=-2;
	else go[v][t]=pos;
	return go[v][t];
}
void dfs_clear(int v,int p)
{
	memo[id[v]]=-1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) dfs_clear(e.to,v);
	}
}
void dfs_ins(int v,int p)
{
	memo[id[v]]=max(memo[id[v]],dep[v]);
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) dfs_ins(e.to,v);
	}
}
int dfs_get(int v,int p)
{
	int ret=0;
	if(memo[id[v]]!=-1) ret=max(ret,dep[v]+memo[id[v]]);
	for(int i=0;i<26;i++)
	{
		int c=get_id(v,i);
		if(c!=-2&&memo[c]!=-1) ret=max(ret,dep[v]+memo[c]);
	}
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) ret=max(ret,dfs_get(e.to,v));
	}
	return ret;
}
void solve(int v=0,int p=-1)
{
	int mx=-1,pos=-1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p&&nd[e.to]>mx)
		{
			mx=nd[e.to];
			pos=e.to;
		}
	}
	if(pos==-1)
	{
		ans[v]=0;
		memo[id[v]]=dep[v];
		return;
	}
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p&&e.to!=pos)
		{
			solve(e.to,v);
			dfs_clear(e.to,v);
		}
	}
	solve(pos,v);
	if(memo[id[v]]==-1) memo[id[v]]=dep[v];
	else ans[v]=memo[id[v]]-dep[v];
	ans[v]=max(ans[v],ans[pos]);
	for(int i=0;i<26;i++)
	{
		int c=get_id(v,i);
		if(c!=-2&&memo[c]!=-1) ans[v]=max(ans[v],memo[c]-dep[v]);
	}
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p&&e.to!=pos)
		{
			ans[v]=max(ans[v],dfs_get(e.to,v)-dep[v]*2);
			ans[v]=max(ans[v],ans[e.to]);
			dfs_ins(e.to,v);
		}
	}
}
char str[10];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int p;
		scanf("%d %s",&p,&str);
		p--;
		int c=str[0]-'a';
		vec[p].push_back(edge(i+1,c));
		vec[i+1].push_back(edge(p,c));
	}
	memset(go,-1,sizeof(go));
	dfs();
	sort(cmp.begin(),cmp.end());
	cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
	for(int i=0;i<n;i++) id[i]=lower_bound(cmp.begin(),cmp.end(),dp[i])-cmp.begin();
	//for(int i=0;i<n;i++) printf("[%d %d %d]\n",dp[i],id[i],dep[i]);
	memset(memo,-1,sizeof(memo));
	solve();
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}