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
typedef __float128 ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll p[111][111];
ll player[158];
ld curp[158];
ll P[158];
ld prob[158][158];
int dep[158];
ld dp[158][158];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			cin>>p[i][j];
		}
	}
	ld ans = 0;
	for(int i=(1<<n);i<(1<<(n+1));i++)
	{
		dep[i]=0;
		prob[i][i-(1<<n)]=1;
		//for(int j=0;j<(1<<n);j++) dp[i][j]=0;
	}
	for(int i=(1<<n)-1;i>=1;i--) 
	{
		dep[i]=dep[(i<<1)]+1;
		for(int j=0;j<(1<<n);j++)
		{
			for(int k=0;k<(1<<n);k++)
			{
				prob[i][j] += prob[(i<<1)][j]*prob[(i<<1)+1][k]*ld(p[j][k])*ld(0.01);
				prob[i][j] += prob[(i<<1)+1][j]*prob[(i<<1)][k]*ld(p[j][k])*ld(0.01);
			}
			//cerr<<i<<' '<<j<<' '<<(double)prob[i][j]<<'\n';
		}
	}
	for(int i=(1<<n)-1;i>=1;i--)
	{
		int l=(i<<1); int r = (l^1);
		/*
		int l2 = player[l]; int r2=player[r];
		//cerr<<l<<' '<<r<<' '<<l2<<' '<<r2<<' '<<p[l2][r2]*P[l]<<' '<<p[r2][l2]*P[r]<<'\n';
		if(p[l2][r2]*P[l]>=p[r2][l2]*P[r])
		{
			player[i]=l2;
			curp[i] = p[l2][r2]*ld(0.01)*curp[l];
			P[i] = p[l2][r2]*P[l];
		}
		else
		{
			player[i]=r2;
			curp[i] = p[r2][l2]*ld(0.01)*curp[r];
			P[i] = p[r2][l2]*P[r];
		}
		dep[i]=dep[l]+1;
		ld cost = ld((1<<(dep[i]-1)));
		//cerr<<i<<' '<<double(cost)<<' '<<double(curp[i])<<'\n';
		cost*=curp[i];
		ans+=cost;
		*/
		ld cost = ld((1<<(dep[i]-1)));
		for(int j=0;j<(1<<n);j++)
		{
			ld pro = prob[i][j];
			ld ext = cost*pro;
			ld res=0;
			for(int k=0;k<(1<<n);k++)
			{
				for(int zl=0;zl<(1<<n);zl++)
				{
					if(k==j||zl==j)
					{
						if(dp[l][k]+dp[r][zl]>res)
						{
							res=dp[l][k]+dp[r][zl];
						}
					}
				}
			}
			dp[i][j]=res+ext;
			//cerr<<"DP : "<<i<<' '<<j<<' '<<double(dp[i][j])<<'\n';
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		if(dp[1][i]>ans) ans=dp[1][i];
	}
	/*
	for(int i=(1<<n);i<(1<<(n+1));i++)
	{
		player[i]=i-(1<<n);
		curp[i] = 1;
		P[i] = 1;
		dep[i]=0;
	}
	for(int i=(1<<n)-1;i>=1;i--)
	{
		int l=(i<<1); int r = (l^1);
		int l2 = player[l]; int r2=player[r];
		//cerr<<l<<' '<<r<<' '<<l2<<' '<<r2<<' '<<p[l2][r2]*P[l]<<' '<<p[r2][l2]*P[r]<<'\n';
		if(p[l2][r2]*P[l]>=p[r2][l2]*P[r])
		{
			player[i]=l2;
			curp[i] = p[l2][r2]*ld(0.01)*curp[l];
			P[i] = p[l2][r2]*P[l];
		}
		else
		{
			player[i]=r2;
			curp[i] = p[r2][l2]*ld(0.01)*curp[r];
			P[i] = p[r2][l2]*P[r];
		}
		dep[i]=dep[l]+1;
		ld cost = ld((1<<(dep[i]-1)));
		//cerr<<i<<' '<<double(cost)<<' '<<double(curp[i])<<'\n';
		cost*=curp[i];
		ans+=cost;
	}
	*/
	
	
	long double tmp = ans;
	cout<<fixed<<setprecision(20)<<tmp<<'\n';
}