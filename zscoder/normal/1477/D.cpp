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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<int> adj[555555];
int p[555555];
int q[555555];
set<int> adj2[555555];

void rem_edge(int u, int v)
{
	adj[u].erase(v); adj[v].erase(u);
}

void clr(int u)
{
	for(int v:adj[u]) adj[v].erase(u);
	adj[u].clear();
}

vector<vi> stars;
set<ii> S;

void redge2(int u, int v)
{
	S.erase({adj2[u].size(),u});
	S.erase({adj2[v].size(),v});
	adj2[u].erase(v); adj2[v].erase(u);
	S.insert({adj2[u].size(),u});
	S.insert({adj2[v].size(),v});
}

void solve()
{
	stars.clear();
	int n,m; cin>>n>>m;
	S.clear();
	vector<ii> Q;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; Q.pb({u,v});
		adj[u].insert(v); adj[v].insert(u);
	}
	for(int i=0;i<n;i++) p[i]=q[i]=-1;
	int curv = 0;
	vi bad; vi good;
	for(int i=0;i<n;i++)
	{
		if(adj[i].size()==n-1)
		{
			p[i]=q[i]=curv;
			curv++;
			bad.pb(i);
		}
	}
	for(int x:bad) clr(x);
	//now every vertex has at least codegree 1
	//step 2: build a forest
	for(int i=0;i<n;i++)
	{
		if(p[i]==-1)
		{
			good.pb(i);
		}
	}
	for(int i:good)
	{
		int smallest=-1;
		for(int j:good)
		{
			if(i==j) continue;
			if(adj[i].find(j)==adj[i].end()) //not an edge
			{
				smallest=j; break;
			}
		}
		//cerr<<"ADD EDGE "<<i<<' '<<smallest<<endl;
		assert(smallest!=-1);
		adj2[smallest].insert(i); adj2[i].insert(smallest);
	}
	//graph built, now to form stars!
	for(int v:good) S.insert({adj2[v].size(),v});
	//cerr<<"GOOD SIZE = "<<good.size()<<'\n';
	while(!S.empty())
	{
		int siz = (*S.begin()).fi; int u = (*S.begin()).se;
		if(siz>=2)
		{
			int v=(*adj2[u].begin());
			redge2(u,v); continue; //do until become leaf
		}
		vi newstar;
		//cerr<<siz<<' '<<u<<'\n';
		assert(siz==1);
		int v = (*adj2[u].begin());
		vi child;
		for(int w:adj2[v]) child.pb(w);
		for(int w:child)
		{
			redge2(v,w);
		}
		assert(S.find({0,v})!=S.end());
		S.erase({0,v}); newstar.pb(v);
		for(int w:child)
		{
			if(adj2[w].empty())
			{
				newstar.pb(w);
				S.erase({0,w});
			}
		}
		stars.pb(newstar);
	}
	//first guy in new star in the star	
	for(auto &v:stars)
	{
		/*
		for(int x:v) cerr<<x<<' ';
		cerr<<'\n';
		cerr<<"CURV = "<<curv<<'\n';
		*/
		for(int i=0;i<v.size();i++)
		{
			p[v[i]]=curv+i;
		}
		for(int i=1;i<v.size();i++)
		{
			q[v[i]]=curv+i-1;
		}
		q[v[0]]=curv+int(v.size())-1;
		curv+=v.size();
	}
	for(int i=0;i<n;i++)
	{
		cout<<p[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<q[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
	//cout<<endl;
	for(ii e:Q)
	{
		int a = (p[e.fi]>p[e.se]);
		int b = (q[e.fi]>q[e.se]);
		assert(a==b);
	}
	
	sort(p,p+n); sort(q,q+n);
	for(int i=0;i<n;i++)
	{
		assert(p[i]==i); assert(q[i]==i);
	}
	for(int i=0;i<n;i++) 
	{
		adj2[i].clear();
		adj[i].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}