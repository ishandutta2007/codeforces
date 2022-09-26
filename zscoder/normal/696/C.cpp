#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*
map<pair<ll, ll>, ll> ma;

ll lca(ll a, ll b)
{
	vi x, y;
	ll c, d;
	c = a; d = b;
	if(c == 0) x.pb(0);
	while(c)
	{
		x.pb(c%2); c>>=1;
	}
	reverse(x.begin(), x.end());
	if(d == 0) y.pb(0);
	while(d)
	{
		y.pb(d%2); d>>=1;
	}
	reverse(y.begin(), y.end());
	vi dig;
	int z = min(int(x.size()), int(y.size()));
	for(int i = 0; i < z; i++)
	{
		if(x[i] == y[i]) 
		{
			dig.pb(x[i]);
		}
		else break;
	}
	ll ans = 0; ll cnt = 1;
	for(int i = int(dig.size()) - 1; i >= 0; i--)
	{
		ans += (cnt*dig[i]);
		cnt <<= 1;
	}
	return ans;
}

ll parent(ll a)
{
	return (a>>1);
}

void add(ll a, ll b, ll v)
{
	ll lc = lca(a, b);
	//cout << a << ' ' << b << ' ' << lc << '\n';
	while(a > lc)
	{
		ma[mp(parent(a), a)] += v;
		a = parent(a);
	}
	while(b > lc)
	{
		ma[mp(parent(b), b)] += v;
		b = parent(b);
	}
}

ll calc(ll a, ll b)
{
	ll ans = 0;
	ll lc = lca(a, b);
	//cout << a << ' ' << b << ' ' << lc << '\n';
	while(a > lc)
	{
		//cout << parent(a) << ' ' << a << ' ' << ma[mp(parent(a), a)] << '\n';
		ans += ma[mp(parent(a), a)];
		a = parent(a);
	}
	while(b > lc)
	{
		//cout << parent(b) << ' ' << b << ' ' << ma[mp(parent(b), b)] << '\n';
		ans += ma[mp(parent(b), b)] ;
		b = parent(b);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	while(q--)
	{
		ll a, b, c, d;
		cin>>a>>b>>c;
		if(a == 1) cin >> d;
		if(a == 1) add(b, c, d);
		else cout << calc(b, c) << '\n';
	}
	return 0;	
}
*/

/*
typedef long double ld;

int par[100001];
vi adj[100001];

ld dp[100001];
int sub[100001];

int dfs(int u)
{
	sub[u] = 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		sub[u] += dfs(adj[u][i]);
	}
	return sub[u];
}

void bfs(int u)
{
	if(u == 0) dp[u] = 1;
	ll sum = 0;
	for(int i = 0; i < adj[u].size(); i++)
	{
		sum += sub[adj[u][i]];
	}
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		dp[v] = (ld(sum - ld(sub[v]))/ld(2)) + ld(dp[u] + ld(1)); 
	}
	for(int i = 0; i < adj[u].size(); i++)
	{
		bfs(adj[u][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> par[i + 1]; par[i + 1]--;
		//0-indexed
		adj[par[i + 1]].pb(i + 1);
	}
	dfs(0);
	bfs(0);
	for(int i = 0; i < n; i++)
	{
		cout << fixed << setprecision(15) << dp[i] << ' ';
	}
	return 0;	
}
*/

ll a[100001];
const ll MOD = 1e9 + 7;

ll modpow(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b&1) r = (r*a)%MOD;
		a = (a*a)%MOD;
		b>>=1;
	}
	return r;
}

ll inv(ll a)
{
	return modpow(a, MOD - 2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bool odd = true;
	for(int i = 0; i < n; i++)
	{
		//cout << i << endl;
		if(a[i]%2 == 0)
		{
			odd = false;
			break;
		}
	}
	//cout << "ok " << endl;
	ll denom = 1;
	ll power = 1;
	for(int i = 0; i < n; i++)
	{
		ll tmp = a[i]%(MOD - 1);
		power = (power * tmp);
		power %= (MOD - 1);
	}
	ll N = power;
	power--;
	if(power < 0) power += (MOD - 1);
	denom = modpow(2, power);
	
	denom %= MOD;
	if(denom < 0) denom += MOD;
	ll num = 0;
	ll inv3 = inv(3);
	
	if(odd)
	{
		ll val = N - 1;
		val /= 2;
		//cout << "OK" << endl;
		num = modpow(4, val) - 1;
	//	cout << "OK" << endl;
		num %= MOD;
		if(num < 0) num += MOD;
		num = (num * inv3)%MOD;
	}
	else
	{
		ll val = N/2;
		num = modpow(4, val + MOD - 2) - 1;
		num %= MOD;
		if(num < 0) num += MOD;
		num = (num*2)%MOD;
		num = (num*inv3)%MOD;
		num++;
		num %= MOD;
		if(num < 0) num += MOD;
	}
	cout << num << "/" << denom << '\n';
	return 0;	
}


/*
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	return 0;	
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	return 0;	
}
*/

/*
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	return 0;	
}
*/