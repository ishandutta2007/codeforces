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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pair<int,ii> , null_type, less<pair<int,ii> >, rb_tree_tag, tree_order_statistics_node_update> pbds2;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

vi weights;
pbds T[101111];
set<pair<ll,int> > small3; //smallest 3 

ll getsm(int u)
{
	if(T[u].size()<3) return -1;
	auto it=T[u].begin();
	ll ans=0;
	for(int i=0;i<3;i++)
	{
		ans+=it->fi;
		it++;
	}
	return ans;
}

void add(int u, int v, int w) //add edge from u->v with weight w
{
	ll sm = getsm(u);
	if(sm>=0) small3.erase({sm,u});
	T[u].insert({w,v});
	sm = getsm(u);
	if(sm>=0) small3.insert({sm,u});
}

pbds2 S;
map<ii,int> ma;

void del(int u, int v, int w) //add edge from u->v with weight w
{
	ll sm = getsm(u);
	if(sm>=0) small3.erase({sm,u});
	T[u].erase({w,v});
	sm = getsm(u);
	if(sm>=0) small3.insert({sm,u});
}

void addedge(int u, int v, int w)
{
	add(u,v,w);
	add(v,u,w);
	ma[{u,v}]=w; ma[{v,u}]=w; S.insert({w,{min(u,v),max(u,v)}});
}

void deledge(int u, int v)
{
	int w=ma[{u,v}];
	del(u,v,w);
	del(v,u,w);
	ma.erase({u,v}); ma.erase({v,u}); S.erase({w,{min(u,v),max(u,v)}});
}

ll solve()
{
	ll ans = ll(1e18);
	if(!small3.empty())
	{
		ans=min(ans,(*small3.begin()).fi);
	}
	//two disjoint edges
	auto x = (*S.begin());
	int w = x.fi; int u = x.se.fi; int v = x.se.se;
	const int C = 5;
	//try combo of 5*5 smallest edges
	{
		auto it = T[u].begin();
		for(int i=0;i<min(C,int(T[u].size()));i++)
		{
			auto it2 = T[v].begin();
			for(int j=0;j<min(C,int(T[v].size()));j++)
			{
				set<int> ss;
				//cerr<<u<<' '<<it->se<<" | "<<v<<' '<<it2->se<<"; SUM = "<<it->fi+it2->fi<<'\n';
				ss.insert(u); ss.insert(v); ss.insert(it->se); ss.insert(it2->se);
				if(ss.size()==4)
				{
					ans=min(ans,ll(it->fi+it2->fi));
				}
				it2++;
			}
			it++;
		}
	}
	//cerr<<"MIN PAIR = "<<u<<' '<<v<<": "<<w<<'\n';
	//use u-v and another disjoint edge
	int lo = w; int hi = min(ll(1e9)+1,ll(ans-w));
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		//is there an edge not equal to u-v with length <= mid?
		int tot = T[u].order_of_key({mid+1,-1})+T[v].order_of_key({mid+1,-1})-1; //number of edges from u and v that are <= mid
		int tot2 = S.order_of_key({mid,{int(1e9),int(1e9)}});
		if(tot2>tot) //more edges <= mid than the ones from u to v
		{
			ans=min(ans,ll(mid+w));
			hi=mid-1;
		}
		else lo=mid+1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		u--; v--;
		addedge(u,v,w);
	}
	int q; cin>>q;
	cout<<solve()<<'\n';
	for(int i=0;i<q;i++)
	{
		int ty; cin>>ty;
		if(ty)
		{
			int u,v,w; cin>>u>>v>>w; u--; v--;
			addedge(u,v,w);
		}
		else
		{
			int u,v; cin>>u>>v; u--; v--;
			deledge(u,v);
		}
		cout<<solve()<<'\n';
	}
}