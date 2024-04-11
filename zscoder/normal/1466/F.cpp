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
vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}

int loop[501111];
vector<ii> adj[501111];
bool vis[501111];
vi C;
vi E;

void dfs(int u)
{
	vis[u]=1; C.pb(u);
	for(auto e:adj[u])
	{
		int v=e.fi; int id=e.se;
		if(vis[v])
		{
			
		}
		else
		{
			dfs(v);
		}
	}
}

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
	
	void inc(int u)
	{
		u=rt(u);
		dsu[u].sum++;
	}
};

void solve()
{
	int m,n; cin>>m>>n;
	DSU dsu(n);
	vi ans;
	for(int i=0;i<m;i++)
	{
		int k; cin>>k;
		if(k==1)
		{
			int x; cin>>x; x--; loop[x]=i;
			if(dsu.getstat(x)>0) continue;
			dsu.inc(x); ans.pb(i);
		}
		else
		{
			int u,v; cin>>u>>v; u--; v--;
			if(dsu.sameset(u,v)) continue;
			if(dsu.getstat(u)>0&&dsu.getstat(v)>0) continue;
			dsu.merge(u,v); ans.pb(i);
			//adj[u].pb({v,i}); adj[v].pb({u,i});
		}
	}
	/*
	int rk = 0;
	
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			C.clear(); E.clear();
			dfs(i);
			rk+=int(C.size())-1;
			sort(C.begin(),C.end());
			for(int x:C)
			{
				if(loop[x])
				{
					ans.pb(x); rk++; break;
				}
			}
		}
	}
	*/
	int rk=ans.size();
	cout<<pow2[rk]<<' '<<rk<<'\n';
	sort(ans.begin(),ans.end());
	for(int x:ans)
	{
		cout<<x+1<<' ';
	}
	cout<<'\n';
	for(int i=0;i<n;i++)
	{
		adj[i].clear(); loop[i]=-1; vis[i]=0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(511111);
	int t=1; while(t--) solve();
}