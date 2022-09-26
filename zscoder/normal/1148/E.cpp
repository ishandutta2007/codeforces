#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii a[333333];
ll b[333333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin>>n; ll sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].fi; a[i].se=i+1; sum+=a[i].fi;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i]; sum-=b[i];
	}
	if(sum!=0){cout<<"NO\n"; return 0;}
	sort(a,a+n); sort(b,b+n);
	int ptr=0;
	vector<pair<ii,ll> > moves;
	for(int i=0;i<n;i++)
	{
		if(a[i].fi==b[i]) continue;
		if(a[i].fi>b[i])
		{
			while(ptr<i&&a[i].fi>b[i])
			{
				if(a[ptr].fi<b[ptr])
				{
					ll dist = b[ptr]-a[ptr].fi;
					if(dist<=a[i].fi-b[i])
					{
						a[ptr].fi+=dist;
						a[i].fi-=dist;
						moves.pb({{a[ptr].se,a[i].se},dist});
					}
					else
					{
						dist=a[i].fi-b[i];
						a[ptr].fi+=dist;
						a[i].fi-=dist;
						moves.pb({{a[ptr].se,a[i].se},dist});
						break;
					}
				}
				ptr++;
				continue;
			}
			if(a[i].fi>b[i])
			{
				cout<<"NO\n"; return 0;
			}
		}
		else
		{
			continue;
		}
	}
	for(int i=0;i<n;i++)
	{
		assert(a[i].fi==b[i]);
	}
	cout<<"YES\n";
	cout<<moves.size()<<'\n';
	for(int i=0;i<moves.size();i++)
	{
		cout<<moves[i].fi.fi<<' '<<moves[i].fi.se<<' '<<moves[i].se<<'\n';
	}
}