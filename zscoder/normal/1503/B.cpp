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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void pri(int b, int i, int j)
{
	cout<<b+1<<' '<<i+1<<' '<<j+1<<'\n';
	fflush(stdout);
}

int get()
{
	int x; cin>>x; x--; return x;
}

int main()
{
	int n; cin>>n;
	int ptr[2]={0,0};
	vector<ii> v[2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[(i+j)&1].pb({i,j});
		}
	}
	for(int i=0;i<n*n;i++)
	{
		int c = get();
		//use color c^1 this turn
		if(c==2)
		{
			if(ptr[0]<v[0].size())
			{
				pri(0,v[0][ptr[0]].fi,v[0][ptr[0]].se); 
				ptr[0]++;
			}
			else
			{
				pri(1,v[1][ptr[1]].fi,v[1][ptr[1]].se); 
				ptr[1]++;
			}
		}
		else
		{
			if(ptr[c^1]<v[c^1].size())
			{
				pri(c^1,v[c^1][ptr[c^1]].fi,v[c^1][ptr[c^1]].se);
				ptr[c^1]++;
			}
			else
			{
				//ptr[c^1] bao zha le
				//use color 2 to put in ptr[c] slot
				pri(2,v[c][ptr[c]].fi,v[c][ptr[c]].se);
				ptr[c]++;
			}
		}
	}
}