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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222222];
pair<pair<short,short>,short> dp[222222][11][11];

pair<short,short> conv(short n)
{
	return mp(n/100,n%100);
}

short conv(pair<short,short> x)
{
	return x.fi*100+x.se;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		string s; cin>>s;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<11;j++)
			{
				for(int k=0;k<11;k++)
				{
					dp[i][j][k]=mp(mp(-1,-1),0);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			a[i]=s[i]-'0'+1;
		}
		dp[0][a[0]][0]=mp(mp(0,-1),0);
		dp[0][0][a[0]]=mp(mp(1,a[0]),0);
		for(int i=0;i+1<n;i++)
		{
			int d = a[i+1];
			for(int j=0;j<11;j++)
			{
				for(int k=0;k<11;k++)
				{
					if(dp[i][j][k].fi.fi!=-1)
					{
						//go to i+1
						//go 1
						int cur2=dp[i][j][k].fi.se;
						//cerr<<d<<' '<<i<<' '<<j<<' '<<k<<' '<<cur2<<'\n';
						if(d>=j)
						{
							if(cur2>=dp[i+1][d][k].fi.se)
							{
								if(cur2==-1||cur2>=d)
								{
									dp[i+1][d][k]=mp(mp(0,cur2),conv({j,k}));
								}
							}
						}
						if(d>=k)
						{
							int nwv = cur2;
							if(cur2<0) nwv=d;
							if(nwv>=dp[i+1][j][d].fi.se)
							{
								if(nwv>=j)
								{
									dp[i+1][j][d]=mp(mp(1,nwv),conv({j,k}));
								}
							}
						}
					}
				}
			}
		}
		ii pos=mp(-1,-1);
		for(int j=0;j<11;j++)
		{
			for(int k=0;k<11;k++)
			{
				//cerr<<j<<' '<<k<<' '<<dp[n-1][j][k].fi.fi<<' '<<dp[n-1][j][k].fi.se<<'\n';
				if(dp[n-1][j][k].fi.fi>=0&&(dp[n-1][j][k].fi.se==-1||dp[n-1][j][k].fi.se>=j))
				{
					pos=mp(j,k); break;
				}
			}
		}
		if(pos.fi==-1)
		{
			cout<<"-"<<'\n'; continue;
		}
		int x=pos.fi; int y=pos.se;
		vi ans(n,0);
		for(int i=n-1;i>=0;i--)
		{
			ans[i]=dp[i][x][y].fi.fi;
			int x2=dp[i][x][y].se/100;
			int y2=dp[i][x][y].se%100;
			x=x2;y=y2;
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]+1;
		}
		cout<<'\n';
	}
}