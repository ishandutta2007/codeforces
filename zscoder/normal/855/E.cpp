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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll dp[11][65][1025][2];
ll sum[11][65][1025];

const ll INF = ll(2e18);
ll add(ll x, ll y)
{
	x+=y;
	if(x>INF) x=INF;
	return x;
}

ll mult(ll x, ll y)
{
	if(y==0||x==0) return 0;
	if(x>INF/y) return INF;
	else return (x*y);
}

int DIG[11];
ll powe[11][101];
ll solve(int b, ll x)
{
	if(x<=0) return 0;
	int curmask = 0;
	bool lead=1;
	ll ans = 0;
	for(int i=DIG[b]-1;i>=0;i--)
	{
		ll z = 0; ll coeff = powe[b][i];
		for(int j = 0; j < b; j++)
		{
			if(add(z,coeff)>x)
			{
				//choose j 
				if(lead&&j==0)
				{
					
				}
				else
				{
					curmask^=(1<<j);
					lead=0;
				}
				if(i==0)
				{
					if(curmask==0) ans++;
				}
				else
				{
					x -= z;
				}
				break;
			}
			else
			{
				if(j==0&&lead)
				{
					ans+=sum[b][i][curmask];
				}
				else
				{
					if(i==0)
					{
						if(curmask==(1<<j)) ans++;
					}
					else ans+=add(dp[b][i][curmask^(1<<j)][1],dp[b][i][curmask^(1<<j)][0]);
				}
			}
			z+=coeff;
		}
		//cerr<<i<<' '<<x<<' '<<curmask<<' '<<ans<<'\n';
	}
	ans--; //to remove the 0
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	for(int b=2;b<=10;b++)
	{
		powe[b][0] = 1;
		for(int j=1;j<=70;j++)
		{
			powe[b][j] = mult(powe[b][j-1], b);
		}
	}
	for(int b=2;b<=10;b++)
	{
		for(int i=0;i<b;i++)
		{
			dp[b][1][(1<<i)][(i!=0)] = 1;
		}
		int dig=0;
		ll cnt=1;
		while(cnt<=ll(1e18))
		{
			cnt=mult(cnt,b);
			dig++;
		}
		DIG[b] = dig;

		for(int i = 2; i <= dig; i++)
		{
			for(int k=0;k<(1<<b);k++)
			{
				for(int l=0;l<2;l++)
				{
					//leading zero
					if(l==0)
					{
						dp[b][i][k][l] = add(dp[b][i][k][l], add(dp[b][i-1][(k^1)][0], dp[b][i-1][(k^1)][1]));
					}
					else
					{
						for(int z=1;z<b;z++)
						{
							dp[b][i][k][l] = add(dp[b][i][k][l], add(dp[b][i-1][k^(1<<z)][0], dp[b][i-1][k^(1<<z)][1]));
						}
					}
				}
			}
		}
	}
	for(int b=2;b<=10;b++)
	{
		sum[b][0][0] = 1;
		for(int i=1;i<=DIG[b];i++)
		{
			for(int j=0;j<(1<<b);j++)
			{
				sum[b][i][j] = dp[b][i][j][1];
				//sum[b][i][j] = add(dp[b][i][j][1], dp[b][i][j][0]);
				sum[b][i][j] = add(sum[b][i][j], sum[b][i-1][j]);
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		int b;
		ll l,r;
		//b=10; l=ll(1e18)-10; r=ll(1e18);
		cin>>b>>l>>r;
		ll res1 = solve(b,r);
		ll res2 = solve(b,l-1);
		//cerr<<res2<<' '<<res1<<'\n';
		cout<<res1-res2<<'\n';
	}
}