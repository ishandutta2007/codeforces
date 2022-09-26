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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi pos[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; pos[x].pb(i);
	}
	vector<ii> vec;
	for(int i=0;i<=101111;i++)
	{
		if(pos[i].empty()) continue;
		if(pos[i].size()==1) vec.pb({i,0});
		else
		{
			int mind=int(1e9); int maxd=0;
			for(int j=1;j<pos[i].size();j++)
			{
				maxd=max(maxd,pos[i][j]-pos[i][j-1]);
				mind=min(mind,pos[i][j]-pos[i][j-1]);
			}
			if(maxd==mind) vec.pb({i,mind});
		}
	}
	cout<<vec.size()<<'\n';
	for(ii x:vec)
	{
		cout<<x.fi<<' '<<x.se<<'\n';
	}
}