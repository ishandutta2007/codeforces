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

vi adj[1050000];
unordered_map<int,int> del[1050000];

vi storage[501111];

ll hsh(int u, int v)
{
	return (u*1050000LL+v);
}

void clean(int u)
{
	while(!adj[u].empty())
	{
		int v=adj[u].back();
		if(del[v].count(u))
		{
			del[v][u]--;
			if(del[v][u]==0) del[v].erase(u);
			adj[u].pop_back();
		}
		else break;
	}
}

bool vis[1111111];
void dfs(int u)
{
	vis[u]=1;
	for(int v:adj[u])
	{
		if(!vis[v]) dfs(v);
	}
}

bool check(vector<ii> &vec)
{
	int n=vec.size();
	int mx=0;
	for(int i=0;i<vec.size();i++)
	{
		int u=vec[i].fi; int v=vec[i].se;
		mx=max(mx,u); mx=max(mx,v);
	}
	for(int i=0;i<=mx;i++) 
	{
		del[i].clear(); adj[i].clear(); vis[i]=0;
	}
	for(int i=0;i<vec.size();i++)
	{
		int u=vec[i].fi; int v=vec[i].se;
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i=0;i<=mx;i++)
	{
		if(int(adj[i].size())&1) return {};
	}
	int cc=0;
	for(int i=0;i<=mx;i++) 
	{
		if(adj[i].empty()) continue;
		if(!vis[i])
		{
			cc++; dfs(i);
			if(cc>=2) return false;
		}
	}
	return true;
}

vi solve(vector<ii> &vec)
{
	//cerr<<"SOLVE\n";
	int n=vec.size();
	int mx=0;
	unordered_map<ll,int> ma;
	for(int i=0;i<vec.size();i++)
	{
		int u=vec[i].fi; int v=vec[i].se;
		mx=max(mx,u); mx=max(mx,v);
	}
	for(int i=0;i<=mx;i++) 
	{
		del[i].clear(); adj[i].clear();
	}
	for(int i=0;i<=n;i++)
	{
		storage[i].clear();
	}
	for(int i=0;i<vec.size();i++)
	{
		int u=vec[i].fi; int v=vec[i].se;
		adj[u].pb(v); adj[v].pb(u);
		if(!ma.count(hsh(u,v)))
		{
			int siz=ma.size();
			ma[hsh(u,v)]=siz;
		}
		storage[ma[hsh(u,v)]].pb(i);
		//ma[{u,v}].pb(i);
		//cerr<<"EDGE "<<u<<' '<<v<<'\n';
	}
	for(int i=0;i<=mx;i++)
	{
		if(int(adj[i].size())&1) return {};
	}
	//all degrees are even
	int s = 0;
	while(adj[s].empty()) s++; //choose a good starting vertex
	stack<int> st;
    st.push(s);
    vector<int> res;
    while (!st.empty()) 
    {
        int v = st.top();
        clean(v);
        if(adj[v].empty())
        {
			res.pb(v); st.pop();
		}
		else
		{
			int u=adj[v].back();
			adj[v].pop_back();
			del[v][u]++;
			st.push(u);
		}
    }
	for(int i=0;i<=mx;i++)
	{
		clean(i);
		if(!adj[i].empty()) return {};
	}
	//possible eulerian path!
	assert(res.size()==n+1);
	vi ans;
	for(int i=0;i<n;i++)
	{
		int u=res[i]; int v=res[i+1];
		int sw=0;
		if(!ma.count(hsh(u,v))) 
		{
			sw=1; swap(u,v);
		}
		int id=ma[hsh(u,v)];
		int realid=storage[id].back(); storage[id].pop_back();
		if(sw)
		{
			ans.pb(2*realid+1); ans.pb(2*realid);
		}
		else 
		{
			ans.pb(2*realid); ans.pb(2*realid+1);
		}
		if(storage[id].empty()) ma.erase(hsh(u,v));
	}
	return ans;
}

int val[1001111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y; vec.pb({x,y});
		val[i*2]=x; val[i*2+1]=y;
	}
	int lo=0; int hi=20;
	int ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		vector<ii> v(n);
		for(int i=0;i<n;i++)
		{
			int x=vec[i].fi; int y=vec[i].se;
			v[i].fi=(x&((1<<mid)-1));
			v[i].se=(y&((1<<mid)-1));
		}
		if(!check(v))
		{
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
			ans=mid;
		}
	}
	vector<ii> v(n);
	for(int i=0;i<n;i++)
	{
		int x=vec[i].fi; int y=vec[i].se;
		v[i].fi=(x&((1<<ans)-1));
		v[i].se=(y&((1<<ans)-1));
	}
	vi ansseq = solve(v);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
	{
		int l=val[ansseq[i*2-1]]; int r=val[ansseq[(i*2)%(2*n)]];
		assert(((l^r)&((1<<ans)-1))==0);
	}
	for(int i=0;i<2*n;i++)
	{
		cout<<ansseq[i]+1;
		if(i+1<2*n) cout<<' ';
	}
	cout<<'\n';
}