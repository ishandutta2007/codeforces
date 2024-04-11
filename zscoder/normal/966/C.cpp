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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int LG = 60;

int highestbit(ll x)
{
	for(int i=LG;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ll> vec[66]; 
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		vec[highestbit(x)].pb(x);
	}
	vector<ll> ans;
	for(int i=LG;i>=0;i--)
	{
		if(vec[i].empty()) continue;
		vector<ll> nw;
		int cur = 0;
		for(int j=0;j<vec[i].size();j++)
		{
			if(j>0)
			{
				bool pos=0;
				while(cur<ans.size())
				{
					nw.pb(ans[cur]);
					cur++;
					if(ans[cur-1]&(1LL<<i))
					{
						pos=1;
						break;
					}
				}
				if(!pos)
				{
					cout<<"No\n"; return 0;
				}
			}
			nw.pb(vec[i][j]);
		}
		
		while(cur<ans.size())
		{
			nw.pb(ans[cur]);
			cur++;
		}
		ans = nw;
	}
	assert(int(ans.size())==n);
	ll pref=0;
	for(int i=0;i<n;i++)
	{
		assert((pref^ans[i])>pref);
		pref^=ans[i];
	}
	cout<<"Yes\n";
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}