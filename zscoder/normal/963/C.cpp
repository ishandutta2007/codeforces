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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
map<ii,ll> ma;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	map<ll,vector<ll> > L;
	ll G = 0;
	for(int i=0;i<n;i++)
	{
		ll x,y,c; cin>>x>>y>>c;
		if(G==0) G=c;
		else G=__gcd(c,G);
		ma[mp(x,y)]=c;
		L[x].pb(y);
	}	
	for(auto it = L.begin(); it != L.end(); it++)
	{
		sort(it->se.begin(),it->se.end());
	}
	vi tt = (*L.begin()).se;
	for(auto it = L.begin(); it != L.end(); it++)
	{
		if(it->se!=tt){cout<<0<<'\n'; return 0;}
	}
	vi xl,xr;
	for(auto it = L.begin(); it != L.end(); it++) xl.pb(it->fi);
	xr = tt;
	ll tmp = ma[mp(xl[0],xr[0])];
	const ld eps = 8e-13;
	vector<ld> vec;
	for(ll r:xr)
	{
		vec.pb(ma[mp(xl[0],r)]/ld(ma[mp(xl[0],xr[0])]));
	}
	for(ll l:xl)
	{
		ll ori = ma[mp(l, xr[0])];
		int ptr=0;
		for(ll r:xr)
		{
			ld res = ma[mp(l,r)]/ld(ori);
			if(res!=vec[ptr++])
			{
				cout<<0<<'\n'; return 0;
			}
		}
	}
	/*
	vector<ll> row;
	if(xl.size()<xr.size())
	{
		for(int i=0;i<xl.size();i++)
		{
			row.pb(ma[mp(xl[i],xr[0])]);
		}
	}
	else
	{
		for(int i=0;i<xr.size();i++)
		{
			row.pb(ma[mp(xl[0],xr[i])]);
			cerr<<row[i]<<' ';
		}
		cerr<<'\n';
	}
	*/
	int ans = 0;
	for(ll d=1;d*d<=G;d++)
	{
		if(G%d==0)
		{
			/*
			bool pos=1;
			for(int i=0;i<row.size();i++)
			{
				ll num = row[i]; ll denom = row[0];
				ll g = __gcd(num,denom);
				num/=g; denom/=g;
				ll g2 = __gcd(d,denom);
				denom/=g2;
				if(denom!=1) pos=0;
			}
			if(pos) 
			{
				cerr<<d<<'\n';
				ans++;
			}
			if(d*d!=tmp)
			{
				bool pos=1;
				for(int i=0;i<row.size();i++)
				{
					ll num = row[i]; ll denom = row[0];
					ll g = __gcd(num,denom);
					num/=g; denom/=g;
					ll g2 = __gcd(tmp/d,denom);
					denom/=g2;
					if(denom!=1) pos=0;
				}				
				if(pos) 
				{
					cerr<<tmp/d<<'\n'; ans++;
				}
			}
			*/
			ans++;
			if(d*d!=G) 
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}