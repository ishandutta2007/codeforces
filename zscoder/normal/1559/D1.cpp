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

const int MAXN1 = 250000;
const int MAXN2 = 250000;
const int MAXM = 250000;

int n1, n2, edges, last[MAXN1], pre[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) 
{
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) 
{
    head[edges] = v;
    pre[edges] = last[u];
    last[u] = edges++;
}

void bfs() 
{
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = pre[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) 
{
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = pre[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || ((!vis[u2] && dist[u2] == dist[u1] + 1) && dfs(u2))) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() 
{
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

set<ii> adj[222222];
set<ii> L,R;
int n,m1,m2; 

void deledge(int x, int y, int e)
{
	if(x>y) swap(x,y);
	L.erase({adj[x].size(),x});
	R.erase({adj[y].size(),y});
	adj[x].erase({y,e});
	adj[y].erase({x,e});
	if(!adj[x].empty())  L.insert({adj[x].size(),x});
	if(!adj[y].empty()) R.insert({adj[y].size(),y});
}

void addedge(int x, int y, int e)
{
	if(x>y) swap(x,y);
	L.erase({adj[x].size(),x});
	R.erase({adj[y].size(),y});
	adj[x].insert({y,e});
	adj[y].insert({x,e});
	if(!adj[x].empty()) L.insert({adj[x].size(),x});
	if(!adj[y].empty()) R.insert({adj[y].size(),y});
}

void merge(int u, int v)
{
	if(adj[u].size()<adj[v].size()) swap(u,v);
	//merge v to u
	vector<ii> neigh;
	for(auto x:adj[v])
	{
		neigh.pb(x);
	}
	for(auto x:neigh)
	{
		deledge(v,x.fi,x.se);
	}
	for(auto x:neigh)
	{
		addedge(u,x.fi,x.se);
	};
}

void solve()
{
	cin>>n>>m1>>m2;
	DSU dsu1(n);
	DSU dsu2(n);
	for(int i=0;i<m1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		dsu1.merge(u,v);
	}
	for(int i=0;i<m2;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		dsu2.merge(u,v);
	}
	map<ii,int> ma;
	//init(n+1,n+1);
	for(int i=0;i<n;i++)
	{
		//addEdge(dsu1.rt(i),dsu2.rt(i));
		ma[mp(dsu1.rt(i),dsu2.rt(i))]=i;
		adj[dsu1.rt(i)].insert({dsu2.rt(i)+n,i});
		adj[dsu2.rt(i)+n].insert({dsu1.rt(i),i});
		//cerr<<"EDGE: "<<dsu1.rt(i)<<' '<<dsu2.rt(i)<<'\n';
		//cerr<<dsu1.rt(i)<<' '<<dsu2.rt(i)<<": "<<i<<'\n';
	}
	//build adj le, now we check 
	
	for(int i=0;i<n;i++)
	{
		if(adj[i].size()>0) L.insert({adj[i].size(),i});
	}
	for(int i=n;i<2*n;i++)
	{
		if(adj[i].size()>0) R.insert({adj[i].size(),i});
	}
	
	//L and R exist, now ans is 
	int ans = int(min(L.size(),R.size()))-1;
	int cnt=0;
	cout<<ans<<'\n';
	while(int(min(L.size(),R.size()))>=2)
	{
		//cerr<<L.size()<<' '<<R.size()<<'\n';
		int u1 = (*L.begin()).se;
		int v1 = (*adj[u1].begin()).fi;
		int e1 = (*adj[u1].begin()).se;
		//cerr<<"FIRST: "<<u1<<' '<<v1-n<<' '<<e1<<'\n';
		//now, find the merging point
		if(L.size()<=R.size()) //find another 
		{
			bool pos=0;
			for(auto x:R)
			{
				int v2 = x.se;
				//cerr<<"VISIT: "<<v2<<'\n';
				if(v2==v1) continue;
				//find u2
				int u2=-1; int e2=-1;
				for(auto x:adj[v2])
				{
					if(x.fi!=u1)
					{
						u2=x.fi; e2=x.se; break;
					}
				}
				//cerr<<"R: "<<v2<<' '<<u2<<' '<<e2<<'\n';
				if(u2==-1) continue;
				//join u2,v2
				cnt++;
				cout<<e1+1<<' '<<e2+1<<'\n';
				merge(u1,u2);
				merge(v1,v2);
				pos=1;
				break;
			}
			if(!pos) assert(0);
		}
		else
		{
			bool pos=0;
			for(auto x:L)
			{
				int u2 = x.se;
				if(u2==u1) continue;
				//find u2
				int v2=-1; int e2=-1;
				for(auto x:adj[u2])
				{
					if(x.fi!=v1)
					{
						v2=x.fi; e2=x.se; break;
					}
				}
				//cerr<<"L: "<<u2<<' '<<v2-n<<' '<<e2<<'\n';
				if(v2==-1) continue;
				//join u2,v2
				cnt++;
				cout<<e1+1<<' '<<e2+1<<'\n';
				merge(u1,u2);
				merge(v1,v2);
				pos=1;
				break;
			}
			if(!pos) assert(0);
		}
	}
	assert(cnt==ans);
	/*
	int ans = maxMatching();
	cout<<ans-1<<'\n';
	vector<int> res;
	for(int i=0;i<n;i++)
	{
		if(matching[i]==-1) continue;
		//cerr<<"MATCH: "<<i<<' '<<matching[i]<<'\n';
		int nodeno = ma[mp(matching[i],i)];
		res.pb(nodeno);
	}
	assert(int(res.size())==ans);
	for(int i=1;i<res.size();i++)
	{
		cout<<res[0]+1<<' '<<res[i]+1<<'\n';
	}
	*/
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}