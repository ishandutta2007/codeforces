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

vector<pair<int,ii> > vec;
int dp[300001];
vector<ii> tmp;

void process()
{
	map<int,int> ma;
	for(int i = 0; i < tmp.size(); i++)
	{
		int u = tmp[i].fi; int v = tmp[i].se;
		if(dp[v] < dp[u] + 1)
		{
			ma[v] = max(ma[v], dp[u] + 1);
		}
	}
	for(mit it = ma.begin(); it != ma.end(); it++)
	{
		dp[(*it).fi] = (*it).se;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vec.pb(mp(w, mp(u, v)));
	}
	sort(vec.begin(), vec.end());
	int curval = -1;
	for(int i = 0; i < m; i++)
	{
		int w = vec[i].fi; int u = vec[i].se.fi; int v = vec[i].se.se;
		if(w > curval)
		{
			process();
			tmp.clear();
		}
		curval = w;
		tmp.pb(mp(u, v));
	}
	process();
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = max(dp[i], ans);
	}
	cout << ans;
}