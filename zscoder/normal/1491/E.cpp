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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef bitset<200001> b100;

int fib[41];
vi adj[202222];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r)
{
	return uniform_int_distribution<int>(l,r)(rng);
}

int sub[202222];
bool ok[202222];
int par[222222];

void prep(int u, int p=-1)
{
	sub[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(!ok[v]) continue;
		par[v]=u;
		prep(v,u);
		sub[u]+=sub[v];
	}
}

int centroid(int u, int p, int r)
{
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(!ok[v]) continue;
		if(sub[v]*2>sub[r])
		{
			return centroid(v,u,r);
		}
	}
	return u;
}

bool color[202222];

void paint(int u, int p)
{
	color[u]=1;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(!ok[v]) continue;
		paint(v,u);
	}
}

unordered_map<ll,bool> tried;

const int MOD[2] = {int(1e9)+7,int(1e9)+9};
const int C[2] = {333333,419017};

ll hsh(vi &v)
{
	int cur[2] = {0,0};
	int coeff[2] = {1,1};
	for(int x:v)
	{
		for(int j=0;j<2;j++)
		{
			cur[j]+=(coeff[j]*1LL*(x+1))%MOD[j];
			while(cur[j]>=MOD[j]) cur[j]-=MOD[j];
			coeff[j]=(coeff[j]*1LL*C[j])%MOD[j];
		}
	}
	return cur[0]*1LL*(MOD[1]+20)+cur[1];
}

bool solve(vi &v, int tt)
{
	if(v.size()<=3) return true;
	assert(int(v.size())==fib[tt]);
	ll H = hsh(v);
	if(tried.find(H)!=tried.end()) return tried[H];
	for(int &x:v) ok[x]=1;
	int u = v[0];
	prep(u);
	int cent = centroid(u,-1,u);
	u = cent;
	//new root
	prep(u);
	vi subs;
	for(int x:v)
	{
		if(x!=u) assert(sub[x]*2<=sub[u]);
		if(sub[x]==fib[tt-2])
		{
			subs.pb(x);
		}
	}
	if(subs.size()>=2)
	{
		if(rnd(0,99)<=49) swap(subs[0],subs[1]);
	}
	if(subs.empty()) return (tried[H]=false);
	assert(subs.size()<=2);
	vi l[2];
	vi r[2];
	for(int i=0;i<subs.size();i++)
	{
		int x=subs[i];
		for(int &y:v) color[y]=0;
		paint(x,par[x]);
		for(int &y:v)
		{
			if(color[y]) l[i].pb(y);
			else r[i].pb(y);
		}
		//l is smaller
		assert(l[i].size()<=r[i].size());
	}
	for(int &x:v) ok[x]=0;
	for(int i=0;i<subs.size();i++)
	{
		bool pos=1;
		int rr = rnd(0,99);
		auto tmp = hsh(l[i]);
		auto tmp2 = hsh(r[i]);
		if(tried.find(tmp)!=tried.end())
		{
			rr=0;
		}
		if(tried.find(tmp2)!=tried.end())
		{
			rr=90;
		}
		if(rr<=49)
		{
			if(!solve(l[i],tt-2))
			{
				pos=0;
			}
			else if(!solve(r[i],tt-1))
			{
				pos=0;
			}
		}
		else
		{
			if(!solve(r[i],tt-1))
			{
				pos=0;
			}
			else if(!solve(l[i],tt-2))
			{
				pos=0;
			}
		}
		if(pos) return (tried[H]=true);
	}	
	return (tried[H]=false);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fib[0]=fib[1]=1;
	for(int i=2;i<=40;i++) fib[i]=fib[i-1]+fib[i-2];
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	if(n<=3)
	{
		cout<<"YES\n"; return 0;
	}
	int tt=-1;
	for(int i=0;i<=40;i++)
	{
		if(n==fib[i])
		{
			tt=i; break;
		}
	}
	if(tt==-1)
	{
		cout<<"NO\n"; return 0;
	}
	vi vec;
	for(int i=0;i<n;i++) vec.pb(i);
	if(solve(vec,tt))
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}