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
typedef pair<int,int> ii2;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const ll C = 1000000001;
ll hsh(ll a, ll b)
{
	return a*C+b;
}

ii unhsh(ll x)
{
	return mp(x/C, x%C);
}

unordered_map<ll, pair<ii,ii2> > ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll bestans = 0; ii2 bestidx = ii(0,0);
	for(int i = 0; i < n; i++)
	{
		int a[3]; cin >> a[0]>>a[1]>>a[2];
		sort(a,a+3);
		ll tmp = hsh(a[1],a[2]);
		if(a[0]>=ma[tmp].fi.fi)
		{
			ma[tmp].fi.se=ma[tmp].fi.fi;
			ma[tmp].fi.fi=a[0];
			ma[tmp].se.se=ma[tmp].se.fi;
			ma[tmp].se.fi=i+1;
		}
		else if(a[0]>=ma[tmp].fi.se)
		{
			ma[tmp].fi.se=a[0];
			ma[tmp].se.se=i+1;
		}
	}
	for(unordered_map<ll,pair<ii,ii2> >::iterator it = ma.begin(); it != ma.end(); it++)
	{
		pair<ii,ii2> tmp = (*it).se;
		ii ori = unhsh((*it).fi);
		int mini = min(ori.fi,ori.se);
		mini = min(tmp.fi.fi+tmp.fi.se,ll(mini));
		if(mini>bestans)
		{
			bestans = mini;
			bestidx = tmp.se;
		}
	}	
	if(bestidx.se == 0)
	{
		cout << 1 << '\n' << bestidx.fi << '\n';
	}
	else
	{
		cout << 2 << '\n' << bestidx.fi << ' ' << bestidx.se << '\n';
	}
}