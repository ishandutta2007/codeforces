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

class LazySegmentTree {
private:
	int size_;
	vector<long long> v, lazy;
	void update(int a, int b, long long x, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			push(k, l, r);
		}
		else {
			update(a, b, x, k * 2, l, (l + r) >> 1);
			update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
			v[k] = merge(v[k * 2], v[k * 2 + 1]);
		}
	}
	long long query(int a, int b, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return v[k];
		long long lc = query(a, b, k * 2, l, (l + r) >> 1);
		long long rc = query(a, b, k * 2 + 1, (l + r) >> 1, r);
		return merge(lc, rc);
	}
 
public:
	LazySegmentTree() : v(vector<long long>()), lazy(vector<long long>()) {};
	LazySegmentTree(int n) {
		for (size_ = 1; size_ < n;) size_ <<= 1;
		v.resize(size_ * 2,1);
		lazy.resize(size_ * 2);
	}
	inline void push(int k, int l, int r) {
		if (lazy[k] != 0) {
			v[k] = max(v[k], lazy[k]);
			if (r - l > 1) {
				lazy[k * 2] = max(lazy[k*2], lazy[k]);
				lazy[k * 2 + 1] = max(lazy[k*2+1], lazy[k]);
			}
			lazy[k] = 0;
		}
	}
	inline long long merge(long long x, long long y) {
		return max(x, y);
	}
	inline void update(int l, int r, long long x) {
		update(l, r, x, 1, 0, size_);
	}
	inline long long query(int l, int r) {
		return query(l, r, 1, 0, size_);
	}
};

vi adj[555555];
int par[555555];
int downecc[555555];
int upecc[555555]; //eccen size
int maxh[555555];

void dfs(int u, int p)
{
	par[u]=p;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		maxh[u]=max(maxh[u],maxh[v]+1);
	}
}

void dfs2(int u, int p)
{
	int mx=-1; int mx2=-1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		downecc[v]=maxh[v]+1;
		if(downecc[v]>mx)
		{
			mx2=mx;
			mx=downecc[v];
		}
		else if(downecc[v]>mx2)
		{
			mx2=downecc[v];
		}
	}
	for(int v:adj[u])
	{
		if(v==p) continue;
		int best=mx;
		if(mx==downecc[v]) best=mx2;
		upecc[v]=max(1+best,1+upecc[u]);
		dfs2(v,u);
	}
}

vector<ii> G[555555];
int deg[555555];
int ans[555555];
map<int,int> ma[555555];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i=0;i<=n;i++) ans[i]=1;
	dfs(0,-1); dfs2(0,-1);
	int diam=0;
	for(int i=1;i<n;i++)
	{
		diam=max(diam,upecc[i]); diam=max(diam,downecc[i]);
		ma[i][-upecc[i]]++;
		ma[par[i]][-downecc[i]]++;
		//G[upecc[i]].pb({i,par[i]});
		//G[downecc[i]].pb({par[i],i});
		//downecc[i]++;
		//cerr<<i<<' '<<upecc[i]<<' '<<downecc[i]<<'\n';
	}
	ans[diam]=2;
	for(int i=1;i<n;i++)
	{
		int u=par[i]; int v=i;
		auto it1 = ma[u].begin();
		auto it2 = ma[v].begin();
		int cursum=-2;
		//cerr<<"EDGE "<<u<<' '<<v<<'\n';
		while(!(it1==ma[u].end()&&it2==ma[v].end()))
		{
			if(it1==ma[u].end())
			{
				cursum+=it2->se;
				//cerr<<"ADD: "<<it2->fi<<' '<<it2->se<<'\n';
				ans[-it2->fi*2]=max(ans[-it2->fi*2],cursum);
				it2++;
			}
			else if(it2==ma[v].end())
			{
				//cerr<<"ADD: "<<it1->fi<<' '<<it1->se<<'\n';
				cursum+=it1->se;
				ans[-it1->fi*2]=max(ans[-it1->fi*2],cursum);
				it1++;
			}
			else
			{
				if(it1->fi<=it2->fi)
				{
					//cerr<<"ADD: "<<it1->fi<<' '<<it1->se<<'\n';
					cursum+=it1->se;
					ans[-it1->fi*2]=max(ans[-it1->fi*2],cursum);
					it1++;
				}
				else
				{
					//cerr<<"ADD: "<<it2->fi<<' '<<it2->se<<' '<<cursum<<'\n';
					cursum+=it2->se;
					ans[-it2->fi*2]=max(ans[-it2->fi*2],cursum);
					it2++;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		vi vec;
		if(i!=0) vec.pb(upecc[i]);
		for(int v:adj[i])
		{
			if(v==par[i]) continue;
			vec.pb(downecc[v]);
		}
		sort(vec.rbegin(),vec.rend());
		/*
		cerr<<"ADJ "<<i<<'\n';
		for(int x:vec)
		{
			cerr<<x<<' ';
		}
		cerr<<'\n';
		*/
		for(int i=1;i<vec.size();i++)
		{
			int best = 2*vec[i];
			ans[best]=max(ans[best],i+1);
			//if(vec
			best = 2*min(vec[i-1]-1,vec[i])+1;
			ans[best]=max(ans[best],i+1);
		}
	}
	
	int maxdeg=0;
	for(int i=0;i<n;i++)
	{
		maxdeg=max(maxdeg,int(adj[i].size()));
	}
	ans[1]=max(ans[1],maxdeg+1);
	for(int i=n;i>=1;i--)
	{
		ans[i]=max(ans[i],ans[i+2]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}