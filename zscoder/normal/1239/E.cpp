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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef bitset<25*50001> b100;

b100 dp[52][26];
int ex[52][25*50001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int S=0;
	vi vec;
	for(int i=0;i<2*n;i++)
	{
		int x; cin>>x; vec.pb(x);S+=x;
	}
	sort(vec.rbegin(),vec.rend());
	dp[0][0].set(0,1);
	for(int i=1;i<=2*n;i++)
	{
		dp[i][0].set(0,1);
		for(int j=1;j<=min(i,n-1);j++)
		{
			dp[i][j]=dp[i-1][j]|(dp[i-1][j-1]<<vec[i-1]);
		}
	}
	for(int i=n-1;i+1<2*n;i++)
	{
		for(int j=0;j<25*50001;j++)
		{
			if(dp[i][n-1][j]) 
			{
				ex[i][j]=j;
			}
			else 
			{
				if(j>0) ex[i][j]=ex[i][j-1];
				else ex[i][j]=-1;
			}
		}
	}
	int lo=0; int hi=50000*50;
	int ans=int(1e9);
	vi res;
	while(lo<=hi)
	{
		int C=(lo+hi)>>1;
		int r=C-vec.back();
		bool pos=0;
		for(int i=n-1;i+1<2*n;i++)
		{
			//this is minimum
			//0 to i-1
			int L=S-C;
			int R=r-vec[i];
			L=max(L,0);R=min(R,25*50000);
			if(L>R) continue;
			//check dp[i][n-1]
			if(ex[i][R]>=L)
			{
				pos=1;
				if(C<ans)
				{
					ans=C;
					int bsum=ex[i][R];
					//cerr<<C<<' '<<bsum<<' '<<i<<' '<<vec[i]<<'\n';
					set<int> idL; idL.insert(i);
					int cc=n-1;
					for(int j=i;j>=1;j--)
					{
						if(j==1)
						{
							if(bsum==0) continue;
							idL.insert(j-1);
						}
						else
						{
							if(dp[j-1][cc][bsum])
							{
								continue;
							}
							else
							{
								idL.insert(j-1); bsum-=vec[j-1]; cc--;
							}
						}
					}
					set<int> idR;
					for(int j=0;j<2*n;j++)
					{
						if(idL.find(j)==idL.end())
						{
							idR.insert(-j);
						}
					}
					res.clear();
					for(auto x:idR)
					{
						res.pb(vec[-x]);
					}
					for(auto x:idL)
					{
						res.pb(vec[x]);
					}
				}
				break;
			}
		}
		if(pos)
		{
			hi=C-1;
		}
		else
		{
			lo=C+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<res[i]<<' ';
	}
	cout<<'\n';
	for(int i=n;i<2*n;i++)
	{
		cout<<res[i]<<' ';
	}
	cout<<'\n';
}