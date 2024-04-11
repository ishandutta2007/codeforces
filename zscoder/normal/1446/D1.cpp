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

int a[222222];
int freq[145][222222];
int dp[145][222222];
int mn[555555];
const int SHIFT = 222222;

int get(int num, int l, int r)
{
	if(l==0) return freq[num][r];
	else return freq[num][r]-freq[num][r-1];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; a[i]--;
		freq[a[i]][i]++;
	}
	for(int i=0;i<101;i++)
	{
		for(int j=1;j<n;j++)
		{
			freq[i][j]+=freq[i][j-1];
		}
	}
	int mxfreq=0;
	for(int i=0;i<101;i++)
	{
		mxfreq=max(mxfreq,freq[i][n-1]);
	}
	vi M;
	for(int i=0;i<101;i++)
	{
		if(freq[i][n-1]==mxfreq) M.pb(i);
	}
	if(M.size()>1){cout<<n<<'\n'; return 0;}
	int m = M[0];
	int ans=0;
	for(int i=0;i<101;i++)
	{
		if(i==m) continue;
		for(int j=0;j<=SHIFT*2;j++) mn[j]=-2;
		//map<int,int> mn;
		for(int j=0;j<n;j++)
		{
			dp[i][j]=freq[m][j]-freq[i][j];
		}
		mn[SHIFT]=-1;
		for(int j=0;j<n;j++)
		{
			if(mn[dp[i][j]+SHIFT]>=-1)
			{
				//if(j-mn[dp[i][j]]+1>ans) cerr<<"FROM: "<<mn[dp[i][j]]<<" TO "<<j<<" i = "<<i<<" DP = "<<dp[i][j]<<'\n';
				ans=max(ans,j-mn[dp[i][j]+SHIFT]);
			}
			else
			{
				mn[dp[i][j]+SHIFT]=j;
			}
		}
	}
	cout<<ans<<'\n';
	
}