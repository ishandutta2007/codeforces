#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define PII pair<int,int>
#define iter set<int>::iterator 
#define sz(x) (int)(x.size())
#define pb push_back
#define mk make_pair
#define rd (rand())
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e6+5,inf=1e9;
int n,Q,s,d;
int a[maxn];
set<int>S;
int fa[maxn],mp[maxn];
inline void input()
{
	n=gi(),Q=gi(),s=gi(),d=gi();
	FOR(i,1,n)a[i]=gi(),mp[a[i]]=i;
}
int ans[maxn];
vector<int>v[maxn];
vector<pair<int,int>>e[maxn];
inline void dfs(int u,int fa)
{
	for(auto x:e[u])
	{
		int v=x.first,w=x.second;
		if(v==fa)continue;
		ans[v]=max(ans[u],w);
		dfs(v,u);
	}
}
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
inline void solve()
{
	FOR(i,1,n)fa[i]=i;	
	FOR(i,1,n)S.insert(a[i]),v[i].pb(i);
	//FOR(i,1,n)printf("fa[%d]=%d\n",i,fa[i]);
	while(1)
	{
		int cnt=0;
		FOR(i,1,n)cnt+=get(i)==i;
		//FOR(i,1,n)printf("fa[%d]=%d\n",i,fa[i]);
		if(cnt==1)break;
		vector<pair<pair<int,int>,int>>edges;
		FOR(i,1,n)
		{
			if(i==get(i))
			{
				for(int x:v[i])S.erase(a[x]);
				pair<int,pair<int,int>>best={inf,{0,0}};
				for(int x:v[i])
				{
					auto it=S.lower_bound(a[x]+d);
					if(it!=S.end())best=min(best,{abs(d-abs((*it)-a[x])),{x,mp[(*it)]}});
					if(it!=S.begin())it--,best=min(best,{abs(d-abs((*it)-a[x])),{x,mp[(*it)]}});
					it=S.lower_bound(a[x]-d);
					if(it!=S.end())best=min(best,{abs(d-abs((*it)-a[x])),{x,mp[(*it)]}});
					if(it!=S.begin())it--,best=min(best,{abs(d-abs((*it)-a[x])),{x,mp[(*it)]}});
				}
				if(best.first!=inf)
				{
					//int node=get(best.second.second);fa[i]=node;
					//cerr<<i<<' '<<node<<endl;
					//if(sz(v[i])>sz(v[node]))swap(v[i],v[node]);
					//for(int x:v[i])v[node].pb(x);
					//int node=best.second.second;
					edges.pb({{best.second.first,best.second.second},best.first});
					//e[node].pb({best.second.first,best.first});
					//e[best.second.first].pb({node,best.first});
				}
				for(int x:v[i])S.insert(a[x]);
			}
		}
		//cerr<<sz(edges)<<endl;
		for(auto x:edges)
		{
			int u=x.first.first,node=x.first.second,w=x.second;
			if(get(u)==get(node))continue;
			e[u].pb({node,w}),e[node].pb({u,w});
			u=get(u),node=get(node);
			fa[get(u)]=get(node);
			if(sz(v[u])>sz(v[node]))swap(v[u],v[node]);
			for(int y:v[u])v[node].pb(y);
			//cerr<<sz(edges)<<endl;
		}
	}
	/*FOR(i,1,n)
	{
		for(auto x:e[i])
		{
			printf("%d %d %d\n",i,x.first,x.second);
		}
	}*/
	dfs(s,0);
	//FOR(i,1,n)printf("ans[%d]=%d\n",i,ans[i]);
	while(Q--)
	{
		int u=gi(),k=gi();
		ans[u]<=k?puts("Yes"):puts("No");
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	input();
	solve();
	return 0;
}