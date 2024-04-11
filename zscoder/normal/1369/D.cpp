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

vector<int> fact;
	vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
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
	
int dp[3333333][2];

void solve()
{
	int n; cin>>n;
	if(n%3==2) cout<<mult(dp[n][0],4)<<'\n';
	else cout<<mult(dp[n][1],4)<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=3;i<=2020000;i++)
	{
		//dp[i][1]=add(1,add(dp[i-2][0],add(dp[i-2][0],dp[i-1][0])));
		//dp[i][0]=add(mult(2,dp[i-2][1]),dp[i-1][1]);
		dp[i][1]=add(add(1,mult(dp[i-2][0],2)),dp[i-1][0]);
		dp[i][0]=dp[i][1];
		if(i%3==0)
		{
			dp[i][0]=add(dp[i][1],MOD-1);
		}
		else if(i%3==2)
		{
			dp[i][0]=add(dp[i][1],1);
		}
		/*
		dp[i][0]=2*max(dp[i-2][1],dp[i-2][0])+max(dp[i-1][1],dp[i-1][0]);
		if(i<=20)
		{
			cerr<<i<<' '<<dp[i][1]<<' '<<dp[i][0]<<'\n';
		}
		*/
	}
	int t; cin>>t;
	while(t--) solve();
}