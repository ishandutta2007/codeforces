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

int dp[1011111][5][3]; //j = expect how many person here, or 4 if no expectations
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	dp[0][4][0]=1;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<2;k++)
			{
				int v=dp[i][j][k];
				if(v==0) continue;
				if(j==1)
				{
					if(s[i]=='?'||s[i]=='*')
					{
						radd(dp[i+1][4][1],v);
					}
				}
				else if(j==0)
				{
					if(s[i]=='?'||s[i]=='0')
					{
						if(k==0)
						{
							radd(dp[i+1][0][0],v);
						}
					}
					if(s[i]=='?'||s[i]=='1')
					{
						radd(dp[i+1][1-k][0],v);
					}
					if(s[i]=='?'||s[i]=='2')
					{
						if(2-k>=0&&2-k<=1) radd(dp[i+1][2-k][0],v);
					}
				}
				else
				{
					if(s[i]=='?'||s[i]=='*')
					{
						radd(dp[i+1][4][1],v);
					}
					if(s[i]=='?'||s[i]=='0')
					{
						if(k==0)
						{
							radd(dp[i+1][0][0],v);
						}
					}
					if(s[i]=='?'||s[i]=='1')
					{
						radd(dp[i+1][1-k][0],v);
					}
					if(s[i]=='?'||s[i]=='2')
					{
						if(2-k>=0&&2-k<=1) radd(dp[i+1][2-k][0],v);
					}
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<2;j++) 
	{
		//cerr<<dp[n][0][j]<<' '<<dp[n][4][j]<<'\n';
		radd(ans,add(dp[n][0][j],dp[n][4][j]));
	}
	cout<<ans<<'\n';
}