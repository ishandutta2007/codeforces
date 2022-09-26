#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const ll MOD = 1e9 + 7;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[1001][1001];
vector<pair<ll, ii> > vec;
ll n, m; 

bool in(ii pt)
{
	if(pt.fi >= 0 && pt.fi < n && pt.se >= 0 && pt.se < m) return true;
	return false;
}

ii l(ii pt)
{
	return ii(pt.fi, pt.se - 1);
}

ii r(ii pt)
{
	return ii(pt.fi, pt.se + 1);
}

ii d(ii pt)
{
	return ii(pt.fi + 1, pt.se);
}

ii u(ii pt)
{
	return ii(pt.fi - 1, pt.se);
}

ll cv(ii pt)
{
	return (pt.fi*m + pt.se);
}

vii adj[1001][1001];
ll par[1000001];

ll root(ll u)
{
	if(par[u] < 0) return u;
	else return (par[u] = root(par[u]));
}

void merge(ll u, ll v)
{
	if((u = root(u)) == (v = root(v))) return ;
	if(par[v] < par[u]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
}

bool sameset(ll u, ll v)
{
	if(root(u) == root(v)) return true;
	return false;
}

bool visited[1001][1001];
bool dfsed[1001][1001];
ll ans[1001][1001];
ll cnt;
void dfs(ii u, ll val, ll quota)
{
	ii v;
	cnt++;
	if(cnt > quota) return ;
	ans[u.fi][u.se] = val;
	dfsed[u.fi][u.se] = true;
	for(ll i = 0; i < adj[u.fi][u.se].size(); i++)
	{
		v = adj[u.fi][u.se][i];
		if(visited[v.fi][v.se] && !dfsed[v.fi][v.se])
		{
			dfs(v, val, quota);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("Polycarp and Hay.in", "r", stdin);
	ll k;
	cin >> n >> m >> k;
	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < m; j++)
		{
			cin >> a[i][j];
			vec.pb(mp(a[i][j], ii(i, j)));
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	ii pt;
	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < m; j++)
		{
			pt = ii(i, j);
			if(in(l(pt))) adj[i][j].pb(l(pt));
			if(in(r(pt))) adj[i][j].pb(r(pt));
			if(in(u(pt))) adj[i][j].pb(u(pt));
			if(in(d(pt))) adj[i][j].pb(d(pt));
		}
	}
	memset(par, -1, sizeof(par));
	for(ll i = 0; i < vec.size(); i++)
	{
		//cout << vec[i].fi << endl;
		//cout << k/vec[i].fi << endl;
		pt = vec[i].se;
		visited[pt.fi][pt.se] = true;
		//cout << pt.fi << " " << pt.se << endl;
		for(ll j = 0; j < adj[pt.fi][pt.se].size(); j++)
		{
			ii pt2 = adj[pt.fi][pt.se][j];
			//cout << pt2.fi << " " << pt2.se << endl;
			if(visited[pt2.fi][pt2.se])
			{
				merge(cv(pt), cv(pt2));
				if(k % vec[i].fi == 0)
				{
					ll siz = k/vec[i].fi;
					//cout << siz << " " << -par[root(cv(pt))] << endl;
					if(siz <= -par[root(cv(pt))])
					{
						dfs(pt, vec[i].fi, siz);
						cout << "YES" << "\n";
						for(ll x = 0; x < n; x++)
						{
							for(ll y = 0; y < m; y++)
							{
								cout << ans[x][y] << ' ';
							}
							cout << "\n";
						}
						return 0;
					}
				}
			}
		}
		if(k % vec[i].fi == 0)
		{
			ll siz = k/vec[i].fi;
			//cout << siz << " " << -par[root(cv(pt))] << endl;
			if(siz <= -par[root(cv(pt))])
			{
				dfs(pt, vec[i].fi, siz);
				cout << "YES" << "\n";
				for(ll x = 0; x < n; x++)
				{
					for(ll y = 0; y < m; y++)
					{
						cout << ans[x][y] << ' ';
					}
					cout << "\n";
				}
				return 0;
			}
		}
	}	
	cout << "NO" << '\n';
	return 0;
}