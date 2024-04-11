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

ll solve(vi &v, int k)
{
	int n=v.size();
	sort(v.rbegin(),v.rend());
	ll ans =0;
	for(int i=0;i<min(k,int(v.size()));i++) ans+=v[i];
	return ans;
	vector<ll> dp(n+1,0);
	vector<ll> pref(n+1,0);
	for(int i=0;i<n;i++)
	{
		pref[i+1]=v[i]+pref[i];
	}
	dp[0]=0;
	multiset<ll> S;	
	for(int i=1;i<=n;i++)
	{
		if(i-k-1>=0)
		{
			S.erase(S.find(-pref[i-k-1]+(i-k-2>=0?dp[i-k-2]:0)));
		}
		S.insert(-pref[i-1]+(i-2>=0?dp[i-2]:0));
		dp[i]=dp[i-1];
		if(!S.empty()) dp[i]=max(dp[i],pref[i]+*(prev(S.end())));
		//i-k punya delete
		cerr<<i<<' '<<dp[i]<<'\n'; 
	}
	return dp[n];
	//dp[i] = max(a[j]+a[j+1]+...+a[i]+dp[j-2]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	set<int> brk;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	string s; cin>>s;
	vector<vi> vec;
	vec.pb(vi());
	for(int i=0;i+1<n;i++)
	{
		vec.back().pb(a[i]);
		if(s[i]!=s[i+1])
		{
			vec.pb(vi());
		}
	}
	ll ans=0;
	vec.back().pb(a[n-1]);
	for(auto &v:vec)
	{
		ans+=solve(v,k);
	}
	cout<<ans<<'\n';
}