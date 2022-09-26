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
typedef unsigned long long ull;
typedef double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<int,set<pair<ii,int> > > ma;
map<ii,set<ii> > ma2;

void add(int x, int y, int z, int p)
{
	ma[x].insert({{y,z},p});
	ma2[{x,y}].insert({z,p});
}

void rem(int x, int y, int z, int p)
{
	ma[x].erase({{y,z},p});
	if(ma[x].empty()) ma.erase(x);
	ma2[{x,y}].erase({z,p});
	if(ma2[{x,y}].empty()) ma2.erase({x,y});
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y,z; cin>>x>>y>>z;
		add(x,y,z,i+1);
	}
	for(int i=0;i<n/2;i++)
	{
		int x = (*ma.begin()).fi;
		auto BIG = *(((*ma.begin()).se).begin());
		int y = BIG.fi.fi; int z = BIG.fi.se; int lab=BIG.se;
		rem(x,y,z,lab);
		auto it = ma.lower_bound(x);
		if(it==ma.end())
		{
			it--;
		}
		int x2 = it->fi;
		auto it2 = ma[x2].lower_bound({{y,-int(1e9)},-int(1e9)});
		if(it2==ma[x2].end())
		{
			it2--;
		}
		int y2 = it2->fi.fi;
		auto it3 = ma2[{x2,y2}].lower_bound({z,-int(1e9)});
		if(it3==ma2[{x2,y2}].end())
		{
			it3--;
		}
		int z2 = it3->fi; int lab2 = it3->se;
		rem(x2,y2,z2,lab2);
		cout<<lab<<' '<<lab2<<'\n';
	}
}