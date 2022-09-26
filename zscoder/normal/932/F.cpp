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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;


const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return 1.0L * b - s->b < 1.0L *(s->m - m) * x;
    }
};
struct ConvexHullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b)*1.0L*(z->m - y->m) >= (y->b - z->b)*1.0L*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

ConvexHullDynamic buffer[200011];
ConvexHullDynamic *dp[100011];
ll a[111111];
ll b[111111];
vi adj[111111];
int sub[111111];
ll ans[111111];

void prep(int u, int p)
{
	sub[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		prep(v,u); sub[u]+=sub[v];
	}
}

int cnt=0;

void dfs(int u, int p)
{
	int mc=-1; int mx=0;
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		if(sub[v]>mx)
		{
			mx=sub[v]; mc=v;
		}
	}
	if(mc==-1)
	{
		ans[u]=0;
		dp[u] = &(buffer[cnt++]);
		dp[u]->insert_line(-b[u], 0);
		return ;
	}
	dp[u] = dp[mc];
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(v!=mc)
		{
			for(auto it=dp[v]->begin();it!=dp[v]->end();it++)
			{
				dp[u]->insert_line(it->m, it->b);
			}
		}
	}
	ans[u] = -dp[u]->eval(a[u]);
	dp[u]->insert_line(-b[u], -ans[u]);
	//add here
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	prep(0,-1);
	dfs(0,-1);
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}