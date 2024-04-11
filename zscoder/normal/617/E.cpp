#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

ll a[100001];
vector<pair<ii, ll> > q;

const ll N = 100001;
const ll B = 315;
ll pref[100001];
ll cnt[1500001];
ll ans[100001];

bool comp(pair<ii, ll> x, pair<ii, ll> y)
{
	if(x.fi.fi/B != y.fi.fi/B) return x.fi.fi/B < y.fi.fi/B;
	if(x.fi.se != y.fi.se) return x.fi.se < y.fi.se;
	return x.fi.fi < y.fi.fi;
}

ll answer;
ll n, m, k;

void add(ll x)
{
	answer += cnt[x^k];
	cnt[x]++;
}

void subtract(ll x)
{
	cnt[x]--;
	answer -= cnt[x^k];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	
	for(ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i] = pref[i-1]^a[i];
	}
	
	for(ll i = 0; i < m; i++)
	{
		ll x, y; cin >> x >> y;
		q.pb(mp(ii(x, y), i));
	}
	
	sort(q.begin(), q.end(), comp);
	
	ll l = 0; ll r = 0;
	ll ql = 0; ll qr = 0;
	cnt[0] = 1; answer = 0;
	for(ll i = 0; i < m; i++)
	{
		ql = q[i].fi.fi-1; qr = q[i].fi.se;
		while(r < qr)
		{
			r++;
			add(pref[r]);
		}
		while(l < ql)
		{
			subtract(pref[l]);
			l++;
		}
		while(r > qr)
		{
			subtract(pref[r]);
			r--;
		}
		while(l > ql)
		{
			l--;
			add(pref[l]);
		}
		ans[q[i].se] = answer;
	}
	
	for(ll i = 0; i < m; i++) cout << ans[i] << "\n";
	return 0;
}