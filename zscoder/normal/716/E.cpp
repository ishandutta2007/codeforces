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

const int N = 1e5 + 1;
const int MAX = 1e9;
int MOD, n;

bool isprime[100001];
vector<ll> primes;
vector<ii> adj[N];
int subsize[N];
bool visited[N];
int treesize;
vi clrlist;
ll up[N];
ll down[N];
int h[N];
int PHI;
int dppart[N];

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

ll add(ll a, ll b)
{
	return (a+b+MOD)%MOD;
}

ll modpow(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b&1) r=(r*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return r;
}

void Sieve(int n)
{
	memset(isprime, 1, sizeof(isprime));
	isprime[1] = false;
	for(int i = 2; i <= n; i++)
	{
		if(isprime[i])
		{
			primes.pb(i);
			for(int j = 2*i; j <= n; j += i)
			{
				isprime[j] = false;
			}
		}
	}
}

int phi(int n)
{
	ll num = 1; ll num2 = n;
	for(ll i = 0; primes[i]*primes[i] <= n; i++)
	{
		if(n%primes[i]==0)
		{
			num2/=primes[i];
			num*=(primes[i]-1);
		}
		while(n%primes[i]==0)
		{
			n/=primes[i];
		}
	}
	if(n>1)
	{
		num2/=n; num*=(n-1);
	}
	n = 1;
	num*=num2;
	return num;
}

ll inv(ll a)
{
	return modpow(a, PHI-1);
}

void dfs(int u, int par)
{
	if(par == -1) clrlist.clear();
	subsize[u] = 1; clrlist.pb(u);
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].fi;
		if(visited[v]) continue;
		if(v == par) continue;
		dfs(v, u);
		subsize[u] += subsize[v];
	}	
	if(par == -1) treesize = subsize[u];
}

int centroid(int u, int par)
{
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].fi;
		if(visited[v]) continue;
		if(v == par) continue;
		if(subsize[v]*2 > treesize) return centroid(v, u);
	}
	return u;
}

int parts = 0;
void fill(int u, int p, int cent)
{
	if(p == cent)
	{
		dppart[u] = parts;
		parts++;
	}
	else if(p != -1)
	{
		dppart[u] = dppart[p];
	}
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].fi; int w = adj[u][i].se;
		if(v == p || visited[v]) continue;
		down[v] = add(mult(down[u], 10), w);
		up[v] = add(up[u], mult(modpow(10, h[u]), w));
		h[v] = h[u] + 1;
		fill(v, u, cent);
		//cout << v << ' ' << u << ' ' << up[v] << ' ' << up[u] << '\n';
	}
}

ll solve(int cent)
{
	for(int i = 0; i < clrlist.size(); i++)
	{
		up[clrlist[i]] = 0; down[clrlist[i]] = 0; h[clrlist[i]] = 0;
	}
	parts = 0;
	fill(cent, -1, cent); parts--;
	dppart[cent] = -1; 
	map<ll,ll> tot; //only count up
	vector<map<ll,ll> > vec; //only count up, but in specific subtree
	vec.resize(parts+1);
	tot[0]++;
	for(int i = 0; i < clrlist.size(); i++)
	{
		int u = clrlist[i];
		//cout << u << ' ' << up[u] << ' ' << down[u] << '\n';
		if(u == cent) continue;
		tot[up[u]]++;
		vec[dppart[u]][up[u]]++;
	}
	ll ans = 0;
	for(int i = 0; i < clrlist.size(); i++)
	{
		int u = clrlist[i];
		int ht = h[u];
		int pt = dppart[u];
		if(u == cent)
		{
			ans += (tot[0] - 1); //exclude cent as the vertex
		}
		else
		{
			ll val = ((-down[u])%MOD+MOD)%MOD;
			val = mult(val, inv(modpow(10, ht)));
			ans += (tot[val] - vec[pt][val]);
		}
	}
	return ans;
}

ll compsolve(int u)
{
	dfs(u, -1);
	int cent = centroid(u, -1);
	ll ans = solve(cent);
	//cout << u << ' ' << cent << ' ' << ans << '\n';
	visited[cent] = true;
	for(int i = 0; i < adj[cent].size(); i++)
	{
		int v = adj[cent][i].fi;
		if(!visited[v]) ans += compsolve(v);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> MOD;
	if(MOD == 1)
	{
		cout << ll(n)*ll(n - 1);
		return 0;
	}
	Sieve(100000); PHI = phi(MOD);
	for(int i = 0; i < n - 1; i++) //tree is 0-indexed
	{
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb(ii(v, w)); adj[v].pb(ii(u, w));
	}
	cout << compsolve(0) << '\n';
	return 0;
}