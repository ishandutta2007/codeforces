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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[333333];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll a,b; cin>>n>>a>>b;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x; vec.pb(mp(x,i+1));
	}
	sort(vec.begin(),vec.end());
	//case 1 let a take vec[0]
	dp[n] = n;
	for(int i=n-1;i>=0;i--)
	{
		dp[i] = dp[i+1];
		if((n-i)*1LL*vec[i].fi>=b)
		{
			//cerr<<"VALID "<<i<<' '<<vec[i].fi<<' '<<n-i<<' '<<b<<'\n';
			dp[i] = i;
		}
	}
	for(int i=0;i<n;i++)
	{
		ll thres1 = (a+vec[i].fi-1)/vec[i].fi;
		int minr = i + thres1;
		if(minr>=n) continue;
		minr=dp[minr];
		if(minr<n)
		{
			cout<<"Yes\n";
			cout<<thres1<<' '<<n-minr<<'\n';
			for(int j=i;j<i+thres1;j++)
			{
				cout<<vec[j].se;
				if(j+1<i+thres1) cout<<' ';
			}
			cout<<'\n';
			for(int j=minr;j<=n-1;j++)
			{
				cout<<vec[j].se;
				if(j+1<n) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
	}
	swap(a,b);
	dp[n] = n;
	for(int i=n-1;i>=0;i--)
	{
		dp[i] = dp[i+1];
		if((n-i)*1LL*vec[i].fi>=b)
		{
			dp[i] = i;
		}
	}
	for(int i=0;i<n;i++)
	{
		ll thres1 = (a+vec[i].fi-1)/vec[i].fi;
		int minr = i + thres1;
		if(minr>=n) continue;
		minr=dp[minr];
		if(minr<n)
		{
			cout<<"Yes\n";
			cout<<n-minr<<' '<<thres1<<'\n';
			for(int j=minr;j<=n-1;j++)
			{
				cout<<vec[j].se;
				if(j+1<n) cout<<' ';
			}
			cout<<'\n';
			for(int j=i;j<i+thres1;j++)
			{
				cout<<vec[j].se;
				if(j+1<i+thres1) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<"No\n";
}