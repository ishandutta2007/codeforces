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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<pair<ii,int> > S;
map<int,ll> radj[123456];
map<int,ll> adj[122345];

void del(int u)
{
	int s1=adj[u].size(); int s2=radj[u].size();
	S.erase({{-min(s1,s2),-max(s1,s2)},u});
}

void add(int u)
{
	int s1=adj[u].size(); int s2=radj[u].size();
	//cerr<<u<<' '<<s1<<' '<<s2<<'\n';
	S.insert({{-min(s1,s2),-max(s1,s2)},u});
}

void del(int a, int b, int w)
{
	if(a==b) return ;
	//cerr<<"DEL: "<<a<<' '<<b<<' '<<w<<'\n';
	adj[a][b]-=w;
	radj[b][a]-=w;
	if(radj[b][a]==0)
	{
		del(a); del(b);
		adj[a].erase(b);
		radj[b].erase(a);
		add(a); add(b);
	}
}

void add(int a, int b, int w)
{
	if(a!=b) 
	{
		if(adj[a][b]==0)
		{
			del(a); del(b); 
			adj[a][b]+=w; radj[b][a]+=w;
			add(a); add(b);
		}
		else 
		{
			adj[a][b]+=w; radj[b][a]+=w;
		}
		
	}
}

void process(int a,int b, int c)
{
	ll w1 = adj[a][b];
	ll w2 = adj[b][c];
	if(w1<=w2)
	{
		del(a,b,w1);
		del(b,c,w1);
		add(a,c,w1);
	}
	else
	{
		del(a,b,w2);
		del(b,c,w2);
		add(a,c,w2);
	}
}

ll sum[111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; ll w; cin>>u>>v>>w; u--; v--;
		sum[u]-=w; sum[v]+=w;
		//adj[u][v]+=w; radj[v][u]+=w;
	}
	/*
	for(int i=0;i<n;i++)
	{
		add(i);
	}
	while((*S.begin()).fi.fi<0)
	{
		int u=(*S.begin()).se;
		int r=(*adj[u].begin()).fi;
		int l=(*radj[u].begin()).fi;
		//cerr<<l<<' '<<u<<' '<<r<<'\n';
		process(l,u,r);
	}
	vector<pair<int,ii> > vec;
	for(int u=0;u<n;u++)
	{
		for(auto X:adj[u])
		{
			if(X.se>0) vec.pb({X.se,{u,X.fi}});
			//cout<<u<<' '<<X.fi<<' '<<X.se<<'\n';
		}
	}
	*/
	vector<ii> V;
	for(int i=0;i<n;i++)
	{
		V.pb({sum[i],i});
	}
	sort(V.begin(),V.end());
	vector<pair<ll,ii> > vec;
	int l=0; int r=n-1;
	while(l<r)
	{
		if(V[l].fi==0){l++; continue;}
		if(V[r].fi==0){r--; continue;}
		assert(V[l].fi<0&&V[r].fi>0);
		if(abs(V[l].fi)<=abs(V[r].fi))
		{
			vec.pb({abs(V[l].fi),{V[l].se,V[r].se}});
			V[r].fi-=abs(V[l].fi);
			V[l].fi=0;
		}
		else
		{
			vec.pb({V[r].fi,{V[l].se,V[r].se}});
			V[l].fi+=V[r].fi;
			V[r].fi=0; 
		}
	}
	cout<<vec.size()<<'\n';
	for(auto X:vec)
	{
		cout<<X.se.fi+1<<' '<<X.se.se+1<<' '<<X.fi<<'\n';
	}
}