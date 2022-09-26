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

int MOD;

int add(int a, int b)
{
	a+=b;
	a%=MOD;
	return a;
}

void radd(int &a, int b)
{
	a=add(a,b);
}

int dp[1111][111][2][2];
int pw[1111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	cin>>MOD;
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*10)%m;
	dp[0][0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<2;k++)
			{
				for(int l=0;l<2;l++)
				{
					int v=dp[i][j][k][l];
					if(v==0) continue;
					for(int d=0;d<10;d++)
					{
						if(i==n-1&&d==0) continue;
						int digval = (pw[i]*d)%m;
						int newk = k;
						if(d!=0) newk=1;
						int newl=l;
						if(newk&&((digval+j)%m==0)) newl=1;
						//cerr<<i+1<<' '<<(digval+j)%m<<' '<<newk<<' '<<newl<<' '<<v<<'\n';
						radd(dp[i+1][(digval+j)%m][newk][newl],v);
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<m;i++)
	{
		radd(ans,dp[n][i][1][1]);
		//radd(ans,MOD-dp[n-1][i][1][1]);
	}
	if(ans<0) ans+=MOD;
	cout<<ans<<'\n';
}