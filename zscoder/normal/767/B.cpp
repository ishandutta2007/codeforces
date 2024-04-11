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

ll a[100001];
ll dp[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll s, e; ll t;
	cin>>s>>e>>t;
	e--;
	int n; cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	if(n==0)
	{
		cout<<s;
		return 0;
	}
	dp[0] = max(s, a[0]) + t;
	for(int i = 1; i < n; i++)
	{
		ll startime = max(a[i],dp[i-1]);
		dp[i] = startime+t;
		//cerr<<i<<' '<<dp[i]<<'\n';
	}
	ll bestans = 0;
	ll waittime = ll(3e18);
	bestans = min(e-t+1,a[0]-1);
	waittime = max(0LL,s - bestans);
	for(int i = 0; i < n; i++)
	{
		ll qtime = 0;
		if(i<n-1) 
		{
			qtime = a[i+1]-1;
			if(qtime>e-t) continue;
			if(qtime<a[i]) continue;
		}
		else
		{
			qtime = e-t+1;
			if(qtime<a[i]) continue;
		}
		//cerr<<i<<' '<<qtime<<'\n';
		ll star = max(dp[i],qtime);
		ll waittim = star - qtime;
		ll endtime = star+t-1;
		if(endtime<=e)
		{
			if(waittim<waittime)
			{
				waittime=waittim;
				bestans=qtime;
			}
		}
	}
	cout<<bestans;
}