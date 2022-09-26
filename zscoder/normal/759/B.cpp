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

vector<ll> a;
ll dp[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	a.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	dp[0]=20;
	for(int i = 1; i < n; i++)
	{
		dp[i] = dp[i-1] + 20;
		//buy 90-minutes;
		int l = lower_bound(a.begin(),a.end(),a[i]-89)-a.begin();
		if(l==0) dp[i] = min(dp[i],50LL);
		else dp[i]=min(dp[i],dp[l-1]+50);
		l = lower_bound(a.begin(),a.end(),a[i]-1439)-a.begin();
		if(l==0) dp[i]=min(dp[i],120LL);
		else dp[i]=min(dp[i],dp[l-1]+120);
	}
	for(int i = 0; i < n; i++)
	{
		if(i==0) cout<<dp[i]<<'\n';
		else cout<<dp[i]-dp[i-1]<<'\n';
	}
}