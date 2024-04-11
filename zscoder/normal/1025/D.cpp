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

int a[1111];
int dp[777][777][3];
int n; 
bool ok[777][777];
int solve(int l, int r, int mode)
{
	if(l>r) return 1;
	if(dp[l][r][mode]!=-1) return dp[l][r][mode];
	for(int i=l;i<=r;i++)
	{
		if((!solve(l,i-1,0))||(!solve(i+1,r,1))) continue;
		if(mode==1&&l>0&&!ok[l-1][i]) continue;
		if(mode==0&&r+1<n&&!ok[i][r+1]) continue;
		return (dp[l][r][mode]=1);
	}
	return (dp[l][r][mode]=0);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n; 
	//n=700;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		//a[i]=int(1e9);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(__gcd(a[i],a[j])>1) ok[i][j]=1;
		}
	}
	memset(dp,-1,sizeof(dp));
	int res=solve(0,n-1,2);
	if(res) cout<<"Yes\n";
	else cout<<"No\n";
}