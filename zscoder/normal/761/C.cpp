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

string a[51];

int type(char c)
{
	if(c>='0'&&c<='9') return 1;
	if(c>='a'&&c<='z') return 2;
	return 0;
}

int dp[51][3];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		for(int j = 0; j < 3; j++)
		{
			dp[i][j] = 100000;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			dp[i][type(a[i][j])] = min(dp[i][type(a[i][j])], min(j, m - j));
		}
	}
	int minop = 100000;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if(i!=j&&j!=k&&k!=i)
				{
					minop=min(minop,dp[i][0]+dp[j][1]+dp[k][2]);
				}
			}
		}
	}
	cout<<minop;
}