#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

ll a[200001];
ll dp[200001];

struct line
{
	ll m, c;
	ll val(ll x)
	{
		return (m*x + c);
	}
};

vector<line> hull;

bool bad(ll a, ll b, ll c)
{
	line x, y, z;
	x = hull[a];
	y = hull[b];
	z = hull[c];
	return (x.c - z.c)*(x.m - y.m) <= (y.c - x.c)*(z.m - x.m);
}

void add(ll a, ll b)
{
	line n;
	n.m = a; n.c = b;
	hull.pb(n);
	while(hull.size() >= 3 && bad(hull.size() - 2, hull.size() - 3, hull.size() - 1))
	{
		hull[hull.size() - 2] = hull[hull.size() - 1];
		hull.pop_back();
	}
}

ll query(ll x)
{
	ll l = 0; ll r = hull.size() - 1;
	ll ans;
	while(l <= r)
	{
		ll mid = (l+r)>>1;
		if(mid == hull.size() - 1) {ans = mid; break;}
		if(hull[mid].val(x) <= hull[mid+1].val(x))
		{
			l = mid + 1;
		}
		else
		{
			ans = mid;
			r = mid - 1;
		}
	}
	return hull[ans].val(x);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for(ll i = 1; i <= n; i++) cin>>a[i];
	ll ans = 0;
	ll dans = 0;
	for(ll i = 1; i <= n; i++)
	{
		dp[i] = dp[i-1] + a[i];
		ans += ll(i)*a[i];
	}
	
	for(ll l = n - 1; l >= 1; l--)
	{
		ll tmp = dp[l] - a[l]*l;
		add(-(l+1), -dp[l+1]);
		tmp += query(-a[l]);
		dans = max(dans, tmp);
	}
	
	hull.clear();
	
	for(ll r = 2; r <= n; r++)
	{
		ll tmp = dp[r - 1] - a[r]*r;
		add(r - 1, -dp[r - 2]);
		tmp += query(a[r]);
		dans = max(dans, tmp);
	}
	
	cout << ans + dans;
	return 0;
}