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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ld dp[61][5606];
ll f[61];
ll s[61];
ll p[61];
int rem[61];

pair<ld,ld> mult(pair<ld,ld> a, ld x)
{
	a.fi*=x; a.se*=x; return a;
}
pair<ld,ld> add(pair<ld,ld> a, ld x)
{
	a.se+=x; return a;
}

pair<ld,ld> add2(pair<ld,ld> a,pair<ld,ld> b)
{
	return mp(a.fi+b.fi,a.se+b.se);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n,r;
	cin>>n>>r;
	for(int i=0;i<n;i++)
	{
		cin>>f[i]>>s[i]>>p[i];
	}
	rem[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		rem[i]=f[i]+rem[i+1];
	}
	ld lo = 0; ld hi = ld(1e8);
	while(hi-lo>=ld(1e-11))
	{
		ld mid=(lo+hi)*ld(0.5);
		for(int i=0;i<=r;i++) dp[n][i] = 0;
		for(int i=r+1;i<=r+150;i++) 
		{
			//dp[n][i] = mp(1,0);
			dp[n][i] = mid;
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<=r+150;j++)
			{
				/*
				if(j+rem[i]<=r)
				{
					dp[i][j] = ld(p[i])*0.01*
					//dp[i][j] = add2(mult(add(dp[i+1][j+f[i]], f[i]),ld(p[i])*0.01), mult(add(dp[i+1][j+s[i]], s[i]),ld(100-p[i])*0.01));
				}
				else
				{
					dp[i][j] = mp(1,0);
				}
				*/
				dp[i][j] = mid;
				if(j>r) continue;
				dp[i][j] = min(dp[i][j], ld(p[i])*0.01*(dp[i+1][j+f[i]]+f[i]) + ld(100-p[i])*0.01*(dp[i+1][j+s[i]]+s[i]));
			}
		}	
		/*
		ld ans = dp[0][0].se/ld(1-dp[0][0].fi);
		bool pos=1;
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<=r+150;j++)
			{
				if(dp[i][j].fi*ans+dp[i][j].se>ans)
				{
					pos=0;
					cerr<<i<<' '<<j<<' '<<dp[i][j].fi*ans+dp[i][j].se<<' '<<ans<<'\n';
				}
			}
		}
		*/
		if(dp[0][0]<mid)
		{
			hi=mid;
		}
		else
		{
			lo=mid;
		}
	}
	cout<<fixed<<setprecision(15)<<lo<<'\n';
	//cout<<fixed<<setprecision(15)<<dp[0][r]<<'\n';
}