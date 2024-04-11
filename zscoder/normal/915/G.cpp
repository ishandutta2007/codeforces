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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int MOD=1e9+7;

int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
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
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int n;
int dp[2000011];
int powr[2000011];
vi divi[2000011];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k; cin>>n>>k;
	powr[0] = 0;
	for(int i=1;i<=k;i++)
	{
		powr[i]=modpow(i,n);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=i;j<=k;j+=i)
		{
			divi[j].pb(i);
		}
	}
	int ans=0;
	int cur=0;
	for(int i=1;i<=k;i++)
	{
		dp[i] = add(powr[i],MOD-powr[i-1]);
		for(auto z:divi[i])
		{
			if(z<i)
			{
				dp[i]=add(dp[i],MOD-dp[z]);
			}
		}
		cur=add(cur,dp[i]);
		ans=add(ans,cur^i);
	}
	cout<<ans<<'\n';
}