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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

vi adj[511];
vector<ii> candidate;
bool vis[511];
int par[511];
int rt;
void dfs(int u)
{
	vis[u]=1;
	for(auto v : adj[u])
	{
		if(!candidate.empty()) continue;
		if(vis[v])
		{
			if(v!=rt) continue;
			candidate.pb(mp(u,v));
			int cur = u;
			while(cur!=v)
			{
				candidate.pb(mp(par[cur],cur));
				cur = par[cur];
			}
			return ;
		}
		else
		{
			par[v]=u;
			dfs(v);
		}
	}
}

struct SCC
{
	const int INF = int(1e9);
	vector<vector<int> > vec;
	int index;
	vector<int> idx;
	vector<int> lowlink;
	vector<bool> onstack;
	stack<int> s;
	vector<int> sccidx;
	int scccnt;
	vi topo;
	
	//lower sccidx means appear later
	void init(int n)
	{
		idx.assign(n,-1);
		index = 0;
		onstack.assign(n,0);
		lowlink.assign(n,INF);
		while(!s.empty()) s.pop();
		sccidx.assign(n,-1);
		scccnt = 0;
		vec.clear();
		vec.resize(n);
	}
	
	void reset(int n)
	{
		idx.assign(n,-1);
		index=0;
		onstack.assign(n,0);
		lowlink.assign(n,INF);
		while(!s.empty()) s.pop();
		sccidx.assign(n,-1);
		scccnt = 0;
	}
	void addedge(int u, int v) //u -> v
	{
		vec[u].pb(v);
	}
	
	void connect(int u)
	{
		idx[u] = index;
		lowlink[u] = index;
		index++;
		s.push(u);
		onstack[u] = true;
		for(int i = 0; i < vec[u].size(); i++)
		{
			int v = vec[u][i];
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
		for(int i = 0; i < vec.size(); i++)
		{
			if(idx[i] == -1)
			{
				connect(i);
			}
		}
	}
	
	void toposort() //if graph is a DAG and i just want to toposort
	{
		tarjan();
		int n = vec.size();
		topo.resize(n);
		vector<ii> tmp;
		for(int i = 0; i < n; i++)
		{
			tmp.pb(mp(sccidx[i],i));
		}
		sort(tmp.begin(),tmp.end());
		reverse(tmp.begin(),tmp.end());
		for(int i = 0; i < n; i++)
		{
			topo[i]=tmp[i].se;
			if(i>0) assert(tmp[i].fi!=tmp[i-1].fi);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	SCC scc; scc.init(n);
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--;
		scc.addedge(u,v);
		adj[u].pb(v);
	}
	for(int i=0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(par,-1,sizeof(par));
		rt=i;
		dfs(i);
	}
	if(candidate.empty())
	{
		cout<<"YES\n";
		return 0;
	}
	
	for(int i=0;i<candidate.size();i++)
	{
		int u=candidate[i].fi; int v=candidate[i].se;
		scc.reset(n);
		for(int j=0;j<scc.vec[u].size();j++)
		{
			int id=scc.vec[u][j];
			if(v==id)
			{
				scc.vec[u].erase(scc.vec[u].begin()+j);
				break;
			}
		}
		scc.tarjan();
		if(scc.scccnt==n)
		{
			cout<<"YES\n";
			return 0;
		}
		scc.vec[u].pb(v);
	}
	cout<<"NO\n";
}