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

vi pos[111111];

void solve()
{
	int n,x,y; cin>>n>>x>>y;
	vi a(n);
	vi cnt(n+2,0);
	for(int i=0;i<=n+1;i++) pos[i].clear();
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
		cnt[a[i]]++;
		pos[a[i]].pb(i);
	}
	int extracolor = 0;
	while(cnt[extracolor]>0) extracolor++;
	//extracolor is good le
	vi b(n,extracolor);
	//pick a derangement
	int dercount = n-x;
	//choose a subset of size dercount for derangement purposes
	vector<int> sortedlist;
	vector<ii> E;
	for(int i=0;i<=n;i++)
	{
		E.pb({cnt[i],i});
	}
	sort(E.rbegin(),E.rend());
	while(!E.empty()&&E.back().fi==0) E.pop_back();
	while(!E.empty())
	{
		for(ii &x:E)
		{
			assert(x.fi>0);
			x.fi--;
			sortedlist.pb(pos[x.se].back());
			pos[x.se].pop_back();
		}
		while(!E.empty()&&E.back().fi==0) E.pop_back();
	}
	set<int> S;
	for(int i=0;i<n;i++) S.insert(i);
	if(dercount>0)
	{
		vi derpos;
		for(int i=0;i<dercount;i++)
		{
			derpos.pb(sortedlist[i]);
			S.erase(sortedlist[i]);
		}
		//use this list to make a derangement (or at least try to)
		vector<pair<int,ii> > vec;
		map<int,int> ma;
		for(int x:derpos)
		{
			ma[a[x]]++;
		}
		for(int x:derpos)
		{
			vec.pb({ma[a[x]], {a[x], x}});
		}
		sort(vec.rbegin(),vec.rend());
		int maxcount = vec[0].fi;
		int yy = 0;
		int l = 0;
		for(int i=maxcount;i<maxcount+dercount;i++)
		{
			ii p1 = vec[i%int(vec.size())].se;
			ii p2 = vec[l].se;
			if(yy<y-x)
			{
				while(l<int(vec.size())&&p2.fi==p1.fi)
				{
					l++; 
					p2 = vec[l].se;
				}
				if(l>=int(vec.size()))
				{
					cout<<"NO\n"; return ;
				}
				b[p1.se] = p2.fi;
				if(p1.fi==p2.fi)
				{
					cout<<"NO\n"; return ;
				}
				l++;
				yy++;
			}
			else
			{
				b[p1.se] = extracolor;
			}
		}		
	}
	int ct=0;
	for(int y:S)
	{
		b[y]=a[y];
		ct++;
		if(ct>=x) break;
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}