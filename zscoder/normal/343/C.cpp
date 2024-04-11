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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll h[100001];
ll p[100001];

int n, m; 

bool solve(ll v)
{
	int ptr = 0;
	for(int i = 0; i < n; i++)
	{
		//cerr << i << ' ' << ptr << '\n';
		if(ptr >= m) break;
		ll go = 0; ll gotmp = 0;
		if(p[ptr] < h[i])
		{
			go += h[i] - p[ptr];
			if(go > v) return false;
			gotmp = h[i] - p[ptr];
			//go += h[i] - p[ptr];
		}
		//ll cur = h[i];
		while(ptr < m && p[ptr] < h[i]) ptr++;
		if(go > v) continue;
		if(ptr >= m) break;
		//cerr << go << ' ' << p[ptr] << ' '<< cur << '\n';
		while(ptr < m && go + p[ptr] - h[i] + min(gotmp, p[ptr]-h[i]) <= v)
		{
			//go += p[ptr] - cur;
			ptr++;
		}
	}
	//cerr << ptr << '\n';
	if(ptr < m) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> p[i];
	}
	ll lo = 0; ll hi = ll(1e14);
	ll ans = 0;
	//cerr << solve(8) << '\n';
	
	while(lo <= hi)
	{
		ll mid = (lo+hi)>>1;
		if(solve(mid))
		{
			hi = mid - 1;
			ans = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	cout << ans;
	
}