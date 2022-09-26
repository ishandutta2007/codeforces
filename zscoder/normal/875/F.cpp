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

int par[211111];
int bad[211111];

int rt(int u)
{
	if(par[u]<0) return u;
	else return (par[u]=rt(par[u]));
}

void merge(int u, int v)
{
	u=rt(u); v=rt(v);
	if(u==v) return ;
	if(rand()&1) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	bad[u]|=bad[v];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(par,-1,sizeof(par));	
	int n,m; cin>>n>>m;
	vector<pair<int,ii> > edges;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		int w; cin>>w;
		edges.pb(mp(w,mp(u,v)));
	}
	sort(edges.rbegin(),edges.rend());
	int ans = 0;
	for(int i=0;i<m;i++)
	{
		int u=edges[i].se.fi; int v=edges[i].se.se;
		int w=edges[i].fi;
		u=rt(u); v=rt(v);
		if(u!=v)
		{
			if(bad[u]&&bad[v]) continue;
			merge(u,v);
			ans+=w;
		}
		else
		{
			if(!bad[u])
			{
				bad[u]=1;
				ans+=w;
				continue;
			}
		}
	}
	cout<<ans<<'\n';
}