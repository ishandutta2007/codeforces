#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll dist(ll a, ll b, ll m)
{
	if(a>b) swap(a,b);
	return min(b-a,m-(b-a));
}

ll mod(ll a, ll m)
{
	a%=m;
	if(a<0) a+=m;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll m,n; cin>>m>>n;
	vector<ii> coord;
	m*=2;
	vector<ii> a(n);
	vector<ii> b(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].fi; a[i].fi*=2; a[i].se=i; 
	}
	ll ss=a[0].fi;
	for(int i=0;i<n;i++)
	{
		cin>>b[i].fi; b[i].fi*=2; b[i].se=i; 
		a[i].fi=mod(a[i].fi-ss,m);
		b[i].fi=mod(b[i].fi-ss,m);
	}
	for(int i=0;i<n;i++)
	{
		coord.pb({a[i].fi,i}); 
		coord.pb({b[i].fi,i+n});
	}
	coord.pb({m,2*n});
	sort(coord.begin(),coord.end());
	int cnt=0; int las=0;
	vector<pair<ll,ii> > F;
	for(int i=0;i<2*n;i++)
	{
		while(coord[las].fi<=coord[i].fi)
		{
			if(coord[las].se<n) cnt++;
			else cnt--;
			las++;
		}
		if(coord[i].fi!=coord[i+1].fi)
		{
			F.pb({cnt,{coord[i].fi,coord[i+1].fi}});
		}
	}
	sort(F.rbegin(),F.rend());
	ll sumlen = 0;  int startpos=-1;
	for(int i=0;i<F.size();i++)
	{
		ll l = F[i].se.fi; ll r = F[i].se.se;
		sumlen+=r-l;
		//cerr<<l<<' '<<r<<' '<<sumlen<<' '<<F[i].fi<<'\n';
		if(sumlen>=m/2)
		{
			startpos = l; break;
		}
	}
	//cerr<<startpos<<'\n';
	vector<int> fin[2];
	vi perm(n);
	ll ans = 0;
	for(int i=0;i<2*n;i++)
	{
		ll pos = coord[i].fi; int id = coord[i].se;
		if(pos>startpos)
		{
			fin[id/n].pb(id%n);
		}
	}
	for(int i=0;i<2*n;i++)
	{
		ll pos = coord[i].fi; int id = coord[i].se;
		if(pos<=startpos)
		{
			fin[id/n].pb(id%n);
		}
	}
	for(int i=0;i<n;i++)
	{
		//cerr<<a[fin[0][i]].fi<<' '<<b[fin[1][i]].fi<<'\n';
		ans+=dist(a[fin[0][i]].fi,b[fin[1][i]].fi,m);
		perm[fin[0][i]]=fin[1][i];
	}
	cout<<ans/2<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<perm[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}