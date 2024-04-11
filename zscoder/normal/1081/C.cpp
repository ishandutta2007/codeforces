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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
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
	
int dp[2222][2222];
int S[2222][2222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k; cin>>n>>m>>k;
	k++;
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=m;
		S[i][1]=m;
		if(i>1) S[i][1]=add(S[i][1],S[i-1][1]);
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			dp[i][j]=mult(S[i-1][j-1],m-1);
			S[i][j]=dp[i][j];
		}
		for(int j=2;j<=k;j++)
		{
			S[i][j]=add(S[i][j],S[i-1][j]);
		}
	}
	cout<<dp[n][k]<<'\n';
}