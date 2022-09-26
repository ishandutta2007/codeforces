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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[281][2100][92][2];
int s[4001];
int a[4001];
const int C = 140;
const int INF = 1000000000;
int n; 

int sum(int l, int r)
{
	if(l==0) return s[r];
	else return s[r]-s[l-1];
}

int solve(int diff, int i, int k, int l)
{
	int j = i - (diff - C);
	//cerr<<i<<' '<<j<<'\n';
	if(i+j>n) return -INF;
	if(i+j==n) return 0;
	
	if(dp[diff][i][k][l]!=INF) return dp[diff][i][k][l];
	
	int ans = 0;
	if(l == 0)
	{
		//[i, i + k - 1]
		if(i + k - 1 < n - j) ans = solve(diff+k, i+k, k, (l^1)) + sum(i, i + k - 1);
		if(i + k < n - j) ans = max(ans, solve(diff+k+1, i+k+1, k+1, (l^1)) + sum(i, i + k));
	}
	else
	{
		//[n - j - k, n - j - 1]
		int ans2 = -INF;
		if(n - j - k >= i) ans = solve(diff-k, i, k, (l^1)) - sum(n - j - k, n - j - 1);
		if(n - j - k - 1 >= i) ans2 = solve(diff-k-1, i, k+1, (l^1)) - sum(n - j - k - 1, n - j - 1);
		if(ans==-INF) ans = INF;
		if(ans2==-INF) ans2=INF;
		ans=min(ans,ans2);
		if(ans==INF) ans=0;
	}
	//cerr<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<ans<<'\n';
	dp[diff][i][k][l] = ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < 281; i++)
	{
		for(int j = 0; j < 2100; j++)
		{
			for(int k = 0; k < 92; k++)
			{
				for(int l = 0; l < 2; l++)
				{
					dp[i][j][k][l] = INF;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		s[i]=a[i];
		if(i>0) s[i]+=s[i-1];
	}
	cout<<solve(C, 0, 1, 0);
}