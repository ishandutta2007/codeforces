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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll a[222222];
string s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<pair<ll,char> > vec;
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>s;
	ll len=0;
	for(int i=0;i<n;i++)
	{
		if(i>0&&s[i]!=s[i-1])
		{
			vec.pb(mp(len,s[i-1])); len=0;
		}
		len+=a[i];
	}
	vec.pb(mp(len,s[n-1]));
	ll ans = 0;
	priority_queue<pair<ll,ll> > stamina;
	for(int i=0;i<vec.size();i++)
	{
		ll L = vec[i].fi; char c = vec[i].se;
		if(c=='L')
		{
			ll expend = L;
			while(expend>0)
			{
				ll cost = -stamina.top().fi; ll avi = stamina.top().se; 
				stamina.pop();
				if(avi>expend)
				{
					ans+=cost*expend;
					stamina.push(mp(-cost,avi-expend));
					expend=0;
				}
				else
				{
					ans+=cost*avi;
					expend-=avi;
				}
			}
		}
		else if(c=='G')
		{
			ll expend=L;
			while(expend>0&&!stamina.empty()&&stamina.top().fi>-3)
			{
				ll cost = -stamina.top().fi; ll avi = stamina.top().se; 
				stamina.pop();
				if(avi>expend)
				{
					ans+=cost*expend;
					stamina.push(mp(-cost,avi-expend));
					expend=0;
				}
				else
				{
					ans+=cost*avi;
					expend-=avi;
				}
			}
			ans+=3LL*expend;
			stamina.push(mp(-3,L));
			stamina.push(mp(-3,L-expend));
			stamina.push(mp(-6,ll(1e18)));
		}
		else
		{
			ans+=2LL*L;
			stamina.push(mp(-2,L));
			stamina.push(mp(-4,ll(1e18)));
		}
	}
	cout<<ans<<'\n';
}