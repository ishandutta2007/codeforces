#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

set<ii> adj[222222];
//set<ii> L,R;
pbds L,R;
int n,m1,m2; 

void deledge(int x, int y, int e)
{
	if(x>y) swap(x,y);
	//L.erase({adj[x].size(),x});
	//R.erase({adj[y].size(),y});
	adj[x].erase({y,e});
	adj[y].erase({x,e});
	//if(!adj[x].empty()) L.insert({adj[x].size(),x});
	//if(!adj[y].empty()) R.insert({adj[y].size(),y});
}

void addedge(int x, int y, int e)
{
	if(x>y) swap(x,y);
	//L.erase({adj[x].size(),x});
	//R.erase({adj[y].size(),y});
	adj[x].insert({y,e});
	adj[y].insert({x,e});
	//if(!adj[x].empty()) L.insert({adj[x].size(),x});
	//if(!adj[y].empty()) R.insert({adj[y].size(),y});
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
	L.erase(v);R.erase(v);
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
	for(int i=0;i<n;i++)
	{
		adj[dsu1.rt(i)].insert({dsu2.rt(i)+n,i});
		adj[dsu2.rt(i)+n].insert({dsu1.rt(i),i});
	}
	//build adj le, now we check 
	
	for(int i=0;i<n;i++)
	{
		if(adj[i].size()>0) L.insert(i);
	}
	for(int i=n;i<2*n;i++)
	{
		if(adj[i].size()>0) R.insert(i);
	}
	
	//L and R exist, now ans is 
	int ans = int(min(L.size(),R.size()))-1;
	int cnt=0;
	cout<<ans<<'\n';
	while(int(min(L.size(),R.size()))>=2)
	{
		//cerr<<L.size()<<' '<<R.size()<<'\n';
		int rngsus,u1,v1,e1;
		
		if(L.size()<=R.size())
		{
			rngsus = rand()%int(L.size());
			u1 = (*L.find_by_order(rngsus));
			v1 = (*adj[u1].begin()).fi;
			e1 = (*adj[u1].begin()).se;
		}
		else
		{
			rngsus = rand()%int(R.size());
			v1 = (*R.find_by_order(rngsus));
			u1 = (*adj[v1].begin()).fi;
			e1 = (*adj[v1].begin()).se;
		}
		if(L.size()<=R.size()) //find another 
		{
			bool pos=0;
			for(auto x:R)
			{
				int v2 = x;
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
		}
		else
		{
			bool pos=0;
			for(auto x:L)
			{
				int u2 = x;
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
		}
	}
	assert(cnt==ans);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	int t=1;
	while(t--) solve();
}