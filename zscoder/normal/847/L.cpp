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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

vector<ii> edges;

struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

DSU dsu(1);

void addedge(int u, int v)
{
	if(dsu.sameset(u,v)) assert(0);
	dsu.merge(u,v);
	edges.pb(mp(u,v));
}

vector<set<int> > adj[1011];
bool used[1011];
int belong[1011][1011];
int cnt[1011];
vector<vi> F[1011];
vector<int> T[1011];
vector<vi> cc;
bool vis[1011];

void dfs(int u)
{
	vis[u]=1;
	cc.back().pb(u);
	for(int i=0;i<T[u].size();i++)
	{
		int v=T[u][i];
		if(!vis[v]) dfs(v);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(belong,-1,sizeof(belong));
	int n; cin>>n;
	dsu.reset(n);
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		int cur=0;
		int ptr=0;
		while(ptr<s.length())
		{
			//cerr<<s[ptr]<<'\n';
			cur=0;
			while(ptr<s.length()&&s[ptr]!=':')
			{
				cur*=10;
				cur+=s[ptr]-'0';
				ptr++;
			}
			ptr++;
			adj[i].pb(set<int>());
			F[i].pb(vi());
			int siz = cur;
			for(int j=0;j<siz;j++)
			{
				cur=0;
				while(ptr<s.length()&&(s[ptr]!=','&&s[ptr]!='-'))
				{
					cur*=10;
					cur+=s[ptr]-'0';
					ptr++;
				}
				ptr++;
				adj[i].back().insert(cur-1);
				//assert(cur-1!=i);
				belong[i][cur-1]=int(adj[i].size()) - 1;
				F[i].back().pb(cur-1);
			}
		}
		cnt[i]=adj[i].size();
	}
	/*
	cerr<<'\n';
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			cerr<<adj[i][j].size()<<":";
			for(auto it = adj[i][j].begin(); it !=adj[i][j].end(); it++)
			{
				cerr<<(*it);
				if(next(it)!=adj[i][j].end()) cerr<<",";
			}
			if(j+1<adj[i].size()) cerr<<"-";
		}
		cerr<<'\n';
	}
	*/
	for(int i=0;i<n-1;i++)
	{
		int leaf=-1;
		for(int j=0;j<n;j++)
		{
			if(used[j]) continue;
			if(cnt[j]==1)
			{
				leaf=j;
				break;
			}
		}
		if(leaf==-1)
		{
			cout<<-1<<'\n';
			return 0;
		}
		int u=-1;
		for(int j=0;j<n;j++)
		{
			if(used[j]) continue;
			int idx = belong[j][leaf];
			if(idx==-1) continue;
			if(adj[j][idx].size()==1)
			{
				if(u==-1) u=j;
				else u=-2;
			}
		}
		if(u<0)
		{
			cout<<-1<<'\n';
			return 0;
		}
		//cerr<<u<<' '<<leaf<<'\n';
		addedge(u,leaf);
		for(int j=0;j<n;j++)
		{
			if(used[j]) continue;
			int idx=belong[j][leaf];
			if(idx==-1) continue;
			if(adj[j][idx].size()==1)
			{
				cnt[j]--;
			}
			adj[j][idx].erase(leaf);
		}
		used[leaf]=1;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(edges[j].fi!=i&&edges[j].se!=i)
			{
				T[edges[j].fi].pb(edges[j].se);
				T[edges[j].se].pb(edges[j].fi);
			}
		}
		cc.clear();
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&j!=i)
			{
				cc.pb(vi());
				dfs(j);
			}
		}
		for(int j=0;j<cc.size();j++)
		{
			sort(cc[j].begin(),cc[j].end());
		}
		for(int j=0;j<F[i].size();j++)
		{
			sort(F[i][j].begin(),F[i][j].end());
		}
		//cerr<<i<<' '<<cc.size()<<' '<<F[i].size()<<'\n';
		if(cc.size()!=F[i].size())
		{
			cout<<-1<<'\n';
			return 0;
		}
		sort(cc.begin(),cc.end()); sort(F[i].begin(),F[i].end());
		for(int j=0;j<cc.size();j++)
		{
			/*
			for(int k=0;k<cc[j].size();k++)
			{
				cerr<<cc[j][k]<<' ';
			}
			cerr<<'\n';
			for(int k=0;k<F[i][j].size();k++)
			{
				cerr<<F[i][j][k]<<' ';
			}
			cerr<<'\n';
			*/
			if(cc[j]!=F[i][j])
			{
				cout<<-1<<'\n';
				return 0;
			}
		}
		for(int j=0;j<n;j++)
		{
			T[j].clear();
		}
		memset(vis,0,sizeof(vis));
	}
	
	cout<<n-1<<'\n';
	for(int i=0;i<n-1;i++)
	{
		cout<<edges[i].fi+1<<' '<<edges[i].se+1<<'\n';
	}
}