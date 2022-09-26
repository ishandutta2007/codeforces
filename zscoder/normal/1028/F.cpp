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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll dist(ii a)
{
	return (a.fi*1LL*a.fi+a.se*1LL*a.se);
}

ii reduce(ii x)
{
	int g=__gcd(x.fi,x.se);
	x.fi/=g; x.se/=g;
	return x;
}
set<ii> a[222222];
map<ii,int> ma;
vector<ll> coord;
map<ii,int> tot;
void ins(int x, int y)
{
	int lb=lower_bound(coord.begin(),coord.end(),dist(mp(x,y)))-coord.begin();
	tot[reduce(mp(x,y))]++;
	for(ii pt:a[lb])
	{
		ma[reduce(mp(x+pt.fi,y+pt.se))]++;
	}
	a[lb].insert(mp(x,y));
}

void del(int x, int y)
{
	int lb=lower_bound(coord.begin(),coord.end(),dist(mp(x,y)))-coord.begin();
	tot[reduce(mp(x,y))]--;
	a[lb].erase(mp(x,y));
	for(ii pt:a[lb])
	{
		ma[reduce(mp(x+pt.fi,y+pt.se))]--;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	vector<pair<int,ii> > queries; 
	for(int z=0;z<q;z++)
	{
		int t; cin>>t; ll x,y; cin>>x>>y; queries.pb(mp(t,mp(x,y))); coord.pb(dist(mp(x,y)));
	}
	sort(coord.begin(),coord.end()); coord.erase(unique(coord.begin(),coord.end()),coord.end());
	int pointcnt=0;
	for(int z=0;z<q;z++)
	{
		int t=queries[z].fi; int x=queries[z].se.fi; int y=queries[z].se.se;
		if(t==1)
		{
			pointcnt++;
			ins(x,y);
		}
		else if(t==2)
		{
			pointcnt--;
			del(x,y);
		}
		else
		{
			ii cur = reduce(mp(x,y));
			int ans = pointcnt;
			//i dont think need to care on the line as pair
			ans -= tot[cur];
			ans -= 2*ma[cur];
			cout<<ans<<'\n';
		}
	}
	
}