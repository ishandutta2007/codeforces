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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll c[300011];
ll t[300011];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll k; cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	priority_queue<ii> pq;
	for(int i=0;i<=min(n-1,int(k));i++) pq.push(mp(c[i],i));
	for(int i=0;i<n;i++)
	{
		t[pq.top().se] = k + i + 1;
		pq.pop();
		if(i+k+1<n)
		{
			pq.push(mp(c[i+k+1],i+k+1));
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=c[i]*ll(t[i]-(i+1));
	}
	cout<<ans<<'\n';
	for(int i=0;i<n;i++)
	{
		cout<<t[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}