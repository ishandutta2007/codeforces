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

void solve()
{
	int n; cin>>n;
	string a[3];
	cin>>a[0]>>a[1]>>a[2];
	vector<ii> vec;
	for(int i=0;i<3;i++)
	{
		int cnt=0;
		for(char c:a[i]) cnt+=(c=='1');
		vec.pb({cnt,i});
	}
	sort(vec.begin(),vec.end());
	string ans="";
	if(vec[1].fi>=n) //use 1s
	{
		int ptr[3] = {0,0,0};
		for(int i=0;i<n;i++)
		{
			for(int z=1;z<3;z++)
			{
				int j=vec[z].se;
				while(ptr[j]<2*n&&a[j][ptr[j]]!='1')
				{
					ans+=string(1,a[j][ptr[j]]);
					ptr[j]++;
				}
				ptr[j]++;
			}
			ans+="1";
		}
		for(int z=1;z<3;z++)
		{
			int j=vec[z].se;
			while(ptr[j]<2*n)
			{
				ans+=string(1,a[j][ptr[j]]);
				ptr[j]++;
			}
		}
	}
	else
	{
		int ptr[3] = {0,0,0};
		for(int i=0;i<n;i++)
		{
			for(int z=0;z<2;z++)
			{
				int j=vec[z].se;
				while(ptr[j]<2*n&&a[j][ptr[j]]!='0')
				{
					ans+=string(1,a[j][ptr[j]]);
					ptr[j]++;
				}
				ptr[j]++;
			}
			ans+="0";
		}
		for(int z=0;z<2;z++)
		{
			int j=vec[z].se;
			while(ptr[j]<2*n)
			{
				ans+=string(1,a[j][ptr[j]]);
				ptr[j]++;
			}
		}
	}
	assert(int(ans.length())<=3*n);
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		solve();
	}
}