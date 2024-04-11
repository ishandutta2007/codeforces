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

const int MOD=1e8;

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
int dp[111][111][11][2];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	dp[0][0][0][0]=1;
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			for(int k=0;k<=10;k++)
			{
				for(int l=0;l<2;l++)
				{
					int v=dp[i][j][k][l];
					if(v==0) continue;
					//use i+1
					{
						int newk=k+1;
						int newl=0;
						if(l==1) newk=1;
						if(newk<=k1) radd(dp[i+1][j][newk][newl],v);
					}
					{
						int newk=k+1;
						int newl=1;
						if(l==0) newk=1;
						if(newk<=k2) radd(dp[i][j+1][newk][newl],v);
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<2;j++)
		{
			radd(ans,dp[n1][n2][i][j]);
		}
	}
	cout<<ans<<'\n';
}