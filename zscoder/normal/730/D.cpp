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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll l[200001];
ll t[200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll r; cin>>n>>r;
	for(int i = 0; i < n; i++)
	{
		cin>>l[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin>>t[i];
		if(t[i]<l[i])
		{
			cout<<-1;
			return 0;
		}
	}
	ll rem = 0;
	ll tot = 0;
	ll k = 0;
	ll len = 0;
	ll tim = 0;
	vector<ll> ans;
	for(int i = 0; i < n; i++)
	{
		len = l[i]; tim = t[i];
		ll lef = min(rem, len);
		len-=lef;
		tim-=lef;
		rem-=lef;
		tot+=lef;
		if(len==0) continue;
		lef = min(len, tim-len);
		len-=lef;
		tim-=lef*2LL;
		tot+=lef*2LL;
		if(len==0) continue;
		ll nw = (len+r-1)/r;
		k+=nw;
		if(k<=100000)
		{
			for(int j = 0; j < nw; j++)
			{
				ans.pb(tot);
				if(j<nw-1) tot+=r;
			}
		}
		rem = nw*r-len;
		tot+=(r-rem);
	}
	cout<<k<<'\n';
	if(k <= 100000)
	{
		for(int i = 0; i < k; i++)
		{
			cout << ans[i] << ' ';
		}
	}
}