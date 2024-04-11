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

ll a[222222];
ll b[222222];

bool cmp(ii a, ii b)
{
	if(a.fi!=b.fi) return a.fi<b.fi;
	return a.se>b.se;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<ii> vec;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		vec.pb({a[i],b[i]});
	}
	sort(vec.begin(),vec.end(),cmp);
	ll ans = 0;
	ll cur = -1;
	priority_queue<ii> pq;
	for(int i=0;i<n;i++)
	{
		bool pos=0;
		while(!pq.empty())
		{
			if(vec[i].fi<=cur+1)
			{
				pq.push({vec[i].se,vec[i].fi}); pos=1; 
				break;
			}
			ans+=(cur+1-pq.top().se)*1LL*pq.top().fi; pq.pop();
			cur++;
		}
		if(!pos)
		{
			if(vec[i].fi>=cur+1)
			{
				cur=vec[i].fi;
			}
			else
			{
				pq.push({vec[i].se,vec[i].fi});
			}
		}
	}
	while(!pq.empty())
	{
		ans+=(cur+1-pq.top().se)*1LL*pq.top().fi; pq.pop();
		cur++;
	}
	cout<<ans<<'\n';
}