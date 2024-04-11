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

const int MOD=1e9+7;

int add(int a, int b)
{
	a+=b; while(a>=MOD) a-=MOD;
	return a;
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a); b>>=1;
	}
	return r;
}

map<int,int> dp;
vi divisors;

int solve(int x)
{
	if(x==1) return 0;
	if(dp.find(x)!=dp.end()) return dp[x];
	int ans = add(modpow(2,x-1),MOD-1);
	for(auto d:divisors)
	{
		if(x%d==0&&d<x)
		{
			ans=add(ans,MOD-solve(d));
		}
	}
	return (dp[x]=ans);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x, y; cin>>x>>y;
	for(int i=1;i*i<=y;i++)
	{
		if(y%i==0)
		{
			divisors.pb(i);
			if(i!=y/i) divisors.pb(y/i);
		}
	}
	if(y%x!=0){cout<<0<<'\n'; return 0;}
	int ans=solve(y/x)+(y/x==1?1:0);
	cout<<ans<<'\n';
}