#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

map<ii,ld> ma;
vi adj[100001];
vi vec[100001];
vector<ll> pref[100001];
int diam[100001];
bool visited[100001];
int idx[100001];
int h[100001];
vi dp[100001];
int ecc[100001];
vi clr;
int cc;

void dfs1(int u, int p)
{
	visited[u]=1;
	idx[u]=cc;
	clr.pb(u);
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		dfs1(v,u);
		h[u]=max(h[u],h[v]+1);
	}
}

void calcdp(int u, int p)
{
	int max1=-1; int idx=-1;
	int max2=-1;
	for(int j = 0; j < adj[u].size(); j++)
	{
		int v=adj[u][j];
		if(v==p) continue;
		if(h[v]>max1)
		{
			max2=max1;
			max1=h[v];
			idx=j;
		}
		else if(h[v]>max2)
		{
			max2=h[v];
		}
	}
	ecc[u]=max1+1;
	for(int j=0;j<adj[u].size();j++)
	{
		dp[u].pb(0);
		if(adj[u][j]==p) continue;
		if(j==idx)
		{
			dp[u].back() = (max2+1);
		}
		else
		{
			dp[u].back() = (max1+1);
		}
	}
	for(int j = 0; j < adj[u].size(); j++)
	{
		int v=adj[u][j];
		if(v==p) continue;
		calcdp(v,u);
	}
}

void dfs2(int u, int p, int child = -1)
{
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==p) continue;
		if(p!=-1)
		{
			dp[u][i]=max(dp[u][i],dp[p][child]+1);
		}
		ecc[v] = max(ecc[v], dp[u][i]+1);
		dfs2(v,u,i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<m;i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs1(i,-1);
			calcdp(i,-1);
			ecc[i]=h[i];
			dfs2(i,-1);
			cc++;
			clr.clear();
		}
	}
	for(int i = 0; i < n; i++)
	{
		int lab = idx[i];
		//cerr<<i<<' '<<lab<<' '<<h[i]<<' '<<ecc[i]<<'\n';
		vec[lab].pb(ecc[i]);
		diam[lab]=max(diam[lab],ecc[i]);
	}
	for(int i = 0; i < cc; i++)
	{
		sort(vec[i].begin(),vec[i].end());
		pref[i].resize(int(vec[i].size()));
		pref[i][0]=vec[i][0];
		for(int j=1;j<vec[i].size();j++)
		{
			pref[i][j]=pref[i][j-1]+vec[i][j];
		}
	}
	for(int i = 0; i < q; i++)
	{
		int u, v; cin>>u>>v;
		u--; v--;
		u=idx[u];v=idx[v];
		if(u==v)
		{
			cout<<-1<<'\n';
			continue;
		}
		ll n1 = vec[u].size(); ll n2 = vec[v].size();
		if(n1>n2)
		{
			swap(n1,n2);
			swap(u,v);
		}
		if(ma.find(mp(u,v))!=ma.end())
		{
			cout<<fixed<<setprecision(12)<<ma[mp(u,v)]<<'\n';
			continue;
		}
		ll D = max(diam[u],diam[v]);
		ll cnt=0;
		ll sum=0;
		for(int j=0;j<n1;j++)
		{
			int cur=vec[u][j];
			int z = upper_bound(vec[v].begin(),vec[v].end(),D-1-cur)-vec[v].begin();
			z--;
			if(z>=0)
			{
				sum+=pref[v][z];
				sum+=ll(z+1)*cur;
				cnt+=z+1;
			}
			else break;
		}
		ll ans = n2*pref[u][n1-1]+n1*pref[v][n2-1]+n1*n2;
		ans+=(D-1)*cnt;
		ans-=sum;
		ld res = ld(ans)/ld(n1*n2);
		ma[mp(u,v)]=res;
		cout<<fixed<<setprecision(12)<<res<<'\n';
	}
}