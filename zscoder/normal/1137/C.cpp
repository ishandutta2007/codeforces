#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int INF = int(1e9);
vi vec[101111];
int index;
int idx[5011111];
int lowlink[5011111];
bool onstack[5011111];
stack<int> s;
int sccidx[5011111];
int scccnt;

//lower sccidx means appear later

void addedge(int u, int v) //u -> v
{
	vec[u].pb(v);
}
const int C = 50;	
int n,m,d;

void connect(int u)
{
	if(u%C>=d) return ;
	if(u/C>=n) return ;
	idx[u] = index;
	lowlink[u] = index;
	index++;
	s.push(u);
	onstack[u] = true;
	int dd=u%C; int d2=(dd+1)%d;
	for(int v:vec[u/C])
	{
		v*=C; v+=d2;
		if(idx[v] == -1)
		{
			connect(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if(onstack[v])
		{
			lowlink[u] = min(lowlink[u], idx[v]);
		}
	}
	if(lowlink[u] == idx[u])
	{
		while(1)
		{
			int v = s.top();
			s.pop();
			onstack[v] = false;
			sccidx[v] = scccnt;
			if(v == u) break;
		}
		scccnt++;
	}
}

void tarjan()
{
	for(int i = 0; i < 50*100001; i++)
	{
		int u=i/C; int v=i%C;
		if(u>=n||v>=d) continue;
		if(idx[i] == -1)
		{
			connect(i);
		}
	}
}

int getid(int x, int y)
{
	return (x*C+y);
}

vi radj[111111];

ll bit[111111];
int cntscc[100011*C];
int dp[100011*C];
vector<ii> sorted;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>d;
	vector<pair<int,int> > edges;
	memset(idx,-1,sizeof(idx));
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; radj[v].pb(u);
		edges.pb({u,v});
		vec[u].pb(v);
	}	
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<d;j++)
		{
			if(s[j]=='1') bit[i]|=(1LL<<j);
		}
	}
	tarjan();
	for(int i=0;i<n;i++)
	{
		set<int> S;
		for(int j=0;j<d;j++)
		{
			//cerr<<"SCC IDX "<<i<<' '<<j<<' '<<sccidx[getid(i,j)]<<'\n';
			if(bit[i]&(1LL<<j))
			{
				S.insert(sccidx[getid(i,j)]);
			}
			//assert(sccidx[getid(i,j)]>=0&&sccidx[getid(i,j)]<=5100000);
			sorted.pb(mp(sccidx[getid(i,j)],getid(i,j)));
		}
		for(int s:S)
		{
			cntscc[s]++;
		}
	}
	sort(sorted.begin(),sorted.end());
	/*
	for(int i=0;i<m;i++)
	{
		int u=edges[i].fi; int v=edges[i].se;
		for(int j=0;j<d;j++)
		{
			int d2=j+1;
			if(d2>=d) d2-=d;
			int U=sccidx[getid(u,j)];
			int V=sccidx[getid(v,d2)];
			//cerr<<"U V "<<U<<' '<<V<<' '<<cntscc[U]<<' '<<cntscc[V]<<'\n';
			if(U!=V) adj[V].pb(U);
		}
	}
	*/
	int ptr=int(sorted.size())-1;
	int ans=0;
	for(int i=n*C;i>=0;i--)
	{
		dp[i]=-int(1e9);
	}
	//cerr<<sccidx[getid(0,0)]<<' '<<cntscc[sccidx[getid(0,0)]]<<'\n';
	dp[sccidx[getid(0,0)]]=0;
	for(int i=n*C;i>=0;i--)
	{
		/*
		for(int v:adj[i])
		{
			dp[i]=max(dp[i],dp[v]);
		}
		*/
		while(ptr>=0&&sorted[ptr].fi>i)
		{
			ptr--;
		}
		while(ptr>=0&&sorted[ptr].fi==i)
		{
			int u=sorted[ptr].se/C; int j=sorted[ptr].se%C;
			int d2=j-1;
			if(d2<0) d2+=d;
			for(int v:radj[u])
			{
				int U=sccidx[getid(v,d2)];
				if(U!=i&&U>=0&&U<100011*C) dp[i]=max(dp[i],dp[U]);
			}
			ptr--;
		}
		if(dp[i]>=0) dp[i]+=cntscc[i];
		ans=max(ans,dp[i]);
	}
	cout<<ans<<'\n';
}