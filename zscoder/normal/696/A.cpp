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